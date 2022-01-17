#pragma once
#include <SFML/Graphics.hpp>
class Zbierajka2
{
private:
	sf::RectangleShape zbierajka2;
	void initvariables();
	void initshape();
public:
	Zbierajka2(float posX, float posY);
	virtual ~Zbierajka2();
	void update();
	void render(sf::RenderTarget* target);
};

