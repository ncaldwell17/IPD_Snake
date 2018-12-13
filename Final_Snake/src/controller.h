#pragma once

#include "model.h"
#include "view.h"
#include <ge211.h>

namespace snake {
class Controller : public ge211::Abstract_game
{
public:
    explicit Controller();

protected:
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;

    void draw(ge211::Sprite_set&) override;

    void on_key(ge211::Key key) override;

    void on_frame(double last_frame_seconds) override;

private:
    Model model_;
    View view_;
};
}