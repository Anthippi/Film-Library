#pragma once
#include "Library.h"
#include "defines.h"
#include "Film.h"
#include <list>

class Film;

// ����� Widget ��� �������������� ��� ������ ����������� ��� UI
class Widget
{
    // ������� ��� ������ ��� ��� ������������� (x, y) ��� widget
    float pos_xy[2];

    // ������� �� ����������� ����� Browser
    const class Browser& browser;

public:

    // ����������� ��� ������ �� ����������� ��� ��� ����������:
    // ������� �� �� ������� ��������� ����� ��� ����� ��� widget
    virtual bool contains(float x, float y) = 0;

    // ����������� ��� ��� �������� ��� widget ���� �����
    virtual void draw() = 0;

    // ����������� ��� �� ���������� ��� ������������� ��� widget
    virtual float getPosX() = 0;
    virtual float getPosY() = 0;
    virtual void setPosX(float x) = 0;
    virtual void setPosY(float y) = 0;

    // ������������� ��� ������� ������� �� ����������� Browser
    Widget(const class Browser& browser);

    // ������������ ��� ������ Widget
    ~Widget();
};

// ����� Button ��� ���������� ��� ��� Widget ��� �������������� ��� ������
class Button : public Widget
{
    float pos_xy[2]; // ������������� ��� ��������
    std::string buttonName; // ����� ��� ��������

public:

    // ��������� ��� ���������� draw ��� ��� �������� ��� ��������
    void draw() override;

    // ������� �� �� ������� ��������� ���� ��� ������
    bool contains(float x, float y);

    // ����������� ��� �� ���������� ��� ������������� ��� ��������
    float getPosX();
    float getPosY();
    void setPosX(float x);
    void setPosY(float y);

    // ����������� ��� �� ���������� ��� �������� ��� ��������
    void setButtonName(std::string bname);
    std::string getButtonName();

    // ������������� ��� ������� ������� �� ����������� Browser
    Button(const class Browser& browser);

    // ������������ ��� ������ Button
    ~Button();
};

// ����� FilterButton ��� ���������� ��� ��� Button ��� �������������� ������� �������
class FilterButton : public Button
{
    float pos_xy[2]; // ������������� ��� �������

public:

    // ��������� ��� ���������� draw ��� ��� �������� ��� �������� �������
    void draw() override;

    // ������� �� �� ������� ��������� ���� ��� ������
    bool contains(float x, float y);

    // ����������� ��� �� ���������� ��� ������������� ��� �������
    float getPosX();
    float getPosY();
    void setPosX(float x);
    void setPosY(float y);

    // ������������� ��� ������� ������� �� ����������� Browser
    FilterButton(const class Browser& browser);

    // ������������ ��� ������ FilterButton
    ~FilterButton();
};

// ����� Checkbox ��� ���������� ��� ��� Widget ��� �������������� ��� checkbox
class Checkbox : public Widget
{
    Film* film; // ������� �� ������ (Film)
    float pos_xy[2]; // ������������� ��� checkbox
    bool highlighted = false; // �� ����� ������������ �� checkbox (true �� ����� ������)

public:

    // ��������� ��� ���������� draw ��� ��� �������� ��� checkbox
    void draw() override;

    // ����������� ��� ��� ������������/�������������� ��� ����������� ��� checkbox
    void setHighlight(bool h);
    bool contains(float x, float y);

    // ����������� ��� �� ���������� ��� ������������� ��� checkbox
    float getPosX();
    float getPosY();
    void setPosX(float x);
    void setPosY(float y);

    // ����������� ��� ��� �������� ��� ������ ��� ������� ��� ����������� ��� checkbox
    Film* getFilm();
    void setFilm(Film* film);

    // ������������� ��� ������� ������� �� ����������� Browser
    Checkbox(const class Browser& browser);

    // ������������ ��� ������ Checkbox
    ~Checkbox();
};
