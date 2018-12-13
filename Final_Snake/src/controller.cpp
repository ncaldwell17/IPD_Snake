#include "controller.h"
#include <iostream>

using namespace snake;
using namespace ge211;


namespace snake {

    snake::Controller::Controller()
            : model_(), view_(model_) {}

    ge211::Dimensions Controller::initial_window_dimensions() const {
        return view_.screen_dimensions();
    }

    std::string Controller::initial_window_title() const {
        return "SNAKE SNAKE SNAKE";
    }

    void Controller::draw(ge211::Sprite_set & set) {
        view_.draw(set);
    }

    void Controller::on_key(ge211::Key key) {
        if(model_.get_state()==Game_State::game_over){
            return;
        }

        if(key == Key::up()){
            model_.move_snake(Direction::up);
        }
        else if(key == Key::down()){
            model_.move_snake(Direction::down);
        }
        else if(key == Key::left()){
            model_.move_snake(Direction::left);
        }
        else if(key == Key::right()){
            model_.move_snake(Direction::right);
        }
    }

    void Controller::on_frame(double last_frame_seconds) {
        if(model_.get_state()==Game_State::game_over){
            return;
        }

        model_.update(last_frame_seconds);
    }


}
