#pragma once

#include <SFML/Graphics.hpp>

namespace Collision
{
	bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
	bool singlePixelTest(const sf::Sprite& Object1, sf::Vector2f& mousePosition, sf::Uint8 AlphaLimit);
	bool CreateTextureAndBitmask(sf::Texture& LoadInto, const std::string& Filename);
	bool CircleTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
	bool BoundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
}
