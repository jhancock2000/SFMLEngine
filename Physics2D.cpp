#include "Physics2D.h"

Physics2D::Physics2D() {
	if (!isEnabled()) {
		speed = 0;
		mass = 0;
		velocity = { 0, 0 };
		gravity = 0;
	}
}

void Physics2D::setSpeed(float s) {
	speed = s;
}

void Physics2D::setGravity(float g) {
	gravity = g;
}

void Physics2D::setMass(float m) {
	mass = m;
}

void Physics2D::setVelocity(Vector2f v) {
	velocity = v;
}