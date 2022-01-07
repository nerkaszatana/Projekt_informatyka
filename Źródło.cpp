#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

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
private:
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::VideoMode videomode;
	void initVariables();
	void initWindow();
	void initZbierajka();
	sf::RectangleShape Zbierajka;
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
}

Gra::~Gra()
{
	delete this->window;
}

void Gra::initVariables()
{
	this->window = nullptr;
}

void Gra::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1000), "GRA v.01", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Gra::update()
{
	this->pollEvents();
}

void Gra::render()
{
	this->window->clear();
	this->window->draw(this->Zbierajka);
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
			break;
		case sf::Event::KeyPressed:
			if (this->evnt.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
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

class Zbierajka
{
public:
	sf::RectangleShape zbierajka;
	void initVariables();
	void initZbierajka();
	void render();
	void initWindow();
};

void Zbierajka::initZbierajka()
{
	this->zbierajka.setPosition(0.f, 0.f);
	this->zbierajka.setSize(sf::Vector2f(100.f, 100.f));
	this->zbierajka.setFillColor(sf::Color::Red);
	this->zbierajka.setOutlineColor(sf::Color::Magenta);
	this->zbierajka.setOutlineThickness(2.f);
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
	Zbierajka zbierajka;
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
//bool Collision::CheckCollision(Collision& other)
//{
//	return false;
//}
