#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Physics2D.h"
#include "Textures.h"
#include "Input.h"
using namespace sf;
Game::Game() {

	gameObject = GameObject({ 175, 20 }, { 100, 200 }, "Player", "Player");
	player = Player(gameObject);
	gameObjects.push_back(&player.gameObject);

	gameObject = GameObject({ 100, 500 }, { 300, 50 }, "Wall1", "Wall");
	gameObjects.push_back(&gameObject);

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->getTag() == "Player") {

			gameObjects[i]->physics.enabled = true;
			gameObjects[i]->physics.setGravity(1);
			gameObjects[i]->physics.setSpeed(100);
			//gameObjects[i]->obj.setTexture(player.gameObject.textures.setTexture("Textures/file.png"));

		}

		if (gameObjects[i]->getTag() == "Wall") {
			gameObjects[i]->physics.enabled = false;
			gameObjects[i]->obj.setTexture(gameObjects[i]->textures.setTexture("Textures/floor.jpg"));
		}
	}

}

Game::~Game() {

}

void Game::init(const char* title, const int W, const int H) {
	window.create(sf::VideoMode(W, H), title);
	window.setFramerateLimit(60); //WOW FRAMERATE DEPENDANT PHYSICS IS THAT EASY.....THIS WILL BREAK IF GAME LAGS BTW...REFACTOR IN THE FUTURE

	isRunning = true;
}

void Game::events() {

	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == Event::Closed) {
			window.close();
		}
		if (e.type == Event::KeyPressed) {
			Input(e.key.code);
		}
	}
}

void Game::update() {
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->physics.isEnabled()) {
			gameObjects[i]->obj.move({ gameObjects[i]->physics.getVelocity().x, gameObjects[i]->physics.getGravity()});

		}
	}
}

void Game::draw() {
	window.clear();
	//window.draw(gameObjects.at(0).obj);
	//window.draw(player.gameObject.obj);

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		window.draw(gameObjects[i]->obj);
	}
	//window.draw();
	window.display();

}
