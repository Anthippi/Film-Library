#include "Browser.h"
#include "graphics.h"
#include "defines.h"
#include <list>

// ��������� ���������� (update) ��� �������� �� ����� ���������� �� ���� �� status
void Browser::update()
{
	if (status == LOAD)
	{
		updateLoad(); // �� �� status ����� LOAD, ������� ��� updateLoad()
	}
	if (status == START)
	{
		updateStart(); // �� �� status ����� START, ������� ��� updateStart()
	}
	if (status == MOVIES)
	{
		updateMovies(); // �� �� status ����� MOVIES, ������� ��� updateMovies()
	}
}


// ��������� ���������� ��� ��� ��������� LOAD
void Browser::updateLoad()
{
	mesa = true;
	status = START; // ���� ��� ���������� ��� LOAD, ��������� �� status �� START
}

// ��������� ���������� ��� ��� ��������� START
void Browser::updateStart()
{
	if (mesa)
	{
		Library* lib = new Library(); // ���������� ���� �����������

		lib->init(); // ������������ ��� ����������� �� �������
		films = lib->getFilms(); // ���� ��� ������� ��� �� ����������

		int i = 1.0f, j = 1.0f;

		// ���������� �������� ��� ���� ����� �������
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
			genreButtons.push_back(genreButton); // �������� ��� �������� ��� �����
		}

		int k = 1.0f;
		// ���������� �������� ��� ���� ���� ����������� �������
		for (int y : lib->getYears())
		{
			FilterButton* yearButton = new FilterButton(*this);

			yearButton->setButtonName(std::to_string(y));

			yearButton->setPosX(2.0f);
			yearButton->setPosY(2.0f + k);
			genreButtons.push_back(yearButton);
			k++;
		}
		// ������� ����� ��� �������� ��� �� ������ Clear Filter
		clear->setPosX(31.0f);
		clear->setPosY(10.0f);
		clear->setButtonName("Clear Filter");

		// ���������� checkboxes ��� ���� ������
		for (auto f : films)
		{
			Checkbox* che = new Checkbox(*this);

			che->setPosX(f->getPosX());
			che->setPosY(f->getPosY());

			che->setFilm(f); // ������� ��� checkbox �� ��� ������

			check.push_back(che); // �������� ��� checkbox ��� �����
		}
		mesa = false; // ������� ��������� ����������� ������������
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
	float my = graphics::windowToCanvasY((float)ms.cur_pos_y);

	// ������� ��� hover ���� �� checkbox ��� ������ ���������� ���� �������
	for (auto che : check)
	{
		che->setHighlight(che->contains(mx, my)); 

		if (che->contains(mx, my) && ms.button_left_pressed)
		{
			film = che->getFilm(); // ���������� ��� ������� ��� ����������� ��� checkbox

			graphics::Brush br;
			br.texture = std::string(ASSET_PATH) + "fbutton.wav";
			graphics::playSound(br.texture, 0.3f, false);
			status = MOVIES; // ������ status ��� �� ��������� ���� ��������� MOVIES
		}
	}

	// ������� ��� ������ ���� ��� ������� ������� ��� ����� ��� ���� �������
	for (FilterButton* fb : genreButtons)
	{
		if (fb->contains(mx, my) && ms.button_left_pressed)
		{
			graphics::Brush br;
			br.texture = std::string(ASSET_PATH) + "fbutton.wav";
			graphics::playSound(br.texture, 0.3f, false);

			check = lib->filter(fb->getButtonName(), check); // �������� �������

			int p = 0;
			// ��������������� ��� checkboxes ���� ��� �������� ��� �������
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

	// ������� ������ ��� �� ������� up ��� down
	upButton->setPosX(31.0f);
	upButton->setPosY(13.0f);
	upButton->setButtonName("up");

	downButton->setPosX(31.0f);
	downButton->setPosY(15.0f);
	downButton->setButtonName("down");

	// �� �������� ����������� ��� �����
	if (!check.empty()) {
		// ���� ������: ���������� ���� �� ����
		if (upButton->contains(mx, my) && ms.button_left_pressed && check.size() > 12) {
			// ������� �� �� ��������� ����������� ������ �� �����������
			auto lastChe = check.back();
			if (lastChe->getPosY() + 2 <= 17.5f) {
				// ���������� ���� ��� ������������
				for (auto che : check) {
					che->setPosY(che->getPosY() + 2);
					che->getFilm()->setPosY(che->getPosY());
				}
			}
			// �������������� ���� �������� �� ������� ��� ���� ����
			click1 = (check.back()->getPosY() < 17.5f);
			click2 = true;
		}

		// ���� ������: ���������� ���� �� ����
		if (downButton->contains(mx, my) && ms.button_left_pressed && check.size() > 12) {
			// ������� �� �� ����� ����������� ������ �� �����������
			auto firstChe = check.front();
			if (firstChe->getPosY() - 2 >= -0.5f) {
				// ���������� ���� ��� ������������
				for (auto che : check) {
					che->setPosY(che->getPosY() - 2);
					che->getFilm()->setPosY(che->getPosY());
				}
			}
			// �������������� ���� �������� �� ������� ��� ���� ����
			click2 = (check.front()->getPosY() > -0.5f);
			click1 = true;
		}
	}

	// ������� ��� �� ������ Clear Filter
	if (clear->contains(mx, my) && ms.button_left_down)
	{

		films.clear();

		check.clear();

		genreButtons.clear();

		status = LOAD;

	}
}

// ��������� ��� ��� �������� ��� ��������� �������
void Browser::updateMovies() 
{
	for (auto f : films)
	{
		if (f != film)
		{
			f = nullptr;
			delete f; // �������� ������� ��� ��� �����������
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
		status = START; // ��������� ���� ��������� START
	}
}

// ��������� ��� ��� �������� ��� ������� ������ ��� ���������
void Browser::draw()
{
	graphics::Brush br;

	br.outline_opacity = 0.0f;
	// ������� ������� ������
	br.texture = std::string(ASSET_PATH) + "background.png";
	// ����������� �� ����� ��� ������ ��� ������
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	// ������� �� �� status, ������� ��� ���������� ��������� ���������
	if (status == LOAD) // ���������� ���� ��������� LOAD
	{
		drawLoad();
	}
	if (status == START) // ���������� ���� ��������� START
	{
		drawStart();
	}
	if (status == MOVIES) // ���������� ���� ��������� MOVIES
	{
		drawMovies();
	}
}

// ��������� ��������� ��� ��� ��������� LOAD
void Browser::drawLoad()
{
	// ��� ������� ������ �� ����������� ��� ��� ��������� LOAD ���� �� �����.
}

// ��������� ��������� ��� ��� ��������� START
void Browser::drawStart()
{
	// ����������� ��� �� checkboxes ��� ��� ������� ����
	for (auto che : check)
	{
		che->draw();
		che->getFilm()->draw();
	}
	// ����������� �� ������� up ��� down �� ��������
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

	// ����������� �� ������� ������� ��� �� ���� �������
	for (Button* bg : genreButtons)
	{
		bg->draw();
		graphics::Brush br;
		graphics::drawText(bg->getPosX() - 1.2f, bg->getPosY() + 0.1f, 0.5f, bg->getButtonName(), br);
	}

	// ����������� �� ������ "Clear Filter"
	if (clear)
	{
		clear->draw();
		graphics::Brush br;
		graphics::drawText(clear->getPosX() - 1.2f, clear->getPosY() + 0.1f, 0.5f, clear->getButtonName(), br);
	}
}

// ��������� ��������� ��� ��� ��������� MOVIES
void Browser::drawMovies()
{
	// ����������� �� ����� ��� ������� ���� �����
	graphics::Brush br;
	graphics::drawText(8.0f, 2.0f, 1.0f, film->getFilmName(), br);

	// �������� ��� ������� ��� �������
	std::string photo = film->getFilmName() + std::string(".png");
	br.texture = std::string(ASSET_PATH) + photo;
	br.outline_opacity = 0.0f;
	graphics::drawRect(4.0f, 8.5f, 7.0f, 12.0f, br);

	// �������� ��� ��������� ��� ������� (����, ��������, ����������, ����, �����)
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

	// �������� ���������� ��� �������
	graphics::drawText(2.0f, 15.5f, 0.7f, "Description: ", br);

	graphics::drawText(1.0f, 16.5f, 0.5f, film->getSummary(), br);
	// ����������� �� ������ ����������
	br.texture = "assets\\arrow.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(1.0f, 1.0f, 1.1f, 1.1f, br);

}

// ��������� ��� ��� ������������ ��� font (��������������)
void Browser::init() //font gia ta grammata
{
	graphics::setFont(std::string(ASSET_PATH) + "Kelano Remora.otf");
}


// ������������� ��� ������ Browser
Browser::Browser()
{
}


// ������������ ��� ������ Browser
Browser::~Browser()
{
	// ����������� ����� �� ����������� ��� �� ���������� �������� ������
	delete lib;
	delete film;
	delete backButton;
	delete upButton;
	delete clear;

	// ������� �� nullptr ��� �� ���������� dangling pointers
	lib = nullptr;
	film = nullptr;
	backButton = nullptr;
	upButton = nullptr;
	clear = nullptr;

	// �������� ���� ��� ��������� ���� ������
	for (auto che : check)
	{
		delete che; // �������� ��� ������������
	}
	check.clear(); // ���������� �� ����� ��� �� ��� �������� dangling pointers

	for (auto button : genreButtons)
	{
		delete button;
	}
	genreButtons.clear();
}