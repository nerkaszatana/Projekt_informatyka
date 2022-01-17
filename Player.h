#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;
	void initTexture();
	void initSprite();
public:
	Player();
	void update();
	void render(sf::RenderTarget& target);
	void przesun(const float X, const float Y);
	const sf::RectangleShape& getGlobalBounds() const;
	bool Skret = false;
};

