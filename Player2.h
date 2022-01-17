#pragma once
#include <SFML/Graphics.hpp>
class Player2
{
private:
	sf::Sprite sprite2;
	sf::Texture texture2;
	float movementSpeed;
	void initTexture();
	void initSprite();
public:
	Player2();
	void update();
	void render(sf::RenderTarget& target);
	void przesun(const float X, const float Y);
};