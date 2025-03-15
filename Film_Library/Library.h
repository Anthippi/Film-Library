#pragma once
#include "Film.h"
#include "defines.h"
#include <list>
#include "GUI.h"
#include <set>

class Film;
class Button;
class Checkbox;

// Κλάση Library που διαχειρίζεται τις ταινίες και τα φίλτρα τους
class Library
{
    // Δείκτης σε ταινία (Film)
    Film* film;

    // Λίστα με τις ταινίες που περιλαμβάνονται στη βιβλιοθήκη
    std::list<Film*> films;

    // Σύνολο με τα ονόματα των κουμπιών (buttons) που αντιπροσωπεύουν φίλτρα
    std::set<std::string> nameButtons;

    // Σύνολο με τα έτη κυκλοφορίας των ταινιών
    std::set<int> years;

public:

    // Συνάρτηση για την αρχικοποίηση της βιβλιοθήκης (π.χ., φόρτωση ταινιών, κουμπιών φίλτρων κλπ.)
    void init();

    // Συνάρτηση που επιστρέφει μια λίστα με τα checkbox που αντιστοιχούν στο φίλτρο αναζητούμενων ταινιών
    std::list<Checkbox*> filter(std::string text, std::list<Checkbox*> check);

    // Συνάρτηση που επιστρέφει την λίστα με όλες τις ταινίες της βιβλιοθήκης
    std::list<Film*> getFilms();

    // Συνάρτηση που επιστρέφει ένα σύνολο με τα είδη (genres) των ταινιών
    std::set<std::string> genreNames();

    // Συνάρτηση που επιστρέφει ένα σύνολο με τα έτη κυκλοφορίας των ταινιών
    std::set<int> getYears();

    // Κατασκευαστής της κλάσης Library
    Library();

    // Καταστροφέας της κλάσης Library
    ~Library();
};
