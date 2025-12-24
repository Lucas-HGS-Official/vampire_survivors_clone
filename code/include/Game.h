#pragma once


#include <string>
#include "raylib.h"

#include "Settings.h"


class Game {
public:
    int screenWidth;
    int screenHeight;
    std::string game_title;

    Game();

    ~Game();

    void Run();
};