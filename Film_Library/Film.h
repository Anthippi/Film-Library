#pragma once
#include <iostream>
#include <string>
#include <list>
#include "GUI.h"
#include "defines.h"

class Film
{
    // ������� ��� ������ ��� ��� ������������� ��� ������� (���� �� x, y)
    float pos_xy[2];

private:
    // ����� ��� �������
    std::string filmName;

    // ���� ����������� ��� �������
    int year;

    // �������� ��� ������� �� �����
    int duration;

    // ����� �� �� ������� ��� ���������� ��� �������
    std::list<std::string> director;

    // ����� �� �� ������� ��� �������� (cast) ��� �������
    std::list<std::string> cast;

    // ����� �� �� ���� (genres) ��� �������
    std::list<std::string> genre;

    // �������� ��� ������� (summary)
    std::string summary;

public:

    // ��������� ��� ��� ��������� ��� �������� ��� �������
    std::string getFilmName();

    // ��������� ��� ��� ������ ��� �������� ��� �������
    void setFilmName(std::string fileName);

    // ��������� ��� ��� ��������� ��� ��������� ��� �������
    std::string getSummary();

    // ��������� ��� ��� ������ ��� ��������� ��� �������
    void setSummary(std::string summary);

    // ��������� ��� ��� ��������� ��� ����� ����������� ��� �������
    int getYear();

    // ��������� ��� ��� ������ ��� ����� ����������� ��� �������
    void setYear(int year);

    // ��������� ��� ��� ��������� ��� ��������� ��� �������
    int getDuration();

    // ��������� ��� ��� ������ ��� ��������� ��� �������
    void setDuration(int duration);

    // ��������� ��� ��� ��������� ��� ������ ��� ���������� ��� �������
    std::list<std::string> getDirectors();

    // ��������� ��� ��� ������ ��� ������ ��� ����������
    void setDirectors(std::list<std::string> Dname);

    // ��������� ��� ��� ��������� ��� ������ ��� �������� ��� �������
    std::list<std::string> getCast();

    // ��������� ��� ��� ������ ��� ������ ��� ��������
    void setCast(std::list<std::string> Cname);

    // ��������� ��� ��� ��������� ��� ������ ��� ����� ��� �������
    std::list<std::string> getGenre();

    // ��������� ��� ��� ������ ��� ������ ��� �����
    void setGenre(std::list<std::string> genre);

    // ������������� ����� �����������
    Film();

    // ������������� �� ����������� ��� �� �����, ����, ��������, ����������, ���������, ���� ��� ��������
    Film(std::string filmName, int year, int duration, std::list<std::string> director, std::list<std::string> cast, std::list<std::string> genre, std::string summary);

    // ������������ ��� ������ Film
    ~Film();

    // ��������� ��� ��� �������� ��� ������� ���� �����
    void draw();

    // ��������� ��� ��� ������ ��� ������������� x ��� ����� ��� �������
    void setPosX(float x);

    // ��������� ��� ��� ������ ��� ������������� y ��� ����� ��� �������
    void setPosY(float y);

    // ��������� ��� ��� ��������� ��� ������������� x ��� ����� ��� �������
    float getPosX();

    // ��������� ��� ��� ��������� ��� ������������� y ��� ����� ��� �������
    float getPosY();
};
