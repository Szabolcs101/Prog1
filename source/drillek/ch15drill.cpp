/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};


int main()
{
    using namespace Graph_lib;

    constexpr int xmax = 600;
    constexpr int ymax = 600;

    constexpr int x_orig = 300;
    constexpr int y_orig = 300;

    constexpr int x_scale = 20;
    constexpr int y_scale = 20;

    constexpr int x_length = 400;
    constexpr int y_length = 400;



    Simple_window win{Point{100,100}, xmax, ymax, "Function graphs"};

    Axis x {Axis::x,Point{100,y_orig},
            x_length, x_length/x_scale, "one_notch == 20"};
            x.set_color(Color::red);
    Axis y {Axis::y,Point{x_orig,y_length+100},
            y_length, y_length/y_scale, "one_notch == 20"};
            y.set_color(Color::red);


    int rmin = -11;
    int rmax = 10;
    int n_points = 400;
    Point origo {x_orig, y_orig};
    int xscale = 20;
    int yscale = 20;
    
    Function s1(one, rmin, rmax, origo, n_points, xscale, yscale);
    Function s2(slope, rmin, rmax, origo, n_points, xscale, yscale);
    Function s3(square, rmin, rmax, origo, n_points, xscale, yscale); 
    Function s4(cos, rmin, rmax, origo, n_points, xscale, yscale); 

    
    Text ts {Point{80, y_orig+85}, "x/2"};

    win.attach(x);
    win.attach(y);

    win.attach(s1);
    win.attach(s2);
    win.attach(s3);
    win.attach(ts);
    win.attach(s4);
    

    win.wait_for_button();
};
