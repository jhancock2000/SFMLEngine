#include <SFML/Graphics.hpp>
#include "Game.h"

Game* game = nullptr;
int main()
{
    game = new Game();

    game->init("SFML Game", 1920, 1080);

    while (game->running()) {
        game->events();
        game->update();
        game->draw();
    }
}