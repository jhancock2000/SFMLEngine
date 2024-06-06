#pragma once
#include "Includes.h"
#include "GameObject.h"

class Collision {
public:
	Collision(); //default constructor
	Collision(GameObject player, RectangleShape surface); //collisions between player and surface
	Collision(RectangleShape a, RectangleShape b); //for collisions between 2 surfaces (maybe platforms with gravity)
	Collision(GameObject player, GameObject enemy); //this will be used in the future for player/enemy collisions

	bool isCollide() { return collide; }
private:
	bool collide;
};