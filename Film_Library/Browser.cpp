#include "Browser.h"
#include "graphics.h"
#include "defines.h"
#include <list>

// Συνάρτηση ενημέρωσης (update) που επιλέγει τη σωστή λειτουργία με βάση το status
void Browser::update()
{
	if (status == LOAD)
	{
		updateLoad(); // Αν το status είναι LOAD, καλούμε την updateLoad()
	}
	if (status == START)
	{
		updateStart(); // Αν το status είναι START, καλούμε την updateStart()
	}
	if (status == MOVIES)
	{
		updateMovies(); // Αν το status είναι MOVIES, καλούμε την updateMovies()
	}
}


// Συνάρτηση ενημέρωσης για την κατάσταση LOAD
void Browser::updateLoad()
{
	mesa = true;
	status = START; // Μετά την ολοκλήρωση του LOAD, αλλάζουμε το status σε START
}

// Συνάρτηση ενημέρωσης για την κατάσταση START
void Browser::updateStart()
{
	if (mesa)
	{
		Library* lib = new Library(); // Δημιουργία νέας βιβλιοθήκης

		lib->init(); // Αρχικοποίηση της βιβλιοθήκης με ταινίες
		films = lib->getFilms(); // Λήψη των ταινιών από τη βιβλιοθήκη

		int i = 1.0f, j = 1.0f;

		// Δημιουργία κουμπιών για κάθε είδος ταινίας
		for (auto g : lib->genreNames())
		{
			FilterButton* genreButton = new FilterButton(*this);

			genreButton->setButtonName(g);

			genreButton->setPosX((29.0f + j));
			genreButton->setPosY((-0.6f + i + 0.5f));

			if (i == 6)
			{
				j = 4.0f;
				i = 0;
			}
			i++;
			genreButtons.push_back(genreButton); // Προσθήκη του κουμπιού στη λίστα
		}

		int k = 1.0f;
		// Δημιουργία κουμπιών για κάθε έτος κυκλοφορίας ταινιών
		for (int y : lib->getYears())
		{
			FilterButton* yearButton = new FilterButton(*this);

			yearButton->setButtonName(std::to_string(y));

			yearButton->setPosX(2.0f);
			yearButton->setPosY(2.0f + k);
			genreButtons.push_back(yearButton);
			k++;
		}
		// Ορισμός θέσης και ονόματος για το κουμπί Clear Filter
		clear->setPosX(31.0f);
		clear->setPosY(10.0f);
		clear->setButtonName("Clear Filter");

		// Δημιουργία checkboxes για κάθε ταινία
		for (auto f : films)
		{
			Checkbox* che = new Checkbox(*this);

			che->setPosX(f->getPosX());
			che->setPosY(f->getPosY());

			che->setFilm(f); // Σύνδεση του checkbox με την ταινία

			check.push_back(che); // Προσθήκη του checkbox στη λίστα
		}
		mesa = false; // Αποφυγή πολλαπλών δημιουργιών αντικειμένων
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);

	// Έλεγχος για hover πάνω σε checkbox και αλλαγή κατάστασης όταν πατηθεί
	for (auto che : check)
	{
		che->setHighlight(che->contains(mx, my)); 

		if (che->contains(mx, my) && ms.button_left_pressed)
		{
			film = che->getFilm(); // Αποθήκευση της ταινίας που αντιστοιχεί στο checkbox

			graphics::Brush br;
			br.texture = std::string(ASSET_PATH) + "fbutton.wav";
			graphics::playSound(br.texture, 0.3f, false);
			status = MOVIES; // Αλλαγή status για να περάσουμε στην κατάσταση MOVIES
		}
	}

	// Έλεγχος για πατήμα πάνω στα κουμπιά φίλτρων για είδος και έτος ταινίας
	for (FilterButton* fb : genreButtons)
	{
		if (fb->contains(mx, my) && ms.button_left_pressed)
		{
			graphics::Brush br;
			br.texture = std::string(ASSET_PATH) + "fbutton.wav";
			graphics::playSound(br.texture, 0.3f, false);

			check = lib->filter(fb->getButtonName(), check); // Εφαρμογή φίλτρου

			int p = 0;
			// Επανατοποθέτηση των checkboxes μετά την εφαρμογή του φίλτρου
			for (auto che : check) 
			{
				if (p < 6)
				{
					che->setPosX((p + 1.5f) * 4.0f);
					che->setPosY(3.5f);

					che->getFilm()->setPosX((p + 1.5f) * 4.0f);
					che->getFilm()->setPosY(3.5f);
				}
				else if (p < 12)
				{
					che->setPosX((p - 4.5f) * 4.0f);
					che->setPosY(10.5f);

					che->getFilm()->setPosX((p - 4.5f) * 4.0f);
					che->getFilm()->setPosY(10.5f);
				}
				else
				{
					che->setPosX((p - 10.5f) * 4.0f);
					che->setPosY(17.5f);

					che->getFilm()->setPosX((p - 10.5f) * 4.0f);
					che->getFilm()->setPosY(17.5f);
				}
				p++;

			}

		}
	}

	// Ρύθμιση θέσεων για τα κουμπιά up και down
	upButton->setPosX(31.0f);
	upButton->setPosY(13.0f);
	upButton->setButtonName("up");

	downButton->setPosX(31.0f);
	downButton->setPosY(15.0f);
	downButton->setButtonName("down");

	// Αν υπάρχουν αντικείμενα στη λίστα
	if (!check.empty()) {
		// Πάνω κουμπί: μετακίνηση προς τα πάνω
		if (upButton->contains(mx, my) && ms.button_left_pressed && check.size() > 12) {
			// Έλεγχος αν το τελευταίο αντικείμενο μπορεί να μετακινηθεί
			auto lastChe = check.back();
			if (lastChe->getPosY() + 2 <= 17.5f) {
				// Μετακίνηση όλων των αντικειμένων
				for (auto che : check) {
					che->setPosY(che->getPosY() + 2);
					che->getFilm()->setPosY(che->getPosY());
				}
			}
			// Απενεργοποίηση πάνω κουμπιού αν φτάσαμε στο κάτω όριο
			click1 = (check.back()->getPosY() < 17.5f);
			click2 = true;
		}

		// Κάτω κουμπί: μετακίνηση προς τα κάτω
		if (downButton->contains(mx, my) && ms.button_left_pressed && check.size() > 12) {
			// Έλεγχος αν το πρώτο αντικείμενο μπορεί να μετακινηθεί
			auto firstChe = check.front();
			if (firstChe->getPosY() - 2 >= -0.5f) {
				// Μετακίνηση όλων των αντικειμένων
				for (auto che : check) {
					che->setPosY(che->getPosY() - 2);
					che->getFilm()->setPosY(che->getPosY());
				}
			}
			// Απενεργοποίηση κάτω κουμπιού αν φτάσαμε στο πάνω όριο
			click2 = (check.front()->getPosY() > -0.5f);
			click1 = true;
		}
	}

	// Έλεγχος για το κουμπί Clear Filter
	if (clear->contains(mx, my) && ms.button_left_down)
	{

		films.clear();

		check.clear();

		genreButtons.clear();

		status = LOAD;

	}
}

// Συνάρτηση για την εμφάνιση των στοιχείων ταινίας
void Browser::updateMovies() 
{
	for (auto f : films)
	{
		if (f != film)
		{
			f = nullptr;
			delete f; // Διαγραφή ταινιών που δεν επιλέχθηκαν
		}
	}


	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);

	backButton = new Button(*this);
	backButton->setPosX(1.0);
	backButton->setPosY(1.0);
	if (backButton->contains(mx, my) && ms.button_left_pressed) {
		status = START; // Επιστροφή στην κατάσταση START
	}
}

// Συνάρτηση για την εμφάνιση του βασικού φόντου της εφαρμογής
void Browser::draw()
{
	graphics::Brush br;

	br.outline_opacity = 0.0f;
	// Ορισμός εικόνας φόντου
	br.texture = std::string(ASSET_PATH) + "background.png";
	// Σχεδιάζουμε το φόντο στο κέντρο της οθόνης
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	// Ανάλογα με το status, καλούμε την αντίστοιχη συνάρτηση εμφάνισης
	if (status == LOAD) // Διαχείριση στην κατάσταση LOAD
	{
		drawLoad();
	}
	if (status == START) // Διαχείριση στην κατάσταση START
	{
		drawStart();
	}
	if (status == MOVIES) // Διαχείριση στην κατάσταση MOVIES
	{
		drawMovies();
	}
}

// Συνάρτηση εμφάνισης για την κατάσταση LOAD
void Browser::drawLoad()
{
	// Δεν υπάρχει τίποτα να εμφανίσουμε για την κατάσταση LOAD προς το παρόν.
}

// Συνάρτηση εμφάνισης για την κατάσταση START
void Browser::drawStart()
{
	// Σχεδιάζουμε όλα τα checkboxes και τις ταινίες τους
	for (auto che : check)
	{
		che->draw();
		che->getFilm()->draw();
	}
	// Σχεδιάζουμε τα κουμπιά up και down αν υπάρχουν
	if (upButton)
	{
		graphics::Brush br;
		br.texture = "assets\\up.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(upButton->getPosX(), upButton->getPosY(), 1.1f, 1.1f, br);
	}

	if (downButton)
	{
		graphics::Brush br;
		br.texture = "assets\\down.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(downButton->getPosX(), downButton->getPosY(), 1.1f, 1.1f, br);
	}

	// Σχεδιάζουμε τα κουμπιά φίλτρων για τα είδη ταινιών
	for (Button* bg : genreButtons)
	{
		bg->draw();
		graphics::Brush br;
		graphics::drawText(bg->getPosX() - 1.2f, bg->getPosY() + 0.1f, 0.5f, bg->getButtonName(), br);
	}

	// Σχεδιάζουμε το κουμπί "Clear Filter"
	if (clear)
	{
		clear->draw();
		graphics::Brush br;
		graphics::drawText(clear->getPosX() - 1.2f, clear->getPosY() + 0.1f, 0.5f, clear->getButtonName(), br);
	}
}

// Συνάρτηση εμφάνισης για την κατάσταση MOVIES
void Browser::drawMovies()
{
	// Σχεδιάζουμε το όνομα της ταινίας στην οθόνη
	graphics::Brush br;
	graphics::drawText(8.0f, 2.0f, 1.0f, film->getFilmName(), br);

	// Εμφάνιση της εικόνας της ταινίας
	std::string photo = film->getFilmName() + std::string(".png");
	br.texture = std::string(ASSET_PATH) + photo;
	br.outline_opacity = 0.0f;
	graphics::drawRect(4.0f, 8.5f, 7.0f, 12.0f, br);

	// Εμφάνιση των στοιχείων της ταινίας (έτος, διάρκεια, σκηνοθέτες, καστ, είδος)
	std::string year = std::to_string(film->getYear());
	graphics::drawText(8.0f, 5.0f, 0.7f, std::string("Year:  ") + year, br);

	std::string Duration = std::to_string(film->getDuration());
	graphics::drawText(8.0f, 6.0f, 0.7f, std::string("Duration:  ") + Duration + std::string("  minutes."), br);

	std::string Directors;
	for (auto s : film->getDirectors())
	{
		Directors += s + "   ";
	}
	graphics::drawText(8.0f, 7.0f, 0.7f, std::string("Directors:  ") + Directors, br);

	std::string Cast;
	for (auto s : film->getCast())
	{
		Cast += s + "   ";
	}
	graphics::drawText(8.0f, 8.0f, 0.7f, std::string("Cast:  ") + Cast, br);

	std::string Genre;
	for (auto s : film->getGenre())
	{
		Genre += s + "   ";
	}
	graphics::drawText(8.0f, 9.0f, 0.7f, std::string("Genre:  ") + Genre, br);

	// Εμφάνιση περιγραφής της ταινίας
	graphics::drawText(2.0f, 15.5f, 0.7f, "Description: ", br);

	graphics::drawText(1.0f, 16.5f, 0.5f, film->getSummary(), br);
	// Σχεδιάζουμε το βελάκι επιστροφής
	br.texture = "assets\\arrow.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(1.0f, 1.0f, 1.1f, 1.1f, br);

}

// Συνάρτηση για την αρχικοποίηση του font (γραμματοσειράς)
void Browser::init() //font gia ta grammata
{
	graphics::setFont(std::string(ASSET_PATH) + "Kelano Remora.otf");
}


// Κατασκευαστής της κλάσης Browser
Browser::Browser()
{
}


// Καταστροφέας της κλάσης Browser
Browser::~Browser()
{
	// Διαγράφουμε πρώτα τα αντικείμενα για να αποφύγουμε διαρροές μνήμης
	delete lib;
	delete film;
	delete backButton;
	delete upButton;
	delete clear;

	// Θέτουμε σε nullptr για να αποφύγουμε dangling pointers
	lib = nullptr;
	film = nullptr;
	backButton = nullptr;
	upButton = nullptr;
	clear = nullptr;

	// Διαγραφή όλων των στοιχείων στις λίστες
	for (auto che : check)
	{
		delete che; // Διαγραφή του αντικειμένου
	}
	check.clear(); // Αδειάζουμε τη λίστα για να μην περιέχει dangling pointers

	for (auto button : genreButtons)
	{
		delete button;
	}
	genreButtons.clear();
}