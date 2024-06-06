#pragma once
#include "Includes.h";


class Textures {
public:
	Textures();

	sf::Texture* setTexture(string t);

private:
	sf::Texture tex;
};
