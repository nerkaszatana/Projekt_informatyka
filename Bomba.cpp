#include "Bomba.h"

Bomba::Bomba(float posX, float posY)
{
	this->bomba.setPosition(
		static_cast<float>(rand() % static_cast<int>(50, 750)),
		-250.f
	);
	this->initshape();
	this->initvariables();
}

void Bomba::initshape()
{
	bomba.setPointCount(11);
	bomba.setPoint(0, sf::Vector2f(0, 0));
	bomba.setPoint(1, sf::Vector2f(5, 10));
	bomba.setPoint(2, sf::Vector2f(15, 15));
	bomba.setPoint(3, sf::Vector2f(5, 20));
	bomba.setPoint(4, sf::Vector2f(12, 27));
	bomba.setPoint(5, sf::Vector2f(5, 20));
	bomba.setPoint(6, sf::Vector2f(-12, 27));
	bomba.setPoint(7, sf::Vector2f(-5, 20));
	bomba.setPoint(8, sf::Vector2f(-15, 15));
	bomba.setPoint(9, sf::Vector2f(-5, 10));
	bomba.setPoint(10, sf::Vector2f(0, 0));
	bomba.setFillColor(sf::Color::Red);
}

void Bomba::initvariables()
{

}

Bomba::~Bomba()
{

}

void Bomba::update()
{
	this->bomba.move(0, 10.f);
	if (this->bomba.getPosition().y > 500)
		bomba.setRotation(45);
}

void Bomba::render(sf::RenderTarget* target)
{
	target->draw(this->bomba);
}