#pragma once
#include "GUI.h"
#include <list>
#include "Library.h"

class Browser
{
    // ������� ���� ����� ��������� "status_g" ��� ��������������� ��� �� ������� ��� �������� ��������� ��� ������������
    typedef enum { LOAD, START, MOVIES } status_g;
    status_g status; // ���������� ��� �������� ��������� ��� ������������

    std::list<Checkbox*> check; // ����� ��� �������� ������� (Checkboxes)
    Checkbox* che = new Checkbox(*this); // ���������� ���� ������������ Checkbox ��� ��� ������ �����

    Film* film = nullptr; // ������� �� ������ (������ ��� ������� ������)
    std::list<Film*> films; // ����� �� ������� ��� ����� ���������� ���� browser
    Library* lib = new Library(); // ���������� ���� ����������� ������� (Library)

    FilterButton* clear = new FilterButton(*this); // ���������� ���� �������� ������� ��� ��� ���������� ��������

    // ���������� �������� ��� �������� (����, ����, ����)
    Button* backButton = new Button(*this);
    Button* upButton = new Button(*this);
    Button* downButton = new Button(*this);

    std::list<FilterButton*> genreButtons; // ����� �������� ������� ��� �� ���� �������
    std::list<FilterButton*> yearsButtons; // ����� �������� ������� ��� �� ���

    bool click1 = true; // ������ ��� ������ ��� ������ ������� ��� ������ (�.�., ��� ������� ��������� ����)
    bool click2 = true; // ������ ��� ������ ��� �������� ������� ��� ������
    bool mesa = true; // ������ ��� ������ ���� ������ ���� ��� �������� ��� ���������

    // ����������� ��� ����������� ��� ��������� ��� ���� ��������� ��� ������������
    void updateLoad(); 
    void updateStart();
    void updateMovies();

    // ����������� ��� ��� �������� ��� �������� ����������� ���� �����
    void drawLoad(); 
    void drawStart();
    void drawMovies();

public:

    // �������� ����������� ��� ��������� ��� ��� ��������� ��� ��� ��������
    void update(); 
    void draw();

    // ��������� �������������
    void init();

    // ������������� ��� ������������ ��� ������
    Browser(); 
    ~Browser();

};
