#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

using namespace std;
using namespace genv;

class Menu : public Widget {
protected:
    vector<string> _options;
    bool if_selected = false;
    string text1 = "Choose...";
public:
    Menu(int x, int y, int sx, int sy, vector<string> options);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw();
    virtual void handle(genv::event ev);
    //virtual void add_option();
    virtual void get_text(std::ofstream& f);
};

#endif // MENU_HPP_INCLUDED
