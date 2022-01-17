#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Gra.h"
#include "Pomoc.h"
#include<stdlib.h>

#define MAX_LICZBA_POZIOMOW 4
#define MAX_LICZBA_POZIOMOW_TRUDNOSCI 2

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

class Menu_wybor
{
private:
	sf::Font font;
	sf::Text menu_wybor[MAX_LICZBA_POZIOMOW_TRUDNOSCI];
	int selectedItem1 = 0;
public:
	Menu_wybor(float width, float height);
	~Menu_wybor() {};
	void przesunGora();
	void przesunDol();
	int getSelectedItem1() { return selectedItem1; }
	void draw(sf::RenderWindow& window);
};

Menu_wybor::Menu_wybor(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	menu_wybor[0].setFont(font);
	menu_wybor[0].setFillColor(sf::Color::Cyan);
	menu_wybor[0].setString("Easy");
	menu_wybor[0].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW_TRUDNOSCI + 1) * 1));
	menu_wybor[1].setFont(font);
	menu_wybor[1].setFillColor(sf::Color::White);
	menu_wybor[1].setString("Udreka 13");
	menu_wybor[1].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW_TRUDNOSCI + 1) * 2));
}

void Menu_wybor::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW_TRUDNOSCI; i++)
	{
		window.draw(menu_wybor[i]);
	}
}

void Menu_wybor::przesunGora()
{
		menu_wybor[selectedItem1].setFillColor(sf::Color::White);
		menu_wybor[selectedItem1].setStyle(sf::Text::Regular);
		selectedItem1--;
		if (selectedItem1 >= MAX_LICZBA_POZIOMOW_TRUDNOSCI)
		{
			selectedItem1 = 0;
		}
		if (selectedItem1 < 0)
		{
			selectedItem1 = 1;
		}
		menu_wybor[selectedItem1].setFillColor(sf::Color::Cyan);
		menu_wybor[selectedItem1].setStyle(sf::Text::Bold);
}

void Menu_wybor::przesunDol()
{
		menu_wybor[selectedItem1].setFillColor(sf::Color::White);
		menu_wybor[selectedItem1].setStyle(sf::Text::Regular);
		selectedItem1++;
		if (selectedItem1 >= MAX_LICZBA_POZIOMOW_TRUDNOSCI)
		{
			selectedItem1 = 0;
		}
		menu_wybor[selectedItem1].setFillColor(sf::Color::Cyan);
		menu_wybor[selectedItem1].setStyle(sf::Text::Bold);
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


int main()
{
	int menu_selected_flag = 0;
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 1000), "GRA Menu");
	Menu menu(window.getSize().x, window.getSize().y);
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event) && menu_selected_flag == 0)
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
					window.close();
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

		}
			if (menu_selected_flag == 0)
			{
				window.clear();
				menu.draw(window);
			}
			if (menu_selected_flag == 1)
			{
				window.clear();
				myDelay(150);
				Menu_wybor menu_wybor(window.getSize().x, window.getSize().y);
				menu_wybor.draw(window);
				while (window.pollEvent(event) && menu_selected_flag == 1)
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
							menu_wybor.przesunGora();
						}
						if (event.key.code == sf::Keyboard::Down)
						{
							myDelay(150);
							menu_wybor.przesunDol();
						}
						if (event.key.code == sf::Keyboard::Escape)
						{
							myDelay(150);
							menu_selected_flag = 0;
						}
						if (menu_selected_flag == 1)
						{
							if (event.key.code == sf::Keyboard::Enter && menu_wybor.getSelectedItem1() == 0)
							{
								Gra gra;
								gra.selectedItem = 0;
								menu_selected_flag = 0;
								while (gra.uruchomiona())
								{
									gra.update();
									gra.render();
								}
							}
							if (event.key.code == sf::Keyboard::Enter && menu_wybor.getSelectedItem1() == 1)
							{
								Gra gra;
								gra.selectedItem = 1;
								menu_selected_flag = 0;
								while (gra.uruchomiona())
								{
									gra.update();
									gra.render();
								}

							}
						}
						
					}
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
				}
			}
			if (menu_selected_flag == 2)
			{
				Pomoc pomoc;
				pomoc.draw(window);
				if (event.key.code == sf::Keyboard::Escape)
				{
					menu_selected_flag = 0;
				}
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
	return 0;
}