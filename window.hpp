#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

using namespace std;

class Widget;

class Window {
protected:
    vector<Widget*> _widgets;
    int _size_x, _size_y;
public:
    Window(int x, int y) : _size_x(x), _size_y(y) {}
    void run();
    virtual void action(string id);
    virtual void add(Widget * w);

};

#endif // WINDOW_HPP_INCLUDED
