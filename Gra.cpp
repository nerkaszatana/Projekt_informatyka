#include "Gra.h"
#include<stdlib.h>
#include<iostream>

const bool Gra::uruchomiona() const
{
	return this->window->isOpen();
}

Gra::Gra()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initPomoc2();
	this->initZbierajka();
	this->initZbierajka2();
	this->initBomba();
	this->initline();
}

Gra::~Gra()
{
	delete this->window;
	delete this->winndow;
	delete this->window3;
	delete this->player;
	delete this->player2;
	delete this->pomoc2;
	for (auto* i : this->bomby)
	{
		delete i;
	}
	for (auto *k : this->Zbierajki)
	{
		delete k;
	}
	for (auto *m : this->Zbierajki2)
	{
		delete m;
	}
}

void Gra::initPlayer()
{
	this->player = new Player();
	this->player2 = new Player2();
}

void Gra::initVariables()
{
	this->punkty = 0;
	this->ZbierajkaSpawnTimerMax = 100.f;
	this->ZbierajkaSpawnTimer = this->ZbierajkaSpawnTimerMax;
	this->ZbierajkaSpawnTimer2 = this->ZbierajkaSpawnTimerMax;
	this->MaxZbierajka = 30;
}

void Gra::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1000), "GRA v.01", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Gra::update()
{
		this->pollEvents();
		this->updateZbierajka();
		this->updateZbierajka2();
		this->updateBomba();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Skret == true)
		{
			Skret = false;
			for (int i = 0; i < 55; i++)
			{
				this->player->przesun(-1.f, 0.f);

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Skret == false)
		{
			Skret = true;
			this->player->przesun(55.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Skret2 == false)
		{
			Skret2 = true;
			this->player2->przesun(-55.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Skret2 == true)
		{
			Skret2 = false;
			this->player2->przesun(55.f, 0.f);
		}
		if (this->evnt.key.code == sf::Keyboard::F1)
		{
			//this->pomoc2->przesun(0.f, 10.f);
			
		}
}

void Gra::initPomoc2()
{
	this->pomoc2 = new Pomoc2();
}

void Gra::updateBomba()
{
	this->BombaSpawnTimer += 2.f;
	if (this->BombaSpawnTimer >= this->BombaSpawnTimerMax)
	{
		this->bomby.push_back(new Bomba(0, (rand() % 700) + 50));
		this->BombaSpawnTimer = 0.f;
	}
	for (int i = 0; i < this->bomby.size(); ++i)
	{
		this->bomby[i]->update();
		//for (size_t k = 0; k < this->bomby.size(); k++)
		//{
		//	if (this->bomby[k].getBounds().intersects(player->getShape()));
		//}
	}
}

void Gra::updateZbierajka()
{
	this->ZbierajkaSpawnTimer += 1.f;
	if (this->ZbierajkaSpawnTimer >= this->ZbierajkaSpawnTimerMax)
	{
		this->Zbierajki.push_back(new Zbierajka(rand() % (0, 300) +50, 0));
		this->ZbierajkaSpawnTimer = 0.f;
	}
	for (int i = 0; i < this->Zbierajki.size(); ++i)
	{
		this->Zbierajki[i]->update();
		//for (size_t i = 0; i < this->Zbierajki.size(); i++)
		//{
		//	if (this->Zbierajki[i].getBounds().intersects(this->player->getShape()));
		//}
	}
}

void Gra::updateZbierajka2()
{
	this->ZbierajkaSpawnTimer2 += 1.f;
	if (this->ZbierajkaSpawnTimer2 >= this->ZbierajkaSpawnTimerMax)
	{
		this->Zbierajki2.push_back(new Zbierajka2(rand() % (400, 700) +50, 0));
		this->ZbierajkaSpawnTimer2 = 0.f;
	}
	for (int i = 0; i < this->Zbierajki2.size(); ++i)
	{
		this->Zbierajki2[i]->update();
	}
}

void Gra::initBomba()
{
	this->BombaSpawnTimerMax = 100.f;
	this->BombaSpawnTimer = this->BombaSpawnTimerMax;
}

void Gra::initZbierajka()
{
	this->ZbierajkaSpawnTimerMax = 100.f;
	this->ZbierajkaSpawnTimer = this->ZbierajkaSpawnTimerMax;
}

void Gra::initZbierajka2()
{
	this->ZbierajkaSpawnTimerMax = 100.f;
	this->ZbierajkaSpawnTimer2 = this->ZbierajkaSpawnTimerMax;
}

void Gra::render()
{
	this->window->clear();
	this->window->draw(this->Line);
	this->window->draw(this->Line1);
	this->window->draw(this->Line2);
	this->window->draw(this->Line3);
	this->window->draw(this->Line4);
	this->player->render(*this->window);
	this->player2->render(*this->window);
	this->pomoc2->render(*this->window);
	for (auto* bomba : this->bomby)
	{
		bomba->render(this->window);
	}
	for (auto* zbierajka : this->Zbierajki)
	{
		zbierajka->render(this->window);
	}
	for (auto* zbierajka2 : this->Zbierajki2)
	{
		zbierajka2->render(this->window);
	}
	this->window->display();
}

void mydelay(int opoznienie)
{
	sf::Clock zegar;
	sf::Time czas;
	while (1)
	{
		czas = zegar.getElapsedTime();
		if (czas.asMilliseconds() > opoznienie)
		{
			zegar.restart();
			break;
		}
	}
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
					sf::Event e;
					winndow = new sf::RenderWindow(sf::VideoMode(600, 600), "chcesz wyjsc", sf::Style::Titlebar | sf::Style::Close);
					selectedItem = 0;
					mydelay(3000);
					while (this->winndow->pollEvent(this->e))
					{
						switch (this->e.type)
						{
						case sf::Event::Closed:
							this->winndow->close();
							selectedItem = 0;
							
						case sf::Event::KeyPressed:
							if (this->e.key.code == sf::Keyboard::Escape)
							{
								this->winndow->close();
								selectedItem = 0;
								
							}
						}
					}
				}
			if (this->evnt.key.code == sf::Keyboard::F1)
			{
				this->pomoc2->przesun(0.f, 0.f);
			}
			if (this->evnt.key.code == sf::Keyboard::F2)
			{
				this->pomoc2->przesun(0.f, -600.f);
				mydelay(3000);
			}



				//this->pomoc2->przesun(0.f, -600.f);sssss
				/*sf::Event ew;
				window3 = new sf::RenderWindow(sf::VideoMode(800, 600), "przypomnienie sterowania", sf::Style::Titlebar | sf::Style::Close);
				selectedItem = 0;*/
				
				//mydelay(3000);
				/*while (this->window3->pollEvent(this->ew))
				{
					switch (this->ew.type)
					{
					case sf::Event::Closed:
						this->window3->close();
						selectedItem = 0;

					case sf::Event::KeyPressed:
						if (this->ew.key.code == sf::Keyboard::Escape)
						{
							this->window3->close();
							selectedItem = 0;

						}
					}
				}*/
			
		}
	}
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