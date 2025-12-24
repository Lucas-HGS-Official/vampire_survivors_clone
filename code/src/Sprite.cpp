#include "Sprite.h"


Sprite::Sprite() {
    this->free_sprite = 0;
}

Sprite::~Sprite() {
    this->Kill_All_Sprites();
}



int Sprite::Set_Sprite_Texture(std::string texture_path) {
    this->spr_tex[free_sprite] = LoadTexture(texture_path.c_str());
    this->Set_Source_Rectangle(Rectangle { 0,0, (float) this->spr_tex[free_sprite].height, (float) this->spr_tex[free_sprite].width });
    this->free_sprite++;

    return this->free_sprite -1;
}

int Sprite::Set_Source_Rectangle(Rectangle src_rect) {
    this->src_rect[free_sprite] = src_rect;

    return 0;
}

int Sprite::Set_Destination_Rectangle(Rectangle dest_rect, int sprite_index) {
    this->dest_rect[sprite_index] = dest_rect;

    return 0;
}

int Sprite::Set_Current_Sprite(int current_sprite) {
    this->current_sprite = current_sprite;

    return 0;
}


Texture2D* Sprite::Get_Sprite_Texture(int sprite_index) {
    return &(this->spr_tex[sprite_index]);
}

Rectangle Sprite::Get_Source_Rectangle(int sprite_index) {

    return this->src_rect[sprite_index];
}

Rectangle Sprite::Get_Destination_Rectangle(int sprite_index) {

    return this->dest_rect[sprite_index];
}

int Sprite::Get_Current_Sprite() {

    return this->current_sprite;
}


int Sprite::Kill_All_Sprites() {
    for(int i=0; i<this->free_sprite; i++)
        UnloadTexture(spr_tex[i]);

    return 0;
}