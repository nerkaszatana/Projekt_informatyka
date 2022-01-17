#pragma once
#include <SFML/Graphics.hpp>
class Zbierajka
{
private:
	sf::RectangleShape zbierajka;
	void initvariables();
	void initshape();
public:
	Zbierajka(float posX, float posY);
	virtual ~Zbierajka();
	void update();
	void render(sf::RenderTarget* target);
};

