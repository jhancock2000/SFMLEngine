#include "Input.h"

Input::Input() {
	//intentionally blank
}

Input::Input(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::D) {
		player.right();
	}
	if (key == sf::Keyboard::A) {
		player.left();
	}
	if (key == sf::Keyboard::W) {
		player.up();
	}
	if (key == sf::Keyboard::S) {
		player.down();
	}
}