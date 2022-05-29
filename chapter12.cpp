//olimpiai karikák megrajzolása, ha simán rajzolod egyesével Vector_ref nélkül négyes, Vector_ref-fel ötös

/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp chapter12.cpp `fltk-config --ldflags --use-images` -o ch12
*/

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include <string>
#include <iostream>
using namespace Graph_lib;

int main(){
    try{

        Point t1 {100, 100};

        Simple_window win {t1, 640, 400, "My window"};

        /*for (int i = 1; i < 4; i++)
        {
            Circle *c = new Circle {Point{100+(i*80),200},50};
            win.attach(*c);
        }
        for (int i = 1; i < 3; i++)
        {
            Circle *c = new Circle {Point{140+(i*80),275},50};
            c->set_color(Color::red);
            win.attach(*c);
        }*/

        Vector_ref<Circle> c;
        for (int i=0; i< 5; i++ )  {
            if(i<3){
                c.push_back(new Circle(Point((i+1)*150,100),100));
                win.attach(c[c.size()-1]);
            }else{
                c.push_back(new Circle(Point((i-1.5)*150,250),100));
                win.attach(c[c.size()-1]);
            }
        }


        //Circle c {Point{100,200},50};

        //win.attach(c);

        win.wait_for_button();

    } catch (exception& e) {
        cerr << "exception: " << e.what()<< '\n';
        return 1;
    } catch (...) {
        cerr << "error\n";
        return 2;
    }
}