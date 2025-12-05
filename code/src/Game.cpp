#include "Game.h"

Game::Game() {
    // Initialization
    //--------------------------------------------------------------------------------------
    screenWidth = WINDOW_WIDTH;
    screenHeight = WINDOW_HEIGHT;
    game_title = "Vampire Survivors Game!!";

    InitWindow(screenWidth, screenHeight, game_title.c_str());

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
}

Game::~Game() {}

void Game::Run() {
    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText(game_title.c_str(), 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}