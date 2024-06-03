#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Physics2D.h"
using namespace sf;
Game::Game() {

    gameObject = GameObject({20, 20}, {20, 20}, "Player", "Player");
	gameObjects.push_back(gameObject);
	//player = Player(obj);

	if (gameObject.getTag() == "Player") {
		player = Player(gameObject);
		player.gameObject.physics.enabled = true;
		player.gameObject.physics.setSpeed(100);
		
	}
}

Game::~Game() {

}

void Game::init(const char* title, const int W, const int H) {
	window.create(sf::VideoMode(W, H), title);

	isRunning = true;
}

void Game::events() {
	
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == Event::Closed) {
			window.close();
		}
		if (e.type == Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				//gameObjects[0].setPos({ gameObjects[0].getPos().x + 100, gameObjects[0].getPos().y});
				cout << gameObjects[0].getTag() << endl;
				player.up();
				cout << player.gameObject.physics.getSpeed() << endl;
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
	//window.draw(gameObjects.at(0).obj);
	window.draw(player.gameObject.obj);
	//window.draw();
	window.display();

}
