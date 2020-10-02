#include "PacMan.h"

PacMan::PacMan()
{
    x = 0.05f;
    y = 0.f;
    zycia = 3;
    punkty = 0;
}

void PacMan::addTexture()
{
    if (!myTexture.loadFromFile("tekstury/pacman.png")) {
        std::cerr << "PACMAN!!" << std::endl;
    }
    setTexture(myTexture);
}

void PacMan::Animuj()
{
    move(x, y);
    if (getPosition().x >= 1600.f) {
        move(-1600.f, 0.f);
    }
}

void PacMan::changeMove(float x, float y)
{
    this->x = x;
    this->y = y;
}

void PacMan::duch()
{
    zycia--;
    setPosition(800.f, 450.f);
}

void PacMan::owoc()
{
    punkty += 100;
}

const int PacMan::getZycia() const
{
    return zycia;
}

const int PacMan::getPunkty() const
{
    return punkty;
}
