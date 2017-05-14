#include "button.hpp"

using namespace std;
using namespace genv;

void Button::draw()
{
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << color(230, 230, 230) << box(_size_x-2, _size_y-2);
    gout << move_to(_x+_size_x/2-gout.twidth(_text)/2, _y+gout.cascent()+(_size_y-gout.cascent()-4)/2) << color(0, 0, 0) << text(_text);
}

void Button::handle(event ev)
{
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        action();
    }
}

void Button::action()
{
    _app -> action(_tag);
}
