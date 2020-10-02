#pragma once
#include "RuchomySprite.h"
class PacMan : public RuchomySprite
{
public:

	PacMan();
	void addTexture();
	void Animuj();
	void changeMove(float x, float y);
	void duch();
	void owoc();

	const int getZycia() const;
	const int getPunkty() const;

private:

	float x, y;
	int zycia, punkty;
};

