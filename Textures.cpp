#include "Textures.h"

Textures::Textures() {
	//intentional
}

sf::Texture* Textures::setTexture(string t) {
	tex.loadFromFile(t);
	return &tex;
}