#pragma once
#include <SFML/Graphics.hpp>
class Bomba
{
private:
	sf::ConvexShape bomba;
	void initvariables();
	void initshape();
public:
	Bomba(float posX, float posY);
	virtual ~Bomba();
	void update();
	void render(sf::RenderTarget* target);
};

