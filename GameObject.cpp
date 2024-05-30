#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::GameObject(sf::Vector2f pos, sf::Vector2f size, string name) {
	position = pos;
	this->size = size;
	this->name = name;
	this->tag = "gameObject";

	obj.setSize(sf::Vector2f(size));
	obj.setPosition(sf::Vector2f(position));
}

GameObject::GameObject(sf::Vector2f pos, sf::Vector2f size, string name, string tag) {
	position = pos;
	this->size = size;
	this->name = name;
	this->tag = tag;

	obj.setSize(sf::Vector2f(size));
	obj.setPosition(sf::Vector2f(position));
}

GameObject::~GameObject() {

}

sf::Vector2f GameObject::getPos() {
	return position;
}

sf::Vector2f GameObject::getSize() {
	return size;
}

void GameObject::setPos(sf::Vector2f pos) {
	obj.setPosition(sf::Vector2f(pos));
	position = pos;
}

void GameObject::setSize(sf::Vector2f s) {
	obj.setSize(sf::Vector2f(s));
	size = s;
}

void GameObject::setTag(string tag) {
	this->tag = tag;
}