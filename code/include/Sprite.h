#pragma once

#include <string>

#include "raylib.h"


class Sprite {
protected:
    Texture2D spr_tex;
    Rectangle src_rect;
    Rectangle dest_rect;

public:
    Sprite(std::string texture_path, Rectangle src_rect);
    ~Sprite();


    int Set_Sprite_Texture(std::string texture_path);
    int Set_Source_Rectangle(Rectangle src_rect);
    int Set_Destination_Rectangle(Rectangle dest_rect);

    Texture2D* Get_Sprite_Texture();
    int Get_Source_Rectangle();
    int Get_Destination_Rectangle();

    int Kill_Sprite();
};
