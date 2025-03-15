#pragma once
#include <iostream>
#include <string>
#include <list>
#include "GUI.h"
#include "defines.h"

class Film
{
    // Πίνακας δύο θέσεων για τις συντεταγμένες της ταινίας (θέση σε x, y)
    float pos_xy[2];

private:
    // Όνομα της ταινίας
    std::string filmName;

    // Έτος κυκλοφορίας της ταινίας
    int year;

    // Διάρκεια της ταινίας σε λεπτά
    int duration;

    // Λίστα με τα ονόματα των σκηνοθετών της ταινίας
    std::list<std::string> director;

    // Λίστα με τα ονόματα των ηθοποιών (cast) της ταινίας
    std::list<std::string> cast;

    // Λίστα με τα είδη (genres) της ταινίας
    std::list<std::string> genre;

    // Περίληψη της ταινίας (summary)
    std::string summary;

public:

    // Συνάρτηση για την επιστροφή του ονόματος της ταινίας
    std::string getFilmName();

    // Συνάρτηση για τον ορισμό του ονόματος της ταινίας
    void setFilmName(std::string fileName);

    // Συνάρτηση για την επιστροφή της περίληψης της ταινίας
    std::string getSummary();

    // Συνάρτηση για τον ορισμό της περίληψης της ταινίας
    void setSummary(std::string summary);

    // Συνάρτηση για την επιστροφή του έτους κυκλοφορίας της ταινίας
    int getYear();

    // Συνάρτηση για τον ορισμό του έτους κυκλοφορίας της ταινίας
    void setYear(int year);

    // Συνάρτηση για την επιστροφή της διάρκειας της ταινίας
    int getDuration();

    // Συνάρτηση για τον ορισμό της διάρκειας της ταινίας
    void setDuration(int duration);

    // Συνάρτηση για την επιστροφή της λίστας των σκηνοθετών της ταινίας
    std::list<std::string> getDirectors();

    // Συνάρτηση για τον ορισμό της λίστας των σκηνοθετών
    void setDirectors(std::list<std::string> Dname);

    // Συνάρτηση για την επιστροφή της λίστας των ηθοποιών της ταινίας
    std::list<std::string> getCast();

    // Συνάρτηση για τον ορισμό της λίστας των ηθοποιών
    void setCast(std::list<std::string> Cname);

    // Συνάρτηση για την επιστροφή της λίστας των ειδών της ταινίας
    std::list<std::string> getGenre();

    // Συνάρτηση για τον ορισμό της λίστας των ειδών
    void setGenre(std::list<std::string> genre);

    // Κατασκευαστής χωρίς παραμέτρους
    Film();

    // Κατασκευαστής με παραμέτρους για το όνομα, έτος, διάρκεια, σκηνοθέτες, ηθοποιούς, είδη και περίληψη
    Film(std::string filmName, int year, int duration, std::list<std::string> director, std::list<std::string> cast, std::list<std::string> genre, std::string summary);

    // Καταστροφέας της κλάσης Film
    ~Film();

    // Συνάρτηση για την εμφάνιση της ταινίας στην οθόνη
    void draw();

    // Συνάρτηση για τον ορισμό της συντεταγμένης x της θέσης της ταινίας
    void setPosX(float x);

    // Συνάρτηση για τον ορισμό της συντεταγμένης y της θέσης της ταινίας
    void setPosY(float y);

    // Συνάρτηση για την επιστροφή της συντεταγμένης x της θέσης της ταινίας
    float getPosX();

    // Συνάρτηση για την επιστροφή της συντεταγμένης y της θέσης της ταινίας
    float getPosY();
};
