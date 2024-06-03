#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "Physics2D.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, const int W, const int H); //this is just gonna be the init
	void events(); //event handler
	void update(); //idk what this is for yet
	void draw(); //rendering

	bool running() { return isRunning; }

private:
	bool isRunning; //private so I can set it in the pointer class
	sf::RenderWindow window;
	std::vector<GameObject> gameObjects;
	Player player;
	GameObject gameObject;
	Physics2D physics2D;

};
