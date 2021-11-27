#include <SFML/Graphics.hpp>
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
	int getSelectedItem() { return selectedItem; }
	void draw(sf::RenderWindow& window);
};

class Pomoc
{
public:
	Pomoc();
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape oknopomoc;
	sf::Texture* tekstura = new sf::Texture;
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
	menu[2].setString("Wyjscie");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 3));
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Cyan);
	menu[3].setString("Wyniki");
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
			selectedItem = 0;
		if (selectedItem < 0)
			selectedItem = 3;
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
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}

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





void Pomoc::draw(sf::RenderWindow& window)
{
	window.draw(oknopomoc);
}
Pomoc::Pomoc()
{
	oknopomoc.setPosition(0, 0);
	oknopomoc.setSize({ 800,600 });
	tekstura->loadFromFile("pomoc.png");
	oknopomoc.setTexture(tekstura);
}
int main()
{
	git add <co to za gra.txt>;
	Pomoc pomoc;
	int menu_selected_flag = 0;
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600), "GRA v.01");
	Menu menu(window.getSize().x, window.getSize().y);
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
						exit(0);
					}
				}
			}
		}
		window.clear();
		if (menu_selected_flag == 0)
		{
			menu.draw(window);
		}
		if (menu_selected_flag == 2)
		{
			pomoc.draw(window);
		}
		window.display();
	}
	return 0;
}