#include "Input.h"

Input::Input() {
	//intentionally blank
}

Keyboard::Key Input::Up() {
	return Keyboard::W;
}

Keyboard::Key Input::Down() {
	return Keyboard::S;
}
Keyboard::Key Input::Left() {
	return Keyboard::A;
}
Keyboard::Key Input::Right() {
	return Keyboard::D;
}
Keyboard::Key Input::Jump() {
	return Keyboard::Space;
}