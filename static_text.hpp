#ifndef STATIC_TEXT_HPP_INCLUDED
#define STATIC_TEXT_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

class Static : public Widget {
protected:
    string _s;
    int _r, _g, _b;
public:
    Static(Window * app, int x, int y, int sx, int sy, string s, int r, int g, int b) : Widget(app, x, y, sx, sy), _s(s), _r(r), _g(g), _b(b) {}
    bool _selected;
    void draw();
    void action();
    void handle(genv::event ev);
    void setS(string newS);
    void setColor(int r, int g, int b);
};

#endif // STATIC_TEXT_HPP_INCLUDED
