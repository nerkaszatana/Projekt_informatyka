#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Game.cpp"
#include "SamochodCzerwony.h"
#include "SamochodNiebieski.h"

class Gra
{
public:
		void pollEvents();
		void update();
		void render();
		Gra();
		~Gra();
		const bool uruchomiona() const;
		void spawnZbierajka();
		void updateZbierajki();
		void renderZbierajki();
		int selectedItem = 1;
		Player1* player1;
		Player2* player2;
private:
		sf::Event evnt;
		sf::VideoMode videomode;
		int punkty;
		float ZbierajkaSpawnTimer;
		float ZbierajkaSpawnTimerMax;
		int MaxZbierajka;
		void initVariables();
		void initWindow();
		void initZbierajka();
		void initline();
		void initPlayer1();
		void initPlayer2();
		std::vector<sf::RectangleShape> Zbierajki;
		sf::RectangleShape Zbierajka;
		sf::RectangleShape Line;
		sf::RectangleShape Line1;
		sf::RectangleShape Line2;
		sf::RectangleShape Line3;
		sf::RectangleShape Line4;
		sf::RenderWindow* window;
};

