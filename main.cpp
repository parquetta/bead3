#include "graphics.hpp"
#include "widgets.hpp"
#include "number.hpp"
#include "menu.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets, vector<Number*> n, vector<Menu*> m, ofstream& f)
{
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        gout << move_to(0, 0) << color(230, 230, 230) << box(400, 400);
        gout << move_to(10, 50) << color(0, 0, 0) << text("Press S to save");

        if(ev.type == ev_key && ev.keycode == 's')
        {
            for(size_t i = 0; i < n.size(); i++)
            {
                n[i] -> get_number(f);

            }
            for(size_t i = 0; i < m.size(); i++)
            {
                m[i] -> get_text(f);

            }

        }
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i = 0; i < widgets.size(); i++)
            {
                if (widgets[i] -> is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus != -1)
        {
            widgets[focus] -> handle(ev);
        }
        for (size_t i = 0; i < widgets.size(); i++)
        {
            widgets[i] -> draw();
        }
        gout << refresh;
    }
}

int main()
{
    gout.open(400,400);
    ofstream f("test.txt");
    if(f.bad())
    {
        cout << "error" << endl;
    }
    vector<Widget*> w;
    vector<Number*> n;
    vector<Menu*> m;
    vector<string> o1;
    o1.push_back("First");
    o1.push_back("Second");
    o1.push_back("Third");
    o1.push_back("Fourth");
    vector<string> o2;
    o2.push_back("Test1");
    o2.push_back("Test2");
    o2.push_back("Test3");
    o2.push_back("Test4");
    o2.push_back("Test5");
    Number * n1 = new Number(10, 100, 60, 30, 5, 250);
    Number * n2 = new Number(200, 100, 60, 30, 10, 500);
    n.push_back(n1);
    n.push_back(n2);
    Menu * m1 = new Menu(10, 200, 120, 30, o1);
    Menu * m2 = new Menu(200,200, 120, 30, o2);
    m.push_back(m1);
    m.push_back(m2);
    w.push_back(n1);
    w.push_back(n2);
    w.push_back(m1);
    w.push_back(m2);
    event_loop(w, n, m, f);
    f.close();
    return 0;
}
