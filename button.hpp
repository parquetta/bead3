#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

class Button : public Widget {
protected:
    string _tag;
    string _text;

public:
    Button(Window * app, int x, int y, int sx, int sy, string tag, string txt) : Widget(app, x, y, sx, sy), _tag(tag), _text(txt) {}
    void draw();
    void handle(event ev);
    void action();
};

#endif // BUTTON_HPP_INCLUDED
