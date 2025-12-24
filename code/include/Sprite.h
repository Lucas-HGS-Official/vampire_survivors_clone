#pragma once

#include <string>

#include "raylib.h"

#define NUM_MAX_SPRITES 20


class Sprite {
protected:
    Texture2D spr_tex[NUM_MAX_SPRITES];
    Rectangle src_rect[NUM_MAX_SPRITES];
    Rectangle dest_rect[NUM_MAX_SPRITES];

    int free_sprite;
    int current_sprite;

public:
    Sprite();
    ~Sprite();


    int Set_Sprite_Texture(std::string texture_path);
    int Set_Source_Rectangle(Rectangle src_rect);
    int Set_Destination_Rectangle(Rectangle dest_rect, int sprite_index);
    int Set_Current_Sprite(int current_sprite);

    Texture2D* Get_Sprite_Texture(int sprite_index);
    Rectangle Get_Source_Rectangle(int sprite_index);
    Rectangle Get_Destination_Rectangle(int sprite_index);
    int Get_Current_Sprite();

    int Kill_All_Sprites();
};
