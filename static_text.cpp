#include "static_text.hpp"

using namespace std;
using namespace genv;

void Static::draw()
{
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << color(230, 230, 230) << box(_size_x-2, _size_y-2);
    gout << move_to(_x+_size_x/2-gout.twidth(_s)/2, _y+gout.cascent()+(_size_y-gout.cascent()-4)/2) << color(_r, _g, _b) << text(_s);
}

void Static::setS(string newS)
{
    _s = newS;
}

void Static::handle(event ev)
{

}

void Static::setColor(int r, int g, int b)
{
    _r = r;
    _g = g;
    _b = b;
}
