#include <iostream>
#include "graphics.h"


using namespace std;

class Point{
    int x;
    int y;

public:
    Point(){
        x=0;
        y=0;
    }
    Point(int n1, int n2){
        x=n1;
        y=n2;
    }

    Point(int n){
        x=y=n;
    }

    Point(Point& p){
        this->x=p.x;
        this->y=p.y;

    }
    void set_x(int n){
        x=n;
    }
    void set_y(int n){
        y=n;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }

};

class Circle{
    Point center;
    int rad;
public:
    Circle(){
        rad=0;
    }

    Circle(int x, int y, int r):center(x, y){
        rad=r;
    }

    void setCenter(int x, int y){
        center.set_x(x);
        center.set_y(y);
    }

    void getCenter(int &x, int&y){
        x=center.get_x();
        y=center.get_y();
    }

    Point getCenter_point(){
        Point cent = center;
        return cent;
    }
    void draw(){

    circle(center.get_x(), center.get_y(), rad);

    };



};

class Rec{
Point UL;
Point LR;

public:
    Rec(){};

    Rec(int x1, int y1, int x2, int y2):UL( x1,  y1), LR(x2,  y2){};

    void setUL(int x1, int y1){
        UL.set_x(x1);
        UL.set_y(y1);
    }
    void setLR(int x2, int y2){
        LR.set_x(x2);
        LR.set_y(y2);
    }

    void getUL(int &x1, int &y1){
        x1=UL.get_x();
        y1=UL.get_y();
    }

    void getLR(int &x2, int &y2){
        x2=LR.get_x();
        y2=LR.get_y();
    }

    Point getUL_point(){
        Point upperLeftPoint=UL;
        return upperLeftPoint;
        }

    Point getLR_point(){
        Point lowerRightPoint=UL;
        return lowerRightPoint;
        }

    void draw(){
        rectangle(350,350,460,450);
    };
};

class Line{
Point p1;
Point p2;

public:
    Line(){};

    Line(int x1, int y1, int x2, int y2):p1( x1,  y1), p2( x2,  y2){};

        void set_point1(int x1, int y1){
        p1.set_x(x1);
        p1.set_y(y1);
    }
    void set_point2(int x2, int y2){
        p2.set_x(x2);
        p2.set_y(y2);
    }

    void get_point1(int &x1, int &y1){
        x1=p1.get_x();
        y1=p1.get_y();
    }

    void get_point2(int &x2, int &y2){
        x2=p2.get_x();
        y2=p2.get_y();
    }

    Point getPoint1_point(){
        Point point_1=p1;
        return point_1;
        }

    Point getPoint2_point(){
        Point point_2=p1;
        return point_2;
        }

    void draw();


};
int main()
{

initgraph();
//===================================Circle========================================
    Circle c1, c2(250,250, 35);
    Point c;
    int c_x, c_y;
    c1.getCenter(c_x, c_y);
    c=c2.getCenter_point();
    cout<<"c_x: "<<c_x<<"  "<<"c_y: "<<c_y<<endl;
    c_x=c.get_x(), c_y=c.get_y();
    cout<<"c_x: "<<c_x<<"  "<<"c_y: "<<c_y<<endl;

    c2.draw();
//===================================Rectangle========================================
    Rec r1, r2(85,150,360,250);
    Point UL, LR, r;
    int ul_x, ul_y, lr_x, lr_y;
    r1.getUL(ul_x, ul_y);
    r1.getLR(lr_x, lr_y);

    cout<<"Upper Left Point: ("<<ul_x<<", "<<ul_y<<")"<<endl;
    cout<<"Lower Right Point: ("<<ul_x<<", "<<ul_y<<")"<<endl;

    r1.setUL(45,96);
    r1.setLR(85,120);

    r1.getUL(ul_x, ul_y);
    r1.getLR(lr_x, lr_y);

    cout<<"Upper Left Point: ("<<ul_x<<", "<<ul_y<<")"<<endl;
    cout<<"Lower Right Point: ("<<lr_x<<", "<<lr_y<<")"<<endl;

    r2.draw();
//===================================Point========================================
    Line p1, p2(500,500,850,850);


    return 0;
}
