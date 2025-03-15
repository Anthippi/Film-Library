#include "Film.h"
#include "GUI.h"
#include "graphics.h"

// Συνάρτηση για να επιστρέφει το όνομα της ταινίας
std::string Film::getFilmName()
{
    return filmName;
}

// Συνάρτηση για να ορίζει το όνομα της ταινίας
void Film::setFilmName(std::string fileName)
{
    this->filmName = fileName;
}

// Συνάρτηση για να επιστρέφει το έτος της ταινίας
int Film::getYear()
{
    return year;
}

// Συνάρτηση για να ορίζει το έτος της ταινίας
void Film::setYear(int year)
{
    this->year = year;
}

// Συνάρτηση για να επιστρέφει τη λίστα με τους σκηνοθέτες
std::list<std::string> Film::getDirectors()
{
    return director;
}

// Συνάρτηση για να ορίζει τη λίστα με τους σκηνοθέτες
void Film::setDirectors(std::list<std::string> Dname)
{
    this->director = Dname;
}

// Συνάρτηση για να επιστρέφει τη λίστα με το καστ της ταινίας
std::list<std::string> Film::getCast()
{
    return cast;
}

// Συνάρτηση για να ορίζει τη λίστα με το καστ της ταινίας
void Film::setCast(std::list<std::string> Cname)
{
    this->cast = Cname;
}

// Συνάρτηση για να επιστρέφει τη λίστα με τα είδη της ταινίας
std::list<std::string> Film::getGenre()
{
    return genre;
}

// Συνάρτηση για να ορίζει τα είδη της ταινίας
void Film::setGenre(std::list<std::string> genre)
{
    this->genre = genre;
}

// Συνάρτηση για να ορίζει την περιγραφή της ταινίας
void Film::setSummary(std::string summary)
{
    this->summary = summary;
}

// Συνάρτηση για να επιστρέφει την περιγραφή της ταινίας
std::string Film::getSummary()
{
    return summary;
}

// Συνάρτηση για να ορίζει τη διάρκεια της ταινίας
void Film::setDuration(int duration)
{
    this->duration = duration;
}

// Συνάρτηση για να επιστρέφει τη διάρκεια της ταινίας
int Film::getDuration()
{
    return duration;
}

// Κατασκευαστής της κλάσης Film
Film::Film()
{
}

// Κατασκευαστής της κλάσης Film με παραμέτρους για την ταινία
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

// Καταστροφέας της κλάσης Film
Film::~Film()
{
}

// Συνάρτηση για να σχεδιάσει την ταινία στην οθόνη
void Film::draw()
{
    graphics::Brush br;
    std::string photo = getFilmName() + std::string(".png");// otan kaleitai h draw me thn getFilmName() pernoume to onoma ths tainias
    br.texture = std::string(ASSET_PATH) + photo;// kai prosthetontas to .png psaxnei sta assets thn eikona pou exei to idio onom ame thn tainia
    br.outline_opacity = 0.0f;
    graphics::drawRect(getPosX(), getPosY(), 3.5f, 6.0f, br);
}

// Συνάρτηση για να ορίσει τη θέση x της ταινίας
void Film::setPosX(float x)
{
    pos_xy[0] = x;
}

// Συνάρτηση για να ορίσει τη θέση y της ταινίας
void Film::setPosY(float y)
{
    pos_xy[1] = y;
}

// Συνάρτηση για να επιστρέψει τη θέση x της ταινίας
float Film::getPosX()
{
    return pos_xy[0];
}

// Συνάρτηση για να επιστρέψει τη θέση y της ταινίας
float Film::getPosY()
{
    return pos_xy[1];
}