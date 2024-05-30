#include "Game.h"
#include "GameObject.h"
using namespace sf;

GameObject obj;
Game::Game() {

	obj = GameObject({20, 20}, {20, 20}, "Player");
	gameObjects.push_back(obj);
}

Game::~Game() {

}

void Game::init(const char* title, const int W, const int H) {
	window.create(sf::VideoMode(W, H), title);

	isRunning = true;
	//shape.setFillColor(sf::Color::Green);
}

void Game::events() {
	
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == Event::Closed) {
			window.close();
		}
		if (e.type == Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				gameObjects[0].setPos({ gameObjects[0].getPos().x + 100, gameObjects[0].getPos().y});
				cout << gameObjects[0].getTag() << endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				gameObjects[0].setTag("Player");
			}
		}
	}
}

void Game::update() {

}

void Game::draw() {
	window.clear();
	window.draw(gameObjects.at(0).obj);
	window.display();

}
