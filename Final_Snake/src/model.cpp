#include "model.h"
#include <iostream>
#include <ge211.h>
#include <math.h>

namespace snake{
    Model::Model()
    : apple({AppleType::safe,{SCREEN_WIDTH/2,SCREEN_HEIGHT/2}}),
    current_direction(Direction::right)
    {
        //pushing in three body parts
        //right now the vector is empty, so now our vector will have three snake body structs
        for(int i = 0; i<3;i++){
            snake_body.push_back({BodyPart::body,{0.0,0.0},Direction::right});
        }
//giving literal coordinates (multiples of 10) for objects
        snake_body[0].type = BodyPart::head;
        // irregular coordinate system b/c of pixel size
        snake_body[0].curr_position = {CEllSIZE*4, SCREEN_HEIGHT-2*CEllSIZE};

        snake_body[1].type = BodyPart::body;
        snake_body[1].curr_position = {CEllSIZE*3, SCREEN_HEIGHT-2*CEllSIZE};

        snake_body[2].type = BodyPart::tail;
        snake_body[2].curr_position = {CEllSIZE*2, SCREEN_HEIGHT-2*CEllSIZE};

    }

    void Model::move_snake(Direction input){

        if(current_direction == Direction::up and input == Direction::down){
            return;
        }
        else if(current_direction == Direction::down and input == Direction::up){
            return;
        }
        else if(current_direction == Direction::right and input == Direction ::left){
            return;
        }
        else if(current_direction == Direction::left and input == Direction ::right){
            return;
        }
        current_direction = input;
    }

    bool Model::edge(){
        bool check = false;

        if(snake_body[0].curr_position.y < 0 and
            current_direction==Direction::up){
            check = true;
        }else if(snake_body[0].curr_position.y > SCREEN_HEIGHT-CEllSIZE
        and current_direction==Direction::down){
            check = true;
        }else if(snake_body[0].curr_position.x > SCREEN_WIDTH-CEllSIZE
                 and current_direction==Direction::right){
            check = true;
        }else if(snake_body[0].curr_position.x < 0
                 and current_direction==Direction::left){
            check = true;
        }
        return check;
    }

    bool Model::eat_apple(){
        return snake_body[0].curr_position.x < apple.apple_pos.x + CEllSIZE and
       snake_body[0].curr_position.x+CEllSIZE>apple.apple_pos.x and
       snake_body[0].curr_position.y < apple.apple_pos.y + CEllSIZE and
       snake_body[0].curr_position.y + CEllSIZE > apple.apple_pos.y;
    }

    void Model::spawn_apple(){

        auto newtype = AppleType ::safe;
        if(rand()%2==0){
            newtype = AppleType ::unsafe;
        }
        apple = {newtype,{fmod(rand(),SCREEN_WIDTH),fmod(rand(),SCREEN_HEIGHT)}};

    }

    bool Model::bite_self(){

        for(int i = 1; i<snake_body.size();i++){
            if(snake_body[0].curr_position.x < snake_body[i].curr_position.x + CEllSIZE and
               snake_body[0].curr_position.x+CEllSIZE>snake_body[i].curr_position.x and
               snake_body[0].curr_position.y < snake_body[i].curr_position.y + CEllSIZE and
               snake_body[0].curr_position.y + CEllSIZE > snake_body[i].curr_position.y
               and snake_body[0].body_direction != snake_body[i].body_direction){
                return true;
            }
        }
        return false;
    }

    void Model::update(double dt){

        std::cout<<"\nI entered the update function\n";

        if(current_state == Game_State::game_over){
            std::cout<<"\n I am ending the game\n";
            return;
        }
         auto change = snake_speed_ * dt;
        //will give displacement of snake as a function of dt, as well as based on the snake's direction, will move accordingly
         auto curr_body_position = snake_body[0].curr_position;

         if(current_direction==Direction::right){
             std::cout<<"\n Entering first if branch\n";
             snake_body[0].curr_position.x+=change;
         }
         else if(current_direction==Direction::left){
             std::cout<<"\n Entering second if branch\n";
             snake_body[0].curr_position.x-=change;
         }else if(current_direction==Direction::up){
             std::cout<<"\n Entering third if branch\n";
             snake_body[0].curr_position.y-=change;
         }else if(current_direction==Direction::down){
             std::cout<<"\n Entering final if branch\n";
             snake_body[0].curr_position.y+=change;
         }
        //updates all the positions for all body parts, not updating it properly so that's why it's all going into one
         for(int i = 1; i<snake_body.size();i++){
             std::cout<<"\n Entered body update loop\n";
             auto prev_body_position = snake_body[i].curr_position;
             snake_body[i].curr_position = curr_body_position;
             curr_body_position = prev_body_position;
         }
            //on each frame, I'm checking whether or not the snake has bitten itself or hits the edge
         if((bite_self())or(edge())){
             std::cout<<"\nBite Self value is"<<bite_self()<<"\n";
             std::cout<<"\nEdge value is"<<edge()<<"\n";

             std::cout<<"\n Snake has bitten itself or hit the wall\n";
             current_state = Game_State::game_over;
         }
            //each frame also checks whether or not I've eaten the apple
         if(eat_apple()){
             std::cout<<"\n Snake has eaten apple\n";
              if(apple.apple_type == AppleType::safe){
                  snake_speed_ = snake_speed_+ 100;
                  score = score + 10;
              }
              else{
                  if(snake_speed_ > 50) {
                      snake_speed_ = snake_speed_ - 50;
                      score -= 5;
                  }
              }
              spawn_apple();
         }

    }

}
