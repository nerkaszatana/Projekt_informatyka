#pragma once
#include "Player.h"
#include "Player2.h"
#include "Pomoc.h"
#include "Bomba.h"
#include "Zbierajka.h"
#include "Zbierajka2.h"
#include "Kolizja.h"
#include "Pomoc2.h"

class Gra
{
public:
	void pollEvents();
	void update();
	void render();
	Gra();
	~Gra();
	const bool uruchomiona() const;
	void updateZbierajka();
	void updateZbierajka2();
	void updateBomba();
	void updateCollision();
	int selectedItem {};
	Player* player;
	Player2* player2;
	Pomoc2* pomoc2;
	bool Skret = false;
	bool Skret2 = false;
	bool czystop = false;
private:
	sf::Event evnt;
	sf::Event e;
	sf::Event ew;
	sf::VideoMode videomode;
	int punkty;
	float ZbierajkaSpawnTimer;
	float ZbierajkaSpawnTimer2;
	float ZbierajkaSpawnTimerMax;
	int MaxZbierajka;
	float BombaSpawnTimer;
	float BombaSpawnTimerMax;
	int MaxBomba;
	void initPomoc2();
	void initVariables();
	void initWindow();
	void initBomba();
	void initZbierajka();
	void initZbierajka2();
	void initline();
	void initPlayer();
	std::vector<Bomba*> bomby;
	std::vector<Zbierajka*> Zbierajki;
	std::vector<Zbierajka2*> Zbierajki2;
	sf::RectangleShape Line;
	sf::RectangleShape Line1;
	sf::RectangleShape Line2;
	sf::RectangleShape Line3;
	sf::RectangleShape Line4;
	sf::RenderWindow* window;
	sf::RenderWindow* winndow;
	sf::RenderWindow* window3;
};

