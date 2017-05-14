#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"

class Number : public Widget
{
protected:
    int _mini, _maxi, _number;
public:
    Number(int x, int y, int sx, int sy, int mini, int maxi);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void get_number(std::ofstream& f);
};

#endif // NUMBER_HPP_INCLUDED
