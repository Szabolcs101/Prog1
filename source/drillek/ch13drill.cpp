/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int x_max = 800;
    int y_max = 1000;

    Simple_window win{Point{100,100},x_max, y_max, "Canvas"};

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x=x_grid; x<=x_size; x+=x_grid)
        grid.add(Point{x,0},Point{x,y_size});
    for (int y=y_grid; y<=y_size; y+=y_grid)
        grid.add(Point{0,y},Point{x_size,y});



    /*Rectangle rect00 {Point{0,0}, 100, 100};
    rect00.set_fill_color(Color::red);

    Rectangle rect01 {Point{100,100}, 100, 100};
    rect01.set_fill_color(Color::red);

    Rectangle rect02 {Point{200,200}, 100, 100};
    rect02.set_fill_color(Color::red);

    Rectangle rect03 {Point{300,300}, 100, 100};
    rect03.set_fill_color(Color::red);

    Rectangle rect04 {Point{400,400}, 100, 100};
    rect04.set_fill_color(Color::red);

    Rectangle rect05 {Point{500,500}, 100, 100};
    rect05.set_fill_color(Color::red);

    Rectangle rect06 {Point{600,600}, 100, 100};
    rect06.set_fill_color(Color::red);

    Rectangle rect07 {Point{700,700}, 100, 100};
    rect07.set_fill_color(Color::red); */                   //Béna megoldás


    Vector_ref<Rectangle> rec;

    for(int i=0; i<8; ++i){

        rec.push_back(new Rectangle{Point{i*100, i*100},100,100});  //Point{x,y},height,width
        rec[rec.size()-1].set_fill_color(Color::red);
        win.attach(rec[rec.size()-1]);}

    Image img1 {Point{500,100}, "1kep2.jpg"};
    Image img2 {Point{300,600}, "1kep2.jpg"};
    Image img3 {Point{0,300}, "1kep2.jpg"};

    Image img4 {Point{0,0}, "1kep2.jpg"};

    win.attach(grid);

    /*win.attach(rect00);
    win.attach(rect01);
    win.attach(rect02);
    win.attach(rect03);
    win.attach(rect04);
    win.attach(rect05);
    win.attach(rect06);
    win.attach(rect07);*/


    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.attach(img4);

    for (int y=0; y<8; ++y){
        for(int x=0; x<8; ++x){

            win.wait_for_button();
            img4.move(100,0);
        }
        img4.move(-800, 100);

    }
   

    win.wait_for_button();
}