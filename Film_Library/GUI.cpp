#include "GUI.h"
#include "graphics.h"
#include "Browser.h"
#include "Film.h"

// ��������� ��� ������ Widget
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
	// � ��������� ������ �� ������������� ��������
}

void Widget::setPosY(float y)
{
	// � ��������� ������ �� ������������� ��������
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

// ��������� ��� ������ Button
void Button::draw()
{
	// ����������� �� ������
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

// ������� �� �� ������ (x, y) ����� ���� ��� ������
bool Button::contains(float x, float y) 
{
	if ((x < pos_xy[0] + 0.5f && x > pos_xy[0] - 0.5f) && (y < pos_xy[1] + 0.5f && y > pos_xy[1] - 0.5f))
	{

		return true; // �� �� ������ ����� ����� ��� ��������, ���������� true
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
// ��������� ��� ������ FilterButton
void FilterButton::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 0.1f;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.1f;
	br.outline_opacity = 0.7f;

	graphics::drawRect(pos_xy[0], pos_xy[1], 2.6f, 0.8f, br); // ��������� �� ������ �� ������
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
		return true;// ������� �� �� ������ ����� ���� ��� ������ �������
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
// ��������� ��� ������ Checkbox
void Checkbox::draw()
{
	graphics::Brush br;

	float h = 1.0f * highlighted; // �� ����� ������������, �� ����� ��� ������� �� ����� ��� ������

	br.fill_color[0] = h;
	br.fill_color[1] = h;
	br.fill_color[2] = h;
	br.outline_opacity = 0.0f;

	graphics::drawRect(pos_xy[0], pos_xy[1], 3.7f, 6.2f, br); // ��������� �� checkbox

}


bool Checkbox::contains(float x, float y)
{

	if ((x < pos_xy[0] + 1.8f && x > pos_xy[0] - 1.8f) && (y < pos_xy[1] + 3.1f && y > pos_xy[1] - 3.1f))
	{

		return true; // ������� �� �� ������ (x, y) ����� ���� ��� checkbox
	}

	return false;
}


void Checkbox::setHighlight(bool h)
{
	highlighted = h; // ������ �� �� checkbox ����� ������������
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
	return film; // ���������� ��� ������ ��� ��������� �� �� checkbox
}

void Checkbox::setFilm(Film* ofilm)
{
	film = ofilm; // ������ ��� ������ ��� ��������� �� �� checkbox
}


Checkbox::Checkbox(const Browser& browser)
	:Widget(browser)
{
}

Checkbox::~Checkbox()
{
}
