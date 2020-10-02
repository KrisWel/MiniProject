#include "Duch.h"
#include "Owoc.h"
#include "PacMan.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "PackMan");
    srand(time(NULL));

    //                               OBJECTS
    std::unique_ptr<PacMan> pacman = std::make_unique<PacMan>();
    std::vector<std::unique_ptr<Owoc>> owoce;
    std::vector<std::unique_ptr<Duch>> duchy;
    //                               OBJECTS

    //                              ADDING TEXTURES
    sf::Vector2f posit;
    for (int i = 0; i < 10; i++) {
        posit.x = rand() % 1600;
        posit.y = rand() % 900;
        owoce.push_back(std::make_unique<Owoc>());
        owoce[i]->addTexture();
        owoce[i]->setPosition(posit);
    }
    for (int i = 0; i < 25; i++) {
        posit.x = rand() % 1600;
        posit.y = rand() % 900;
        duchy.push_back(std::make_unique<Duch>());
        duchy[i]->addTexture();
        duchy[i]->setPosition(posit);
    }
    pacman->addTexture();
    pacman->setPosition(800.f, 450.f);
    //                              ADDING TEXTURES

    while (window.isOpen())
    {
        //Changing movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            pacman->changeMove(-0.05f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            pacman->changeMove(0.05f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            pacman->changeMove(0.f, -0.05f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            pacman->changeMove(0.f, 0.05f);
        }

        //Collision
        std::vector<std::unique_ptr<Owoc>>::iterator ito =
            std::find_if(owoce.begin(), owoce.end(),
                [&](std::unique_ptr<Owoc>& obj) { return pacman->getGlobalBounds().intersects(obj->getGlobalBounds()); }
        );
        if (ito != owoce.end()) {
            owoce.erase(ito);
            pacman->owoc();
        }

        std::vector<std::unique_ptr<Duch>>::iterator itd =
            std::find_if(duchy.begin(), duchy.end(),
                [&](std::unique_ptr<Duch>& obj) { return pacman->getGlobalBounds().intersects(obj->getGlobalBounds()); }
        );
        if (itd != duchy.end()) {
            duchy.erase(itd);
            pacman->duch();
        }

        //end game
        if (pacman->getPunkty() == 1000) {
            std::cout << "YOU WIN" << std::endl;
            window.close();
        }
        if (pacman->getZycia() <= 0) {
            std::cout << "YOU LOSE" << std::endl;
            window.close();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //Animations

        pacman->Animuj();
        window.draw(*pacman);
        for (auto& it : owoce) {
            it->Animuj();
            window.draw(*it);
        }
        for (auto& it : duchy) {
            it->Animuj();
            window.draw(*it);
        }

        //Animations
        
        window.display();
    }

    return 0;
}