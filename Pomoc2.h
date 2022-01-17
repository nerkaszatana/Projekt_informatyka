#pragma once
#include <SFML/Graphics.hpp>
class Pomoc2
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	void initTexture();
	void initSprite();
	float movementSpeed;
public:
	Pomoc2();
	void update();
	void render(sf::RenderTarget& target);
	void przesun(float X, float Y);
};