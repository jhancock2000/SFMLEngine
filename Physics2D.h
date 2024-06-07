#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Physics2D {
public:
	Physics2D();

	bool isEnabled() { return enabled; }

	//setters
	void setSpeed(float s);
	void setMass(float m);
	void setGravity(float g);
	void setVelocity(Vector2f v);
	
	//getters
	float getSpeed() { return speed;}
	float getMass() { return mass; }
	float getGravity() { return gravity; }
	Vector2f getVelocity() { return velocity; }

	bool enabled;
	bool isGrounded;

private:

	float mass;
	float gravity;
	float speed;
	Vector2f velocity;
};