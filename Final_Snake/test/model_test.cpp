#include "model.h"
#include <catch.h>
#include <ge211.h>

using namespace snake;

TEST_CASE("Check if it's initializing")
{
    Model s;
    CHECK(s.get_state() == Game_State::in_play);

    auto apple_pos = s.get_apple();
    CHECK(apple_pos.apple_pos.x == SCREEN_WIDTH/2);
    CHECK(apple_pos.apple_pos.y == SCREEN_HEIGHT/2);

}

TEST_CASE("Gameplay")
{
    Model s;
    s.move_snake(Direction::up);
    CHECK(s.get_current_direction()==Direction::up);
    s.move_snake(Direction::down);
    CHECK(s.get_current_direction()!=Direction::down);

    s.move_snake(Direction::right);
    CHECK(s.get_current_direction()==Direction::right);
    s.move_snake(Direction::left);
    CHECK(s.get_current_direction()!=Direction::left);

    s.move_snake(Direction::down);
    CHECK(s.get_current_direction()==Direction::down);
    s.move_snake(Direction::up);
    CHECK(s.get_current_direction()!=Direction::up);

    s.move_snake(Direction::left);
    CHECK(s.get_current_direction()==Direction::left);
    s.move_snake(Direction::right);
    CHECK(s.get_current_direction()!=Direction::right);
}

TEST_CASE("Hitting the Edge?")
{
    Model s;
    auto old_body = s.get_snake_body();
    s.update(3);
    auto new_body = s.get_snake_body();
    CHECK(old_body[0].curr_position!=new_body[0].curr_position);
    s.move_snake(Direction::down);
    s.update(10);
    CHECK(s.edge()==true);
    CHECK(s.get_state()==Game_State::game_over);
}

TEST_CASE("Bite an Apple")
{
    Model s;
    //need to figure out how many seconds pass before it eats the center apple
    //see if speed reduces w/ bad apple? Tough to test random variables
}

TEST_CASE("Slam into Wall Other than the Bottom")
{
    Model s;
    //need to figure out how many seconds pass before it slams into wall
}

TEST_CASE("Bites itself")
{
    Model s;
    //don't have additional body part generation functionality
}

TEST_CASE("Snake_speed_ doesn't go lower than 50")
{
    Model s;
    //involves a random event that I can't replicate?
}