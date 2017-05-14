#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "number.hpp"
#include "menu.hpp"
#include "button.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;

const int XX = 600;
const int YY = 600;

class MyWindow : public Window {
protected:

public:
    MyWindow(int x, int y) : Window(x, y)
    {

    }
    void action(string tag)
    {

    }
};

int main()
{
    gout.open(XX, YY);

    MyWindow * my = new MyWindow(XX, YY);
    my -> run();

    return 0;
}
