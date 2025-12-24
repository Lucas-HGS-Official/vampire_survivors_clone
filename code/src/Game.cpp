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
    double delta_time = .0f;
    Player player;
    player.Set_Sprite_Texture("resources/images/player/up/0.png");
    player.Set_Source_Rectangle((Rectangle) { 0,0, (float) ((player.Get_Sprite_Texture(0))->height), (float) ((player.Get_Sprite_Texture(0))->width) });

    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        delta_time = GetFrameTime();
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexturePro(*(player.Get_Sprite_Texture(0)), player.Get_Source_Rectangle(0), (Rectangle) { 100,100, 70,70 }, (Vector2) { 0,0 }, 0.f, WHITE);

            DrawText(game_title.c_str(), 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}