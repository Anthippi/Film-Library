#include "GUI.h"
#include "graphics.h"
#include "Browser.h"
#include "Film.h"

// Υλοποίηση της κλάσης Widget
void Widget::draw() {}


float Widget::getPosX()
{
	return pos_xy[0];
}

float Widget::getPosY()
{
	return pos_xy[1];
}

void Widget::setPosX(float x)
{
	// Η υλοποίηση μπορεί να προσδιοριστεί αργότερα
}

void Widget::setPosY(float y)
{
	// Η υλοποίηση μπορεί να προσδιοριστεί αργότερα
}

bool Widget::contains(float x, float y)
{
	return false;
}



Widget::Widget(const Browser& browser)
	: browser(browser)
{
}

Widget::~Widget()
{
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Υλοποίηση της κλάσης Button
void Button::draw()
{
	// Σχεδιάζουμε το κουμπί
}

float Button::getPosX()
{
	return pos_xy[0];
}

float Button::getPosY()
{
	return pos_xy[1];
}

void Button::setPosX(float x)
{
	pos_xy[0] = x;
}

void Button::setPosY(float y)
{
	pos_xy[1] = y;
}


void Button::setButtonName(std::string bname)
{
	this->buttonName = bname;
}

std::string Button::getButtonName()
{
	return buttonName;
}

// Ελέγχει αν το σημείο (x, y) είναι μέσα στο κουμπί
bool Button::contains(float x, float y) 
{
	if ((x < pos_xy[0] + 0.5f && x > pos_xy[0] - 0.5f) && (y < pos_xy[1] + 0.5f && y > pos_xy[1] - 0.5f))
	{

		return true; // Αν το σημείο είναι εντός του κουμπιού, επιστρέφει true
	}

	return false;
}


Button::Button(const Browser& browser)
	:Widget(browser)
{

}

Button::~Button()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Υλοποίηση της κλάσης FilterButton
void FilterButton::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 0.1f;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.1f;
	br.outline_opacity = 0.7f;

	graphics::drawRect(pos_xy[0], pos_xy[1], 2.6f, 0.8f, br); // Σχεδιάζει το φίλτρο ως κουμπί
}

float FilterButton::getPosX()
{
	return pos_xy[0];
}

float FilterButton::getPosY()
{
	return pos_xy[1];
}

void FilterButton::setPosX(float x)
{
	pos_xy[0] = x;
}

void FilterButton::setPosY(float y)
{
	pos_xy[1] = y;
}



bool FilterButton::contains(float x, float y)
{

	if ((x < pos_xy[0] + 1.3f && x > pos_xy[0] - 1.3f) && (y < pos_xy[1] + 0.5f && y > pos_xy[1] - 0.5f))
	{
		return true;// Ελέγχει αν το σημείο είναι μέσα στο κουμπί φίλτρου
	}

	return false;
}

FilterButton::FilterButton(const class Browser& browser)
	:Button(browser)
{

}

FilterButton::~FilterButton()
{
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Υλοποίηση της κλάσης Checkbox
void Checkbox::draw()
{
	graphics::Brush br;

	float h = 1.0f * highlighted; // Αν είναι επισημασμένο, το χρώμα του κουτιού θα είναι πιο έντονο

	br.fill_color[0] = h;
	br.fill_color[1] = h;
	br.fill_color[2] = h;
	br.outline_opacity = 0.0f;

	graphics::drawRect(pos_xy[0], pos_xy[1], 3.7f, 6.2f, br); // Σχεδιάζει το checkbox

}


bool Checkbox::contains(float x, float y)
{

	if ((x < pos_xy[0] + 1.8f && x > pos_xy[0] - 1.8f) && (y < pos_xy[1] + 3.1f && y > pos_xy[1] - 3.1f))
	{

		return true; // Ελέγχει αν το σημείο (x, y) είναι μέσα στο checkbox
	}

	return false;
}


void Checkbox::setHighlight(bool h)
{
	highlighted = h; // Ορίζει αν το checkbox είναι επισημασμένο
}

float Checkbox::getPosX()
{
	return pos_xy[0];
}

float Checkbox::getPosY()
{
	return pos_xy[1];
}

void Checkbox::setPosX(float x)
{
	pos_xy[0] = x;
}

void Checkbox::setPosY(float y)
{
	pos_xy[1] = y;
}


Film* Checkbox::getFilm()
{
	return film; // Επιστρέφει την ταινία που συνδέεται με το checkbox
}

void Checkbox::setFilm(Film* ofilm)
{
	film = ofilm; // Ορίζει την ταινία που συνδέεται με το checkbox
}


Checkbox::Checkbox(const Browser& browser)
	:Widget(browser)
{
}

Checkbox::~Checkbox()
{
}
