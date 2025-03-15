#pragma once
#include "Film.h"
#include "defines.h"
#include <list>
#include "GUI.h"
#include <set>

class Film;
class Button;
class Checkbox;

// ����� Library ��� ������������� ��� ������� ��� �� ������ ����
class Library
{
    // ������� �� ������ (Film)
    Film* film;

    // ����� �� ��� ������� ��� ��������������� ��� ����������
    std::list<Film*> films;

    // ������ �� �� ������� ��� �������� (buttons) ��� ��������������� ������
    std::set<std::string> nameButtons;

    // ������ �� �� ��� ����������� ��� �������
    std::set<int> years;

public:

    // ��������� ��� ��� ������������ ��� ����������� (�.�., ������� �������, �������� ������� ���.)
    void init();

    // ��������� ��� ���������� ��� ����� �� �� checkbox ��� ������������ ��� ������ ������������� �������
    std::list<Checkbox*> filter(std::string text, std::list<Checkbox*> check);

    // ��������� ��� ���������� ��� ����� �� ���� ��� ������� ��� �����������
    std::list<Film*> getFilms();

    // ��������� ��� ���������� ��� ������ �� �� ���� (genres) ��� �������
    std::set<std::string> genreNames();

    // ��������� ��� ���������� ��� ������ �� �� ��� ����������� ��� �������
    std::set<int> getYears();

    // ������������� ��� ������ Library
    Library();

    // ������������ ��� ������ Library
    ~Library();
};
