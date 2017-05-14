#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "number.hpp"
#include "menu.hpp"
#include "button.hpp"
#include "static_text.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
using namespace genv;

const int XX = 309;
const int YY = 400;

class MyWindow : public Window
{
protected:
    vector<vector<int> > numbers;
    vector<vector<Static*> > sudoku;
public:
    MyWindow(int x, int y) : Window(x, y)
    {
        numbers.resize(9);
        sudoku.resize(9);

        for(int i = 0; i < numbers.size(); i++)
        {
            numbers[i].resize(9);
        }

        ifstream f;
        f.open("sudoku1.txt");
        if(!f.good())
        {
            cerr << ":(";
            exit(-1);
        }

        for(int i = 0; i < numbers.size(); i++)
        {
            for(int j = 0; j < numbers[i].size(); j++)
            {
                int num;
                f >> num;
                if (num > 0) numbers[i][j] = num;
            }
            }

            for(int i = 0; i < numbers.size(); i++)
            {
                for(int j = 0; j < numbers[i].size(); j++)
                {
                    Static * square = new Static(this, 70+i*19, 50+j*19, 20, 20, "");
                    sudoku[i].push_back(square);
                }
            }
            action("init");

            for(int i = 0; i < 9; i++)
            {
                stringstream ss;
                ss << i+1;
                Button * numberset = new Button(this, 70+i*19, 230, 20, 20, ss.str(), ss.str());
            }

        }
        void action(string tag)
        {
            for(int i = 0; i < numbers.size(); i++)
            {
                for(int j = 0; j < numbers[i].size(); j++)
                {
                    if (numbers[i][j] > 0)
                    {
                        stringstream ss;
                        ss << numbers[i][j];
                        sudoku[i][j] -> setS(ss.str());
                    }
                }
            }

        }

    };

    int main()
    {
        gout.open(XX, YY);

        MyWindow * my = new MyWindow(XX, YY);
        my -> run();

        return 0;
    }
