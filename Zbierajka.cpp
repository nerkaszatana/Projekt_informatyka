#include "Zbierajka.h"

Zbierajka::Zbierajka(float posX, float posY)
{
	this->zbierajka.setPosition(
		static_cast<float>(rand() % static_cast<int>(0, 300) + 60),
		0.f
	);
	this->initshape();
	this->initvariables();
}

void Zbierajka::initshape()
{
	this->zbierajka.setSize(sf::Vector2f(50.f, 50.f));
	this->zbierajka.setFillColor(sf::Color::Green);
	this->zbierajka.setOutlineColor(sf::Color::Magenta);
	this->zbierajka.setOutlineThickness(2.f);
}

void Zbierajka::initvariables()
{

}

Zbierajka::~Zbierajka()
{

}

void Zbierajka::update()
{
	this->zbierajka.move(0, 10.f);
	if (this->zbierajka.getPosition().y > 500)
		zbierajka.setRotation(45);
}

void Zbierajka::render(sf::RenderTarget* target)
{
	target->draw(this->zbierajka);
}
