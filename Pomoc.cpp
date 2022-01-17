#include "Pomoc.h"

void Pomoc::draw(sf::RenderWindow& window)
{
	window.draw(oknopomoc);
}

Pomoc::Pomoc()
{
	oknopomoc.setPosition(0, 0);
	oknopomoc.setSize({ 800,600 });
	tekstura->loadFromFile("pomoc.png");
	oknopomoc.setTexture(tekstura);
}
