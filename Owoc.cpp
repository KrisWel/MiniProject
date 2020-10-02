#include "Owoc.h"

void Owoc::addTexture()
{
    if (!myTexture.loadFromFile("tekstury/owoc.png")) {
        std::cerr << "OWOC!!" << std::endl;
    }
    setTexture(myTexture);
}

void Owoc::Animuj()
{
    move(0.f, 0.05f);
    if (getPosition().y >= 900.f) {
        move(0.f, -900.f);
    }
}
