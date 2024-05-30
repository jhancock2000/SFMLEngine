#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace sf;

class GameObject {
public:
	GameObject();
	GameObject(sf::Vector2f pos, sf::Vector2f size, string name);
	GameObject(sf::Vector2f pos, sf::Vector2f size, string name, string tag);
	~GameObject();

	//getters
	sf::Vector2f getPos();
	sf::Vector2f getSize();
	string getName() { return name; }
	string getTag() { return tag; }


	//setters
	void setPos(sf::Vector2f pos);
	void setSize(sf::Vector2f size);
	void setTag(string tag);

	sf::RectangleShape obj;

	//test

private:
	string name;

	string tag;

	sf::Color c = Color::White;

	sf::Vector2f position;
	sf::Vector2f size;



	//Sprite sprite;
	//Texture texture;
};