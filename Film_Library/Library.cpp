#include "Library.h"
#include "graphics.h"
#include <set>
#include <algorithm>

// Επιστρέφει όλες τις ταινίες
std::list<Film*> Library::getFilms()
{
	return films;
}

// Αρχικοποίηση των ταινιών
void Library::init()
{
	struct Movie {
		std::string title;
		std::list<std::string> directors;
		std::list<std::string> cast;
		std::list<std::string> genre;
		int year;
		int duration;
		std::string summary;
	};

	Movie movies[18] = // Λίστα ταινιών
	{
		{
			"Interstellar",
			{"Christopher Nolan"},
			{"Matthew  McConaughey", "Anne  Hathaway", "Jessica  Chastain"},
			{{"Adventure"}, {"Drama"}, {"Sci-Fi"}},
			2014,
			179,
			"A team of explorers travel through a wormhole in space in an attempt to ensure humanity's survival."
		},
		{
			"The Shawshank Redemption",
			{"Frank Darabont"},
			{"Morgan Freeman", "Tim Robbins", "Clancy Brown", "Mark Rolston"},
			{"Drama"},
			1994,
			142,
			"The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son."
		},
		{
			"The Godfather",
			{"Francis  Ford  Coppola"},
			{"Marlon  Brando", "Al  Pacino", "James  Caan"},
			{{"Crime"}, {"Drama"}},
			1972,
			175,
			"Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency"
		},
		{
			"WALL-E",
			{"Andrew Stanton"},
			{ "Ben Burtt", "Elissa Knight", "Jeff Garlin" },
			{ {"Animation"}, {"Adventure"} },
			2008,
			97,
			"In the distant future, a small waste-collecting robot inadvertently embarks on a space journey that will ultimately decide the fate of mankind."
		},
		{
			"A Star Is Born",
			{"Bradley Cooper"},
			{"Lady Gaga", "Bradley Cooper", "Sam Elliott"},
			{{"Drama"}, {"Romance"}},
			2018,
			136,
			"A musician helps a youn{g singer find fame as age and alcoholism send his own career into a downward spiral."
		},
		{
			"PUSS IN BOOTS  THE LAST WISH",
			{"Joel Crawford"},
			{"Antonio Banderas", "Salma Hayek"},
			{{"Animation"}, {"Adventure"}, {"Comedy"}},
			2022,
			103,
			"Puss sets out on an epic journey to find the mythical Last Wish and restore his nine lives."
		},
		{
			"BLACK PANTHER WAKANDA FOREVER",
			{"Ryan Coogler"},
			{"Letitia Wright", "Lupita Nyong'o", "Danai Gurira"},
			{{"Action"}, {"Adventure"}, {"Drama"} },
			2022,
			161,
			"The people of Wakanda fight to protect their home from intervening world powers as they mourn the death of King T'Challa."
		},
		{
			"AVENGERS INFINITY WAR",
			{"Anthiny Russo" , "Joe Russo" },
			{ "Robert Downey Jr. " , "Chris Hemsworth" , "Mark Ruffalo" },
			{{"Action"}, {"Adventure"}, {"Sci-Fi"}},
			2018,
			149,
			"The Avengers and their allies must be willing to sacrifice all in an attempt to defeat the powerful Thanos before his blitz."
		},
		{
			"12 ANGRY MEN",
			{"Sidney Lumen"},
			{"Henry Fonda" , "Lee J. Cobb" , "Martin Balsam"},
			{{"Crime"}, {"Drama" }},
			1957,
			96,
			"The jury in murder trial is frustrated by a single member whose skeptical caution forces them to consider the evidence before jumping to a verdict."
		},
		{
			"THE WHALE",
			{"Darren Aronofsky"},
			{"Hong  Chau" , "Brendan Fraser" , "Sadie Sink" , "Ty  Simpkins"},
			{ "Drama" },
			2022,
			117,
			"A reclusive, morbidly obese English teacher attempts to reconnect with his estranged teenage daughter."
		},
		{
			"TOC TOC",
			{"Vicente Villanueva"},
			{"Paco Leon" , "Alexandra Jimenez " , "Rossy de Palma"},
			{"Comedy"},
			2017,
			90,
			"The adventures and misadventures of a group of patients with OCD appointed at the same time."
		},
		{
			"FREAKY",
			{ "Christopher Landon" },
			{ "Vince Vaughn" , "Kathryn Newton" , "Celeste O' Connor"},
			{ {"Comedy"} , {"Horror"} , {"Thriller"} },
			2020,
			102,
			"After swapping bodies with a deranged serial killer, a young girl in high school discovers she has less than 24 hours before the change becomes permanent."
		},
		{
			"BATTLESHIPE",
			{ "Peter Berg" },
			{ "Alexander Skarsgard" , "Brooklyn Decker" , "Liam Neeson" , "Rihanna" },
			{ {"Action"} , {"Adventure"} , {"Sci-Fi"} },
			2012,
			131,
			"A fleet of ships is forced to do battle with an armada of unknown origins in order to discover and thwart their destructive goals."
		},
		{
			"The Lion King",
			{"Roger Allers", "Rob Minkoff"},
			{"Matthew Broderick", "Jeremy Irons", "James Earl Jones"},
			{{"Adventure"}, {"Animation"}, {"Drama"}},
			1994,
			88,
			"Lion prince Simba and his father are targeted by his bitter uncle, who wants to ascend the throne himself."

		},
		{
			"HOME",
			{ "Tim Johnson"},
			{ "Jim Parsons" , "Rihanna" , "Steve Martin" },
			{ {"Animation"}, {"Adventure"}, {"Comedy"} },
			2015,
			94,
			"An alien on the run from his own people makes friends with a girl. He tries to help her on her quest, but can be an interference."
		},
		{
			"The Intouchables",
			{ "Olivier Nakache, Eric Toledano" },
			{ "Francois Cluzet, Omar SyAnne Le Ny"},
			{ {"Comedy"}, {"Drama"} },
			2011,
			112,
			"After he becomes a quadriplegic from a paragliding accident, an aristocrat hires a young man from the projects to be his caregiver."
		},
		{
			"Shutter Island",
			{ "Martin Scorsese" },
			{"Leonardo DiCaprio, Emily Mortimer, Mark Ruffalo"},
			{{"Mystery"}, {"Thriller"}},
			2010,
			138,
			"In 1954, a U.S. Marshal investigates the disappearance of a murderer who escaped from a hospital for the criminally insane."
		},
		{
			"Thor Ragnarok",
			{"Taika Waititi"},
			{"Chris Hemsworth, Tom Hiddleston, Cate Blanchett"},
			{{"Action"}, {"Adventure"}, {"Comedy"}},
			2017,
			130,
			"Imprisoned on the planet Sakaar, Thor must race against time to return to Asgard and stop Ragnarok."
		},

	};

	// Αντιστοίχιση στοιχείων ταινίας με το αντικείμενο ταινίας
	for (int i = 0; i < 18; i++) { 
		Film* film = new Film;
		film->setFilmName(movies[i].title);
		film->setDirectors(movies[i].directors);
		film->setCast(movies[i].cast);
		film->setGenre(movies[i].genre);
		film->setYear(movies[i].year);
		film->setDuration(movies[i].duration);
		film->setSummary(movies[i].summary);

		if (i < 6)
		{
			film->setPosX((i + 1.5f) * 4.0f);
			film->setPosY(3.5f);
		}
		else if (i < 12)
		{
			film->setPosX((i - 4.5f) * 4.0f);
			film->setPosY(10.5f);
		}
		else
		{
			film->setPosX((i - 10.5f) * 4.0f);
			film->setPosY(17.5f);
		}
		films.push_back(film); //prosthetoume sto films kathe film

		years.insert(movies[i].year); //set poy periexei ta eth apo kathe tainia

		for (auto g : movies[i].genre)
		{
			nameButtons.insert(g); //set pou periexei ta onomata twn genre
		}
	}
}

// Επιστρέφει τα έτη των ταινιών
std::set<int> Library::getYears()
{
	return years;
}

// Επιστρέφει τα ονόματα των ειδών
std::set<std::string> Library::genreNames()
{
	return nameButtons;
}

// Συνάρτηση φίλτρου
std::list<Checkbox*> Library::filter(std::string text, std::list<Checkbox*> check)
{
	std::list<Checkbox*> newFilms; //NewFilms poy prepei na tupwthoun analoga to filtro

	for (auto che : check)
	{
		for (std::string g : che->getFilm()->getGenre()) //gia kathe filtro poy yparxei mesa se kathe tainia
		{
			if (g == text) //an ta filtra tainiwn tairiazoun me ta filtra poy mas orisan
			{
				newFilms.push_back(che); //prosthiki sthn lista
			}
		}
		if (std::to_string(che->getFilm()->getYear()) == text) //antistoixa gia to year
		{
			newFilms.push_back(che);
		}

	}

	return newFilms; //epistrefei thn lista

}

// Κατασκευαστής
Library::Library()
{

}

// Αποδόμηση
Library::~Library()
{
	for (auto f : films)
	{
		delete f; // Διαγράφουμε το αντικείμενο
	}
	films.clear(); // Αδειάζουμε τη λίστα για αποφυγή dangling pointers

	years.clear();       // Αδειάζουμε τα sets
	nameButtons.clear();
}
