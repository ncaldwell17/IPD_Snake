#pragma once

#include "model.h"
#include <ge211.h>

namespace snake {

    ge211::Color const grid_square_color_even = ge211::Color::medium_red().lighten(0.7);
    ge211::Color const grid_square_color_odd = ge211::Color::medium_green().lighten(0.7);

    class View {
    public:

        explicit View(Model &);

        void draw(ge211::Sprite_set &) const;

        ge211::Dimensions screen_dimensions() const;

    private:
        Model &model_;

        //game pieces
        ge211::Image_sprite const apple_image_{"apple_image.jpeg"};
        ge211::Image_sprite const snake_body_image{"Snake_bodypart.png"};
        ge211::Image_sprite const poison_apple_{"POISONAPPLEOFDEATH.jpg"};
        //Font of the game
        ge211::Font sans20{"sans.ttf", 25};
        //Text of the Game
        ge211::Text_sprite const loser_title{"You Lose!", sans20};
        ge211::Rectangle_sprite const black_tile = ge211::Rectangle_sprite({(int)CEllSIZE,(int)CEllSIZE},grid_square_color_odd);
        ge211::Rectangle_sprite const white_tile = ge211::Rectangle_sprite({(int)CEllSIZE,(int)CEllSIZE},grid_square_color_even);

    };
}











