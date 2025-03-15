#pragma once
#include "Library.h"
#include "defines.h"
#include "Film.h"
#include <list>

class Film;

// Κλάση Widget που αντιπροσωπεύει ένα γενικό αντικείμενο του UI
class Widget
{
    // Πίνακας δύο θέσεων για τις συντεταγμένες (x, y) του widget
    float pos_xy[2];

    // Αναφορά σε αντικείμενο τύπου Browser
    const class Browser& browser;

public:

    // Συναρτήσεις που πρέπει να υλοποιηθούν από τις υποκλάσεις:
    // Ελέγχει αν το ποντίκι βρίσκεται εντός των ορίων του widget
    virtual bool contains(float x, float y) = 0;

    // Συναρτήσεις για την εμφάνιση του widget στην οθόνη
    virtual void draw() = 0;

    // Συναρτήσεις για τη διαχείριση των συντεταγμένων του widget
    virtual float getPosX() = 0;
    virtual float getPosY() = 0;
    virtual void setPosX(float x) = 0;
    virtual void setPosY(float y) = 0;

    // Κατασκευαστής που δέχεται αναφορά σε αντικείμενο Browser
    Widget(const class Browser& browser);

    // Καταστροφέας της κλάσης Widget
    ~Widget();
};

// Κλάση Button που κληρονομεί από την Widget και αντιπροσωπεύει ένα κουμπί
class Button : public Widget
{
    float pos_xy[2]; // Συντεταγμένες του κουμπιού
    std::string buttonName; // Όνομα του κουμπιού

public:

    // Υλοποίηση της συνάρτησης draw για την εμφάνιση του κουμπιού
    void draw() override;

    // Ελέγχει αν το ποντίκι βρίσκεται πάνω στο κουμπί
    bool contains(float x, float y);

    // Συναρτήσεις για τη διαχείριση των συντεταγμένων του κουμπιού
    float getPosX();
    float getPosY();
    void setPosX(float x);
    void setPosY(float y);

    // Συναρτήσεις για τη διαχείριση του ονόματος του κουμπιού
    void setButtonName(std::string bname);
    std::string getButtonName();

    // Κατασκευαστής που δέχεται αναφορά σε αντικείμενο Browser
    Button(const class Browser& browser);

    // Καταστροφέας της κλάσης Button
    ~Button();
};

// Κλάση FilterButton που κληρονομεί από την Button και αντιπροσωπεύει κουμπιά φίλτρων
class FilterButton : public Button
{
    float pos_xy[2]; // Συντεταγμένες του φίλτρου

public:

    // Υλοποίηση της συνάρτησης draw για την εμφάνιση του κουμπιού φίλτρου
    void draw() override;

    // Ελέγχει αν το ποντίκι βρίσκεται πάνω στο φίλτρο
    bool contains(float x, float y);

    // Συναρτήσεις για τη διαχείριση των συντεταγμένων του φίλτρου
    float getPosX();
    float getPosY();
    void setPosX(float x);
    void setPosY(float y);

    // Κατασκευαστής που δέχεται αναφορά σε αντικείμενο Browser
    FilterButton(const class Browser& browser);

    // Καταστροφέας της κλάσης FilterButton
    ~FilterButton();
};

// Κλάση Checkbox που κληρονομεί από την Widget και αντιπροσωπεύει ένα checkbox
class Checkbox : public Widget
{
    Film* film; // Σύνδεση με ταινία (Film)
    float pos_xy[2]; // Συντεταγμένες του checkbox
    bool highlighted = false; // Αν είναι επισημασμένο το checkbox (true αν είναι ενεργό)

public:

    // Υλοποίηση της συνάρτησης draw για την εμφάνιση του checkbox
    void draw() override;

    // Συναρτήσεις για την ενεργοποίηση/απενεργοποίηση της επισήμανσης του checkbox
    void setHighlight(bool h);
    bool contains(float x, float y);

    // Συναρτήσεις για τη διαχείριση των συντεταγμένων του checkbox
    float getPosX();
    float getPosY();
    void setPosX(float x);
    void setPosY(float y);

    // Συναρτήσεις για την ανάκτηση και ορισμό της ταινίας που αντιστοιχεί στο checkbox
    Film* getFilm();
    void setFilm(Film* film);

    // Κατασκευαστής που δέχεται αναφορά σε αντικείμενο Browser
    Checkbox(const class Browser& browser);

    // Καταστροφέας της κλάσης Checkbox
    ~Checkbox();
};
