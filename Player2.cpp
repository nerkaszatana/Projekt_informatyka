#include "Player2.h"


Player2::Player2()
{
	this->movementSpeed = 3.f;
	this->initTexture();
	this->initSprite();
}

void Player2::przesun(const float X, const float Y)
{
	this->sprite2.move(this->movementSpeed * X, this->movementSpeed * Y);
}

void Player2::initSprite()
{
	this->sprite2.setScale(1.5, 1);
	this->sprite2.setTexture(this->texture2);
	this->sprite2.setPosition(590.f, 800.0f);
}

void Player2::initTexture()
{
	this->texture2.loadFromFile("Sam_Nieb.jpg");


}

void Player2::update()
{

}

void Player2::render(sf::RenderTarget& target)
{
	target.draw(this->sprite2);
}
