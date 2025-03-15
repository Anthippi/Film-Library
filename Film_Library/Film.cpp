#include "Film.h"
#include "GUI.h"
#include "graphics.h"

// ��������� ��� �� ���������� �� ����� ��� �������
std::string Film::getFilmName()
{
    return filmName;
}

// ��������� ��� �� ������ �� ����� ��� �������
void Film::setFilmName(std::string fileName)
{
    this->filmName = fileName;
}

// ��������� ��� �� ���������� �� ���� ��� �������
int Film::getYear()
{
    return year;
}

// ��������� ��� �� ������ �� ���� ��� �������
void Film::setYear(int year)
{
    this->year = year;
}

// ��������� ��� �� ���������� �� ����� �� ���� ����������
std::list<std::string> Film::getDirectors()
{
    return director;
}

// ��������� ��� �� ������ �� ����� �� ���� ����������
void Film::setDirectors(std::list<std::string> Dname)
{
    this->director = Dname;
}

// ��������� ��� �� ���������� �� ����� �� �� ���� ��� �������
std::list<std::string> Film::getCast()
{
    return cast;
}

// ��������� ��� �� ������ �� ����� �� �� ���� ��� �������
void Film::setCast(std::list<std::string> Cname)
{
    this->cast = Cname;
}

// ��������� ��� �� ���������� �� ����� �� �� ���� ��� �������
std::list<std::string> Film::getGenre()
{
    return genre;
}

// ��������� ��� �� ������ �� ���� ��� �������
void Film::setGenre(std::list<std::string> genre)
{
    this->genre = genre;
}

// ��������� ��� �� ������ ��� ��������� ��� �������
void Film::setSummary(std::string summary)
{
    this->summary = summary;
}

// ��������� ��� �� ���������� ��� ��������� ��� �������
std::string Film::getSummary()
{
    return summary;
}

// ��������� ��� �� ������ �� �������� ��� �������
void Film::setDuration(int duration)
{
    this->duration = duration;
}

// ��������� ��� �� ���������� �� �������� ��� �������
int Film::getDuration()
{
    return duration;
}

// ������������� ��� ������ Film
Film::Film()
{
}

// ������������� ��� ������ Film �� ����������� ��� ��� ������
Film::Film(std::string filmName, int year, int duration, std::list<std::string> director, std::list<std::string> cast, std::list<std::string> genre, std::string summary)
{
    this->filmName = filmName;
    this->year = year;
    this->duration = duration;
    this->director = director;
    this->cast = cast;
    this->genre = genre;
    this->summary = summary;
}

// ������������ ��� ������ Film
Film::~Film()
{
}

// ��������� ��� �� ��������� ��� ������ ���� �����
void Film::draw()
{
    graphics::Brush br;
    std::string photo = getFilmName() + std::string(".png");// otan kaleitai h draw me thn getFilmName() pernoume to onoma ths tainias
    br.texture = std::string(ASSET_PATH) + photo;// kai prosthetontas to .png psaxnei sta assets thn eikona pou exei to idio onom ame thn tainia
    br.outline_opacity = 0.0f;
    graphics::drawRect(getPosX(), getPosY(), 3.5f, 6.0f, br);
}

// ��������� ��� �� ������ �� ���� x ��� �������
void Film::setPosX(float x)
{
    pos_xy[0] = x;
}

// ��������� ��� �� ������ �� ���� y ��� �������
void Film::setPosY(float y)
{
    pos_xy[1] = y;
}

// ��������� ��� �� ���������� �� ���� x ��� �������
float Film::getPosX()
{
    return pos_xy[0];
}

// ��������� ��� �� ���������� �� ���� y ��� �������
float Film::getPosY()
{
    return pos_xy[1];
}