#include "Sprite.h"


Sprite::Sprite(std::string texture_path, Rectangle src_rect) {
    Set_Sprite_Texture(texture_path);
    Set_Source_Rectangle(src_rect);
}

Sprite::~Sprite() {
}



int Sprite::Set_Sprite_Texture(std::string texture_path) {
    this->spr_tex = LoadTexture(texture_path.c_str());

    return 0;
}

int Sprite::Set_Source_Rectangle(Rectangle src_rect) {
    this->src_rect = src_rect;

    return 0;
}

int Sprite::Set_Destination_Rectangle(Rectangle dest_rect) {
    this->dest_rect = dest_rect;

    return 0;
}


Texture2D* Sprite::Get_Sprite_Texture() {
    return &(this->spr_tex);
}

int Sprite::Get_Source_Rectangle() {

    return 0;
}

int Sprite::Get_Destination_Rectangle() {

    return 0;
}

int Sprite::Kill_Sprite() {

    return 0;
}