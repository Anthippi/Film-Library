#pragma once
#include "GUI.h"
#include <list>
#include "Library.h"

class Browser
{
    // Ορισμός ενός τύπου δεδομένων "status_g" που χρησιμοποιείται για να δηλώσει την τρέχουσα κατάσταση του προγράμματος
    typedef enum { LOAD, START, MOVIES } status_g;
    status_g status; // Αποθηκεύει την τρέχουσα κατάσταση του προγράμματος

    std::list<Checkbox*> check; // Λίστα από κουτάκια ελέγχου (Checkboxes)
    Checkbox* che = new Checkbox(*this); // Δημιουργία ενός αντικειμένου Checkbox για την αρχική χρήση

    Film* film = nullptr; // Δείκτης σε ταινία (αρχικά δεν υπάρχει ταινία)
    std::list<Film*> films; // Λίστα με ταινίες που είναι διαθέσιμες στον browser
    Library* lib = new Library(); // Δημιουργία μιας βιβλιοθήκης ταινιών (Library)

    FilterButton* clear = new FilterButton(*this); // Δημιουργία ενός κουμπιού φίλτρου για την εκκαθάριση επιλογών

    // Δημιουργία κουμπιών για πλοήγηση (πίσω, πάνω, κάτω)
    Button* backButton = new Button(*this);
    Button* upButton = new Button(*this);
    Button* downButton = new Button(*this);

    std::list<FilterButton*> genreButtons; // Λίστα κουμπιών φίλτρου για τα είδη ταινιών
    std::list<FilterButton*> yearsButtons; // Λίστα κουμπιών φίλτρου για τα έτη

    bool click1 = true; // Σημαία για έλεγχο της πρώτης κίνησης του χρήστη (π.χ., για αποφυγή πολλαπλών κλικ)
    bool click2 = true; // Σημαία για έλεγχο της δεύτερης κίνησης του χρήστη
    bool mesa = true; // Σημαία για κάποιο άλλο έλεγχο κατά την εκτέλεση της εφαρμογής

    // Συναρτήσεις που ενημερώνουν την κατάσταση για κάθε κατάσταση του προγράμματος
    void updateLoad(); 
    void updateStart();
    void updateMovies();

    // Συναρτήσεις για την εμφάνιση των διαφόρων καταστάσεων στην οθόνη
    void drawLoad(); 
    void drawStart();
    void drawMovies();

public:

    // Δημόσιες συναρτήσεις που καλούνται για την ενημέρωση και την εμφάνιση
    void update(); 
    void draw();

    // Συνάρτηση αρχικοποίησης
    void init();

    // Κατασκευαστής και καταστροφέας της κλάσης
    Browser(); 
    ~Browser();

};
