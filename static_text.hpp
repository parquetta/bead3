#ifndef STATIC_TEXT_HPP_INCLUDED
#define STATIC_TEXT_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

class Static : public Widget {
protected:
    string _s;
public:
    Static(Window * app, int x, int y, int sx, int sy, string s) : Widget(app, x, y, sx, sy), _s(s) {}
    void draw();
    void action();
    void setS(string newS);
};

#endif // STATIC_TEXT_HPP_INCLUDED
