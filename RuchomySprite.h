#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <stdlib.h>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class RuchomySprite : public sf::Sprite
{
public:

	virtual void addTexture() = 0;
	virtual void Animuj() = 0;

protected:
	sf::Texture myTexture;
};

