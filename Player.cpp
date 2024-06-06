#include "Player.h";
#include "GameObject.h";

Player::Player() {
	//default consturctor
	
}

Player::Player(GameObject player) {
	this->gameObject = player;
}

void Player::up() {
	gameObject.physics.setVelocity({ 0, -25 });
	cout << gameObject.getPos().x << " " << gameObject.getPos().y << endl;
}

void Player::down() {
	gameObject.physics.setVelocity({ 0, 25 });
	//cout << gameObject.physics.getVelocity().x << endl;
}

void Player::right() {
	gameObject.physics.setVelocity({ 25, 0 });
	//cout << gameObject.physics.getVelocity().x << endl;
	//g
}

void Player::left() {
	gameObject.physics.setVelocity({ -25, 0 });
	//cout << gameObject.physics.getVelocity().x << endl;
}