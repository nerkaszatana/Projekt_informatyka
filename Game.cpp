#include "Game.h"


const bool Gra::uruchomiona() const
{
	return this->window->isOpen();
}

Gra::Gra()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer1();
	this->initPlayer2();
	this->initZbierajka();
	this->initline();
}

Gra::~Gra()
{
	delete this->window;
	delete this->player1;
}

void Gra::updateZbierajki()
{
	if (this->Zbierajki.size() < this->MaxZbierajka)
	{
		if (this->ZbierajkaSpawnTimer >= this->ZbierajkaSpawnTimerMax)
		{
			this->spawnZbierajka();
			this->ZbierajkaSpawnTimer = 0.f;
		}
		else
			this->ZbierajkaSpawnTimer++;
	}
	for (auto& e : this->Zbierajki)
	{
		e.move(0.f, 5.f);
	}
	for (auto& e : this->Zbierajki)
	{
		this->window->draw(e);
	}
}

void Gra::renderZbierajki()
{
	for (auto& e : this->Zbierajki)
	{
		this->window->draw(e);
	}
}

void Gra::spawnZbierajka()
{
	this->Zbierajka.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->Zbierajka.getSize().x)),
		0.f
	);
	this->Zbierajka.setFillColor(sf::Color::Green);
	this->Zbierajki.push_back(this->Zbierajka);
}

void Gra::initPlayer1()
{
	this->player1 = new Player1();
}

void Gra::initPlayer2()
{
	this->player2 = new Player2();
}

void Gra::initVariables()
{
	this->window = nullptr;
	this->punkty = 0;
	this->ZbierajkaSpawnTimerMax = 1000.f;
	this->ZbierajkaSpawnTimer = this->ZbierajkaSpawnTimerMax;
	this->MaxZbierajka = 3;
}

void Gra::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1000), "GRA v.01", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Gra::update()
{
	this->pollEvents();
	this->updateZbierajki();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player1->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player1->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player2->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player2->move(1.f, 0.f);
}

void Gra::render()
{
	this->window->clear();
	this->window->draw(this->Line);
	this->window->draw(this->Line1);
	this->window->draw(this->Line2);
	this->window->draw(this->Line3);
	this->window->draw(this->Line4);
	this->window->draw(this->Zbierajka);
	this->renderZbierajki();
	this->player1->render(*this->window);
	this->player2->render(*this->window);
	this->window->display();
}

void Gra::pollEvents()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (this->evnt.type)
		{
		case sf::Event::Closed:
			this->window->close();
			selectedItem = 0;
			break;
		case sf::Event::KeyPressed:
			if (this->evnt.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				selectedItem = 0;
				break;
			}
		}
	}
}

void Gra::initZbierajka()
{
	this->Zbierajka.setSize(sf::Vector2f(50.f, 50.f));
	this->Zbierajka.setFillColor(sf::Color::Red);
	this->Zbierajka.setOutlineColor(sf::Color::Magenta);
	this->Zbierajka.setOutlineThickness(2.f);
}

void Gra::initline()
{
	this->Line.setSize(sf::Vector2f(10.f, 1000.f));
	this->Line.setPosition(50.f, 0.f);
	this->Line1.setSize(sf::Vector2f(10.f, 1000.f));
	this->Line1.setPosition(390.f, 0.f);
	this->Line2.setSize(sf::Vector2f(10.f, 1000.f));
	this->Line2.setPosition(740.f, 0.f);
	this->Line3.setSize(sf::Vector2f(1.f, 1000.f));
	this->Line3.setPosition(215.f, 0.f);
	this->Line4.setSize(sf::Vector2f(1.f, 1000.f));
	this->Line4.setPosition(565.f, 0.f);
}