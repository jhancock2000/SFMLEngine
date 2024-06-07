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
			gameObjects[i]->physics.isGrounded = false;
			gameObjects[i]->physics.setMass(24);
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
	//all very broken movement code. just here for testing my collisions
	while (window.pollEvent(e)) {
		if (e.type == Event::Closed) {
			window.close();
		}
		if (e.type == Event::KeyPressed) {
			if (e.key.code == input.Left()) {
				player.left();
			}
			if (e.key.code == input.Right()) {
				player.right();
			}
			if (e.key.code == input.Up()) {
				player.up();
			}
			if (e.key.code == input.Down()) {
				player.down();
			}
		}
		if (e.type == Event::KeyReleased) {
			player.gameObject.physics.setVelocity({ 0, 0 });
			player.gameObject.physics.setGravity(1);
		}
	}
}

void Game::update() {
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->physics.isEnabled() && !gameObjects[i]->physics.isGrounded) {
			gameObjects[i]->obj.move({ gameObjects[i]->physics.getVelocity().x, gameObjects[i]->physics.getGravity() * gameObjects[i]->physics.getMass() / 10});

		}
		else if (gameObjects[i]->physics.isEnabled() && gameObjects[i]->physics.isGrounded) {
			gameObjects[i]->obj.move(gameObjects[i]->physics.getVelocity());
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
