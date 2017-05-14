#include "widgets.hpp"
#include "graphics.hpp"
#include "number.hpp"
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;

Number::Number(int x, int y, int sx, int sy, int mini, int maxi) : Widget(x, y, sx, sy), _mini(mini), _maxi(maxi), _number(mini) {}

bool Number::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x > _x && mouse_x < _x + _size_x && mouse_y > _y && mouse_y < _y + _size_y;
}

void Number::draw(){
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255, 255, 255) << box(_size_x-4, _size_y-4);
    gout << move_to(_x + _size_x - (_size_y/2), _y) << color(0, 0, 0) << box(2, _size_y);
    gout << move_to(_x + _size_x - (_size_y/2), _y + (_size_y / 2)-1) << color(0, 0, 0) << box(_size_y/2, 2);
    gout << move_to(_x + _size_x - (_size_y/2)+1, _y + _size_y/2) << color(0, 0, 0) << line(_size_y/4, -_size_y/2);
    gout << line(_size_y/4, _size_y/2);
    gout << move_to(_x + _size_x - (_size_y/2)+1, _y + _size_y/2) << color(0, 0, 0) << line(_size_y/4, _size_y/2);
    gout << line(_size_y/4, -_size_y/2);
    stringstream ss;
    ss << _number;
    gout << move_to(_x+5, _y+gout.cascent()+(_size_y-gout.cascent()-4)/2) << color(0, 0, 0) << text(ss.str());
}

void Number::handle(event ev) {
    if(ev.type == ev_key && (ev.keycode == key_down) && _number > _mini) {
        _number --;
    }
    if(ev.type == ev_key && (ev.keycode == key_up) && _number < _maxi){
        _number ++;
    }
    if(ev.type == ev_key && (ev.keycode == key_pgdn) && _number >= _mini+10) {
        _number -= 10;
    }
    if(ev.type == ev_key && (ev.keycode == key_pgup) && _number <= _maxi-10){
        _number += 10;
    }
    if(ev.type == ev_mouse && ev.button == btn_left && _x + _size_x - (_size_y/2) < ev.pos_x && ev.pos_x < _x + _size_x && _y < ev.pos_y && ev.pos_y < _y + (_size_y/2)-1 && _number < _maxi) {
        _number ++;
    }
    if(ev.type == ev_mouse && ev.button == btn_left && _x + _size_x - (_size_y/2) < ev.pos_x && ev.pos_x < _x + _size_x && _y + (_size_y/2)-1 < ev.pos_y && ev.pos_y < _y + _size_y && _number > _mini) {
        _number --;
    }
}

void Number::get_number(ofstream& f) {
    stringstream ss;
    ss << _number;
    f << ss.str() << endl;
}
