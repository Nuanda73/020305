//a jobb alsó sarokból mozogjon és a bal felsőbe érkezzen

/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp chapter13.cpp `fltk-config --ldflags --use-images` -o ch13
*/

#include "GUI/Graph.h"
#include "GUI/Simple_window.h"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace Graph_lib;

int main(){
    try{
        Point t1(300,50);
        Simple_window win(t1,1000,800, "My window");

        Lines grid;
        int x_size = 800;
        int y_size = 800;

        for(int i=100; i<=x_size; i+=100){
            grid.add(Point(i,0), Point(i,y_size));
            grid.add(Point(0,i), Point(x_size,i));
        }
        win.attach(grid);

        /*
        new Rectangle(Point(0,0),100,100);
        vector<Rectangle*> vi

        for(i...8){
        v.pushback (new Rectangle {Point{i*100, i*100}, 100, 100})
        v[v.size()-1].set_fill_color(Color::red);
        win.attach(v[v.size()-1]);
        }
        */

        /*for(int i=1; i<9;i++){
        Rectangle r {Point{i*100, i*100}, 100, 100};
        win.attach(r);
        r.set_fill_color(Color::dark_red);
        }*/

        for(int i = 0; i < x_size; i+=100){
            Rectangle *kocka = new Rectangle(Point{i,i},Point{i+100,i+100});
            kocka->set_fill_color(Color::red);
            win.attach(*kocka);
        }

        win.wait_for_button();

        Image kep1 (Point(200,0),"kep.jpg");
        win.attach(kep1);
        Image kep2 (Point(500,200),"kep.jpg");
        win.attach(kep2);
        Image kep3 (Point(100,500),"kep.jpg");
        win.attach(kep3);

        while (true)
        {
            static int x=700, y=700;
            static int kattszam=0;

            Image kep4 (Point(x,y),"kep.jpg");
            kep4.set_mask(Point(0,0),100,100);
            win.attach(kep4);

            if(kattszam<7){
                x-=100;
                kattszam++;
            }else{
                x=700;
                y-=100;
                kattszam=0;
            }
            win.wait_for_button();
        }


    }catch(exception& e){
        cerr << "exception: " << e.what() << endl;
        return 1;
    }catch(...){
        cerr << "exception\n";
        return 2;
    }
}