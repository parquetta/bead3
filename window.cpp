#include "window.hpp"

using namespace std;
using namespace genv;

void Window::run()
{
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i = 0; i < _widgets.size(); i++)
            {
                if (_widgets[i] -> is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus != -1)
        {
            _widgets[focus] -> handle(ev);
        }
        gout << move_to(0, 0) << color(255, 255, 255) << box(_size_x, _size_y);
        for (size_t i = 0; i < _widgets.size(); i++)
        {
            _widgets[i] -> draw();
        }
        gout << refresh;
    }
}

void Window::action(string id) {

}

void Window::add(Widget * w)
{
    _widgets.push_back(w);
}
