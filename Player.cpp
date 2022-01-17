#include "Player.h"


Player::Player()
{
	this->movementSpeed = 3.f;
	this->initTexture();
	this->initSprite();
}

void Player::przesun(const float X, const float Y)
{
	this->sprite.move(this->movementSpeed * X, this->movementSpeed * Y);
}

void Player::initSprite()
{
	this->sprite.setScale(1.5, 1);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(80.f, 800.0f);
}


void Player::initTexture()
{
	this->texture.loadFromFile("Sam_Czerw.jpg");


}

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}