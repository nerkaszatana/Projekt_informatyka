#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Game.h"
#include "Game.cpp"

class Player1
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;
	void initTexture();
	void initSprite();
public:
	Player1();
	void update();
	void render(sf::RenderTarget& target);
	void przesun(const float X, const float Y);
};

