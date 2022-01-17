#include "SamochodCzerwony.h"

Player1::Player1()
{
	this->movementSpeed = 1.f;
	this->initTexture();
	this->initSprite();
}

void Player1::przesun(const float X, const float Y)
{
	this->sprite.move(this->movementSpeed * X, this->movementSpeed * Y);
}

void Player1::initSprite()
{
	this->sprite.setTexture(this->texture);
}

void Player1::initTexture()
{
	this->texture.loadFromFile("Sam_Czerw.jpg");


}

void Player1::update()
{

}

void Player1::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}