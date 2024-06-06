#pragma once
#include "GameObject.h";

class Player {
public:
	Player(); //default
	Player(GameObject player);

	
	void up();
	void down();
	void left();
	void right();

	GameObject gameObject;
private:
	Vector2f v;
};