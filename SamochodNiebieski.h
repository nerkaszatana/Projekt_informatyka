#pragma once
#include <SFML\Graphics.hpp>


class Player2
{
private:
	sf::Sprite sprite1;
	sf::Texture texture1;
	float movementSpeed;
	void initTexture();
	void initSprite();
public:
	Player2();
	void update();
	void render(sf::RenderTarget& target);
	void przesun(const float X, const float Y);
};
