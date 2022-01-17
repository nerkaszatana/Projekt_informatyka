#include "Zbierajka2.h"

Zbierajka2::Zbierajka2(float posX, float posY)
{
	this->zbierajka2.setPosition(
		static_cast<float>(rand() % static_cast<int>(0, 300) + 410),
		0.f
	);
	this->initshape();
	this->initvariables();
}

void Zbierajka2::initshape()
{
	this->zbierajka2.setSize(sf::Vector2f(50.f, 50.f));
	this->zbierajka2.setFillColor(sf::Color::Blue);
	this->zbierajka2.setOutlineColor(sf::Color::Magenta);
	this->zbierajka2.setOutlineThickness(2.f);
}

void Zbierajka2::initvariables()
{

}

Zbierajka2::~Zbierajka2()
{

}

void Zbierajka2::update()
{
	this->zbierajka2.move(0, 10.f);
	if (this->zbierajka2.getPosition().y > 500)
		zbierajka2.setRotation(45);
}

void Zbierajka2::render(sf::RenderTarget* target)
{
	target->draw(this->zbierajka2);
}
