#include "SamochodNiebieski.h"

Player2::Player2()
{
	this->movementSpeed = 1.f;
	this->initTexture();
	this->initSprite();
}

void Player2::przesun(const float X, const float Y)
{
	this->sprite1.move(this->movementSpeed * X, this->movementSpeed * Y);
}

void Player2::initSprite()
{
	this->sprite1.setTexture(this->texture1);
}

void Player2::initTexture()
{
	this->texture1.loadFromFile("Sam_Nieb.jpg");


}

void Player2::update()
{

}

void Player2::render(sf::RenderTarget& target)
{
	target.draw(this->sprite1);
}