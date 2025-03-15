#include "graphics.h"
#include "Browser.h"

// Συνάρτηση ενημέρωσης
void update(float ms)
{
    // Δημιουργούμε δείκτη στον περιηγητή (Browser)
    Browser* bro = reinterpret_cast<Browser*>(graphics::getUserData());
    bro->update(); // Ενημερώνουμε τον περιηγητή
}

// Συνάρτηση σχεδίασης
void draw()
{
    // Δημιουργούμε δείκτη στον περιηγητή (Browser)
    Browser* bro = reinterpret_cast<Browser*>(graphics::getUserData());
    bro->draw(); // Σχεδιάζουμε τον περιηγητή
}

int main()
{
    // Δημιουργούμε έναν νέο περιηγητή
    Browser browser;

    // Δημιουργούμε το παράθυρο του γραφικού περιβάλλοντος
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Movies");

    // Ορίζουμε τα δεδομένα του χρήστη (την παρουσία του περιηγητή)
    graphics::setUserData(&browser);

    // Ορίζουμε τη συνάρτηση σχεδίασης
    graphics::setDrawFunction(draw);

    // Ορίζουμε τη συνάρτηση ενημέρωσης
    graphics::setUpdateFunction(update);

    // Ορίζουμε το μέγεθος του καμβά
    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);

    // Ορίζουμε τη λειτουργία κλίμακας του καμβά
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    // Αρχικοποιούμε τον περιηγητή
    browser.init();

    // Ξεκινάμε τον βρόχο μηνυμάτων του γραφικού περιβάλλοντος
    graphics::startMessageLoop();

    return 0;
}
