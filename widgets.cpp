#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(Window * app, int x, int y, int sx, int sy)
{
    _app = app;
    _x = x;
    _y = y;
    _size_x = sx;
    _size_y = sy;
    _app -> add(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    bool s = mouse_x > _x && mouse_x < _x + _size_x && mouse_y > _y && mouse_y < _y + _size_y;
    _active = s;
    return s;



}

void Widget::draw() {
}

void Widget::handle(event ev) {
}
