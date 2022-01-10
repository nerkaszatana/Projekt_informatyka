#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#define MAX_LICZBA_POZIOMOW 4

class Menu
{
private:
	sf::Font font;
	sf::Text menu[MAX_LICZBA_POZIOMOW];
	int selectedItem = 0;
public:
	Menu(float width, float height);
	~Menu() {};
	void przesunG();
	void przesunD();
	int getSelectedItem() {return selectedItem;}
	void draw(sf::RenderWindow& window);
};

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("Nowa gra");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 1));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Pomoc");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Wyniki");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 3));
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Wyjscie");
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 4));
	
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::przesunG()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem >= MAX_LICZBA_POZIOMOW)
		{
			selectedItem = 0;
		}
		if (selectedItem < 0)
		{
			selectedItem = 3;
		}
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}

void Menu::przesunD()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= MAX_LICZBA_POZIOMOW)
		{
			selectedItem = 0;
		}
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}

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
	sf::RenderWindow* window;
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
	std::vector<sf::RectangleShape> Zbierajki;
	sf::RectangleShape Zbierajka;
	sf::RectangleShape Line;
	sf::RectangleShape Line1;
	sf::RectangleShape Line2;
	sf::RectangleShape Line3;
	sf::RectangleShape Line4;
	Samochod samochod;
};

const bool Gra::uruchomiona() const
{
	return this->window->isOpen();
}

Gra::Gra()
{
	this->initVariables();
	this->initWindow();
	this->initZbierajka();
	this->initline();
}

Gra::~Gra()
{
	delete this->window;
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
	this->samochod.render(this->window);
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

class Samochod
{
public:
	Samochod();
	void update();
	void render(sf::RenderTarget* target);
	//void przesunL(float x_in, float y_in);
	//void przesunP(float x_in, float y_in);
	sf::Sprite getSamochod();
	bool czy_osiagnieto_koniec;
private:
	sf::Vector2f position;
	float xVel = 1.f, Yvel = 1.f;
	sf::Texture AutoCzerwTexture;
	sf::Sprite Auto_Czerw;
	void initVariables();
	void initShape();

};

void Samochod::initShape()
{
	sf::Texture AutoCzerwTexture;
	AutoCzerwTexture.loadFromFile("Sam_Czerw.jpg");
	sf::Sprite Auto_Czerw(AutoCzerwTexture, sf::IntRect(0, 0, 80, 80));
	Auto_Czerw.setPosition(100.0f, 300.0f);
}

void Samochod::initVariables()
{

}

Samochod::Samochod()
{
	this->initVariables();
	this->initShape();

	//position.x = x_in;
	//position.y = y_in;
	//AutoCzerwTexture.loadFromFile("Sam_Czerw.jpg");
	//Auto_Czerw.setTexture(AutoCzerwTexture);
	//Auto_Czerw.setPosition(position);
	//this->init();
}

sf::Sprite Samochod::getSamochod() {
	return Auto_Czerw;
}

void Samochod::render(sf::RenderTarget* target)
{
	target->draw(this->Auto_Czerw);
}

void Samochod::update()
{

}

//class Collision
//{
//	Collision(sf::RectangleShape& body);
//	~Collision();
//
//	bool CheckCollision(Collision& other);
//	sf::Vector2f GetPosition() { return body.getPosition(); }
//	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
//};



void myDelay(int opoznienie)
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

class Pomoc
{
public:
	Pomoc();
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape oknopomoc;
	sf::Texture* tekstura = new sf::Texture;
};


void Pomoc::draw(sf::RenderWindow& window)
{
	window.draw(oknopomoc);
}

Pomoc::Pomoc()
{
	oknopomoc.setPosition(0, 0);
	oknopomoc.setSize({800,600});
	tekstura->loadFromFile("pomoc.png");
	oknopomoc.setTexture(tekstura);
}

int main()
{
	Pomoc pomoc;
	int menu_selected_flag = 0;
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 1000), "GRA Menu");
	Menu menu(window.getSize().x, window.getSize().y);
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					myDelay(150);
					menu.przesunG();
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					myDelay(150);
					menu.przesunD();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					myDelay(150);
					menu_selected_flag = 0;
				}
				if (menu_selected_flag == 0)
				{
					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 0)
					{
						menu_selected_flag = 1;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1)
					{
						menu_selected_flag = 2;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2)
					{
						menu_selected_flag = 3;
					}
					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3)
					{
							exit(0);
					}
				}
			}
			window.clear();
			if (menu_selected_flag == 0)
			{
				window.clear();
				menu.draw(window);
			}
			if (menu_selected_flag == 1)
			{
				menu_selected_flag == 0;
				Gra gra;
				while (gra.uruchomiona())
				{
					gra.update();
					gra.render();
				}
				////while (window.isOpen())
				//{
				//	//Gra gra; //jest ok bo nowe okno robi
				//	//gra.render();
				//	//gra.update();
				//	sf::Texture tekstura;
				//	tekstura.loadFromFile("bomba.png");
				//	sf::Sprite bomba(tekstura, sf::IntRect(0, 0, 80, 80));

				//	sf::Texture AutoCzerwTexture;
				//	AutoCzerwTexture.loadFromFile("Sam_Czerw.jpg");
				//	sf::Sprite Auto_Czerw(AutoCzerwTexture, sf::IntRect(0, 0, 80, 80));
				//	Auto_Czerw.setPosition(100.0f, 800.0f);

				//	sf::Texture AutoNiebTexture;
				//	AutoNiebTexture.loadFromFile("Sam_Nieb.jpg");
				//	sf::Sprite Auto_Nieb(AutoNiebTexture, sf::IntRect(0, 0, 80, 80));
				//	Auto_Nieb.setPosition(620.0f, 800.0f);
				//}

		//		while (window.isOpen())
		//		{
		//			sf::Event evnt;
		//			if (evnt.type == sf::Event::Closed)
		//			{
		//				window.close();
		//			}
		//			if (evnt.key.code == sf::Keyboard::Escape)
		//			{
		//				window.clear();
		//				menu_selected_flag = 0;
		//				menu.draw(window);
		//			}
		//			window.display();

		//			while (Gra.pollEvent(event))
		//			{
		//				window.clear();
		///*				window.draw(bomba);
		//				window.draw(Auto_Czerw);
		//				window.draw(Auto_Nieb);*/
		//				window.display();
		//			}
		//		}
			}
			if (menu_selected_flag == 2)
			{
				pomoc.draw(window);
			}
			window.display();
			if (menu_selected_flag == 3)
			{
				window.close();
			}
			if (menu_selected_flag == 4)
			{
				window.close();
			}
		}
	}
	return 0;
}