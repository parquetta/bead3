#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "static_text.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;
using namespace genv;

const int XX = 309;
const int YY = 400;

class MyWindow : public Window
{
protected:
    vector<vector<int> > numbers;
    vector<vector<Static*> > sudoku;
    int column;
    int row;
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
                Static * square = new Static(this, 70+i*19, 50+j*19, 20, 20, "", 0, 0, 0);
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
        for (int i = 0; i < sudoku.size(); i++)
        {
            for (int j = 0; j < sudoku[i].size(); j++)
            {
                sudoku[i][j] -> setColor(0, 0, 0);
            }
        }

        if(tag == "1")
        {
            numbers[row][column] = 1;
        }
        if(tag == "2")
        {
            numbers[row][column] = 2;
        }
        if(tag == "3")
        {
            numbers[row][column] = 3;
        }
        if(tag == "4")
        {
            numbers[row][column] = 4;
        }
        if(tag == "5")
        {
            numbers[row][column] = 5;
        }
        if(tag == "6")
        {
            numbers[row][column] = 6;
        }
        if(tag == "7")
        {
            numbers[row][column] = 7;
        }
        if(tag == "8")
        {
            numbers[row][column] = 8;
        }
        if(tag == "9")
        {
            numbers[row][column] = 9;
        }

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

        is_correct();

    }

    void is_correct()
    {
        //oszlop ellenõrzés
        vector<bool> errors(numbers.size(), false);
        for(int i = 0; i < numbers.size(); i++)
        {
            for(int j = 0; j < numbers[i].size(); j++)
            {
                for(int k = j+1; k < numbers[i].size(); k++)
                {
                    if(numbers[i][j] > 0 && numbers[i][j] == numbers[i][k])
                    {
                        errors[numbers[i][j] - 1] = true;
                    }
                }
            }
            for(int l = 0; l < numbers[i].size(); l++)
            {
                if(numbers[i][l] > 0 && errors[numbers[i][l] - 1])
                {
                    sudoku[i][l] -> setColor(255, 0, 0);
                }
            }
            for(int m = 0; m < errors.size(); m++)
            {
                errors[m] = false;
            }
        }

        //sorok ellenorzese
        for(int j = 0; j < numbers.size(); j++)
        {
            for(int i = 0; i < numbers[j].size(); i++)
            {
                for(int k = i+1; k < numbers[j].size(); k++)
                {
                    if(numbers[i][j] > 0 && numbers[i][j] == numbers[k][j])
                    {
                        errors[numbers[i][j] - 1] = true;
                    }
                }
            }
            for(int l = 0; l < numbers.size(); l++)
            {
                if(numbers[l][j] > 0 && errors[numbers[l][j] - 1])
                {
                    sudoku[l][j] -> setColor(255, 0, 0);
                }
            }
            for(int m = 0; m < errors.size(); m++)
            {
                errors[m] = false;
            }
        }

        //3x3-as blokkok ellenőrzése
        for(int i = 0; i < numbers.size()/3; i++)
        {
            for(int j = 0; j < numbers[i].size()/3; j++)
            {
                for(int k = numbers.size()/3*i; k < numbers.size()/3*i + numbers.size()/3; k++)
                {
                    for(int l = numbers[i].size()/3*j; l < numbers[i].size()/3*j + numbers[i].size()/3; l++)
                    {
                        for(int m = numbers.size()/3*i; m < numbers.size()/3*i + numbers.size()/3; m++)
                        {
                            for(int n = numbers[i].size()/3*j; n < numbers[i].size()/3*j + numbers[i].size()/3; n++)
                            {
                                if((k != m && l != n) && numbers[k][l] > 0 && numbers[k][l] == numbers[m][n])
                                {
                                    errors[numbers[k][l] - 1] = true;
                                }
                            }
                        }
                    }
                }
                for(int k = numbers.size()/3*i; k < numbers.size()/3*i + numbers.size()/3; k++)
                {
                    for(int l = numbers[i].size()/3*j; l < numbers[i].size()/3*j + numbers[i].size()/3; l++)
                    {
                        if(numbers[k][l] > 0 && errors[numbers[k][l] - 1])
                        {
                            sudoku[k][l] -> setColor(255, 0, 0);
                        }
                    }
                }
                for(int m = 0; m < errors.size(); m++)
                {
                    errors[m] = false;
                }
            }
        }
    }


    void run()
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
            if(focus < 81)
            {
                column = focus%9;
                row = floor(focus / 9);
            }
            if (focus != -1)
            {
                _widgets[focus] -> handle(ev);
            }
            gout << move_to(0, 0) << color(255, 255, 255) << box(XX, YY);
            for (size_t i = 0; i < _widgets.size(); i++)
            {
                _widgets[i] -> draw();
            }
            gout << refresh;
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
