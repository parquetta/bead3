#include "widgets.hpp"
#include "graphics.hpp"
#include "menu.hpp"
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;

Menu::Menu(Window * app, int x, int y, int sx, int sy, vector<string> options) : Widget(app, x, y, sx, sy), _options(options){}

bool Menu::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x > _x && mouse_x < _x + _size_x && mouse_y > _y && mouse_y < _y + _size_y;
}

void Menu::draw()
{
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255, 255, 255) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x - _size_y, _y) << color(0, 0, 0) << box(2, _size_y);
    gout << move_to(_x+_size_x - _size_y + 2, _y) << line(_size_y/2 - 1, _size_y);
    gout << line(_size_y/2 - 2, -_size_y);
    gout << move_to(_x+5, _y+gout.cascent()+(_size_y-gout.cascent()-4)/2) << color(0, 0, 0) << text(text1);
    if(if_selected)
    {
        gout << move_to(_x, _y + _size_y) << color(0, 0, 0) << box(_size_x,_size_y * _options.size()+2);
        gout << move_to(_x+2, _y+2+_size_y-2) << color(255, 255, 255) << box(_size_x-4, _size_y * _options.size());
        for(int i = 0; i < _options.size(); i++)
        {
            gout << move_to(_x+5,_y + _size_y + i*_size_y + gout.cdescent() + gout.cascent()) << color(0, 0, 0) << text(_options[i]);
        }
    }
}

void Menu::handle(event ev)
{
    if(ev.button == btn_left && _x+_size_x - _size_y < ev.pos_x && ev.pos_x < _x+_size_x && _y < ev.pos_y && ev.pos_y < _y+_size_y)
    {
        if_selected = !if_selected;
    }
    if(if_selected && ev.button == btn_left && _x < ev.pos_x && ev.pos_x < _size_x+_x && _y+_size_y < ev.pos_y && ev.pos_y < _y+_size_y * _options.size()+_size_y)
    {

        for(int i = 1; i < _options.size()+1; i++)
        {
            if(_y + i*_size_y < ev.pos_y && ev.pos_y < _y+(i+1)*_size_y)
            {
                text1 = _options[i-1];
                if_selected = !if_selected;
            }
        }
    }
}

/*void Menu::add_option(string s)
{
    _options.push_back(s);
}*/

void Menu::get_text(ofstream& f)
{
    f << text1 << endl;
}

