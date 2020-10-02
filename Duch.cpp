#include "Duch.h"

Duch::Duch()
{
    if (rand() % 10 > 5) lewo = true;
    else lewo = false;
}

void Duch::addTexture()
{
    if (!myTexture.loadFromFile("tekstury/duch.png")) {
        std::cerr << "DUCH!!" << std::endl;
    }
    setTexture(myTexture);
}

void Duch::Animuj()
{
    if (lewo) move(-0.05f, 0.f);
    else move(0.05f, 0.f);
    if (getPosition().x > 1600.f) {
        move(-1600.f, 0.f);
    }
    else if (getPosition().x < 0.f) {
        move(1600.f, 0.f);
    }
}
