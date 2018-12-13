#pragma once

#include <ge211.h>
#include <vector>

namespace snake {

const double SCREEN_WIDTH = 500;
const double SCREEN_HEIGHT = 500;

const double CEllSIZE = 10;


enum class Direction{
    up, down, left, right
    //movements of snake
};

enum class BodyPart{
    head,body,tail
};
//using enum class just to avoid mistake Jesse called out (the four ints)
//makes code more readable
enum class AppleType{
    safe,unsafe
};


enum class Game_State {
        in_play, game_over
    };

//different data types
//declared outside of class so I could access it easily instead of using a get function in the view
//and to test
    struct Snake{
        BodyPart type;
        ge211::Basic_position<double> curr_position;
        Direction body_direction;
    };

    struct Apple{
        AppleType apple_type;
        ge211::Basic_position<double> apple_pos;

    };


    class Model {
    public:
        //this is the constructor for model
        explicit Model();
        //this moves the snake in a direction
        void move_snake(Direction);
        //this updates the snake's position with time
        //dt = a time which is of type double
        void update(double dt);
        //finds whether or not the snake hits the edge
        bool edge();
        //finds whether or not the snake bites itself (didn't get used b/c ...)
        bool bite_self();
        //collision function which tells whether or not the snake head hit the apple
        //has other attributes associated like what to do with the snake
        //increases score/decreases speed, etc.
        bool eat_apple();
        //how to regenerate a random apple, etc.
        void spawn_apple();
        //get function for the view
        std::vector<Snake> get_snake_body(){
            return snake_body;
        }
        //returns state of the game
        Game_State get_state(){
            return current_state;
        }
        //returns apple attributes
        Apple get_apple(){
            return apple;
        }
        //returns the current direction of the snake
        //used for testing
        Direction get_current_direction(){
            return current_direction;
        }

    private:

        Game_State current_state = Game_State::in_play;
        std::vector<Snake> snake_body;


        Apple apple;
        Direction current_direction;
        size_t score = 0;
        //affects snake speed
        double snake_speed_ = 50;


    };


};