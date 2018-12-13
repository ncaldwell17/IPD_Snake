#include "view.h"
#include <iostream>

namespace snake {


    snake::View::View(snake::Model &model)
            : model_(model) {}

    ge211::Dimensions snake::View::screen_dimensions() const {
        return {(int) SCREEN_WIDTH, (int) SCREEN_HEIGHT + 30};
    }

    void snake::View::draw(ge211::Sprite_set &sprites) const {
        for (int i = 0; i < 50; i++){
            for (int j = 0; j < 50; j++){
                if ((i + j) % 2 == 0) {
                    sprites.add_sprite(black_tile, {(int) (j * CEllSIZE), (int) (i * CEllSIZE)}, 1);
                } else {
                    sprites.add_sprite(white_tile, {(int) (j * CEllSIZE), (int) (i * CEllSIZE)}, 1);
                }
            }
        }

        auto curr_snake = model_.get_snake_body();

        for (auto &part : curr_snake) {
            sprites.add_sprite(snake_body_image, {part.curr_position.into<int>()}, 2);
        }

        auto curr_apple = model_.get_apple();

       if(curr_apple.apple_type == AppleType::safe) {
           sprites.add_sprite(apple_image_, {curr_apple.apple_pos.into<int>()}, 2);
       }
       else{
           sprites.add_sprite(poison_apple_, {curr_apple.apple_pos.into<int>()}, 2);
       }
    }
}
