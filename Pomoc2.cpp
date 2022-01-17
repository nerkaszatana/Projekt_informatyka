#include "Pomoc2.h"

Pomoc2::Pomoc2()
{
	this->initTexture();
	this->initSprite();
	this->movementSpeed = 1.f;
}

void Pomoc2::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(0.f, -600.f);
}


void Pomoc2::initTexture()
{
	this->texture.loadFromFile("pomoc.png");
}

void Pomoc2::przesun(float X, float Y)
{
	this->sprite.setPosition(X, Y);
}

void Pomoc2::update()
{

}

void Pomoc2::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
