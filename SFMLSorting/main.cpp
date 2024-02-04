// SFMLSorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <algorithm>

using namespace std;

const int numBlocks = 100;
const int maxBlockHeight = 500;
const int minBlockHeight = 50;
const int blockWidth = 50;
const int screenWidth = 800;
const int screenHeight = 600;
bool isSorted = false;
int blocks[numBlocks];

void randomBars() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Sorting");
	// Create an array of blocks
	

	// Generate random block heights
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(minBlockHeight, maxBlockHeight);
	for (int i = 0; i < numBlocks; i++) {
		blocks[i] = dis(gen);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		// Drawing
		window.clear(sf::Color::Black);

		for (int i = 0; i < numBlocks; i++) {
			sf::RectangleShape rect(sf::Vector2f(blockWidth, blocks[i]));
			rect.setPosition(i * blockWidth, screenHeight - blocks[i]);
			window.draw(rect);
		}

		window.display();
		sf::sleep(sf::seconds(1));


	}
}



int main()
{

	randomBars();
}
