#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "window.hpp"
#include <fstream>

class Window;

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    Window * _app;
public:
    Widget(Window * app, int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw();
    virtual void handle(genv::event ev);
};


#endif // WIDGETS_HPP_INCLUDED
