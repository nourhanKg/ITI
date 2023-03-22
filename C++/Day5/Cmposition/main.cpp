#include <iostream>
#include "graphics.h"
using namespace std;

class Point {
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point(Point &p) {
        this->x = p.x;
        this->y = p.y;
    }
    void setx(int);
    void sety(int);
    int getx();
    int gety();
};


class Line {
    Point firstP;
    Point secP;

public:
    Line() {
    }
    Line(int x1, int y1, int x2, int y2):firstP(x1, y1),secP(x2, y2){
    }
    Line(Point f, Point s):firstP(f), secP(s) {
    }
    void setfP(int, int);
    void setsP(int, int);
    void getfP(int &, int &);
    void getsP(int &, int &);
    void draw() {
        line(firstP.getx(), firstP.gety(), secP.getx(), secP.gety());
    }
};


class Rec {
    Point UL;
    Point LR;

public:
    Rec() {
    }
    Rec(int x1, int y1, int x2, int y2):UL(x1, y1),LR(x2, y2){
    }
    Rec(Point ul, Point lr):UL(ul), LR(lr) {
    }
    void setUL(int, int);
    void setLR(int, int);
    void getUL(int &, int &);
    void getLR(int &, int &);
    void draw() {
        rectangle(UL.getx(), UL.gety(), LR.getx(), LR.gety());
    }
};


class Circle {
    int rad;
    Point center;

public:
    Circle() {
        rad = 10;
    }
    Circle(int x, int y, int r):center(x, y) {
        rad = r;
    }
    Circle(Point c, int r):center(c) {
        rad = r;
    }
    void draw() {
        circle(center.getx(), center.gety(), rad);
    }
    void setrad(int);
    void setcent(int, int);
    int getrad();
    void getcent(int &, int &);
};

int main()
{
    initgraph();

    Point p1;
    Point p2(2,3);

    cout <<"Check Points\n"<< endl;
    cout <<p1.getx()<< endl;

    p1.sety(5);
    cout <<p1.gety()<< endl;
    cout <<p2.getx()<< endl;


    cout <<"Check Circles\n"<< endl;
    Circle c1;
    cout <<c1.getrad()<< endl;

    c1.setcent(2,2);
    int n1,n2;
    c1.getcent(n1, n2);
    cout <<n1<<","<<n2<< endl;

    Circle c2(6,6,20);
    cout <<c1.getrad()<< endl;

    c2.getcent(n1, n2);
    cout <<n1<<","<<n2<< endl;

    Circle c3(p2, 5);
    c3.getcent(n1, n2);
    cout <<n1<<","<<n2<< endl;
    cout <<c3.getrad()<< endl;

    cout <<"Check Liness\n"<< endl;
    Line l1(3, 3, 7, 7);
    l1.setfP(1,1);
    l1.getfP(n1, n2);
    cout <<n1<<","<<n2<< endl;
    l1.getsP(n1, n2);
    cout <<n1<<","<<n2<< endl;

    Line l2(p1, p2);
    l2.getfP(n1, n2);
    cout <<n1<<","<<n2<< endl;
    l2.getsP(n1, n2);
    cout <<n1<<","<<n2<< endl;

    Circle c4(150, 300, 200);
    c4.draw();
    Line l4(350, 300, 500, 600);
    l4.draw();
    Rec rec1(500, 300, 800, 400);
    rec1.draw();
    return 0;
}

void Point:: setx(int x) {
    this->x = x;
}
void Point:: sety(int y) {
    this->y = y;
}
int Point:: getx() {
    return x;
}
int Point:: gety() {
    return y;
}
void Circle:: setrad(int r) {
    this->rad = r;
}
int Circle:: getrad() {
    return rad;
}
void Circle:: setcent(int x, int y) {
    this->center.setx(x);
    this->center.sety(y);
}
void Circle:: getcent(int &n1, int &n2) {
    n1 = center.getx();
    n2 = center.gety();
}
void Line:: setfP(int x, int y) {
    this->firstP.setx(x);
    this->firstP.sety(y);
}
void Line:: getfP(int &n1, int &n2) {
    n1 = firstP.getx();
    n2 = firstP.gety();
}
void Line:: setsP(int x, int y) {
    this->secP.setx(x);
    this->secP.sety(y);
}
void Line:: getsP(int &n1, int &n2) {
    n1 = secP.getx();
    n2 = secP.gety();
}
void Rec:: setUL(int x, int y) {
    this->UL.setx(x);
    this->UL.sety(y);
}
void Rec:: getUL(int &n1, int &n2) {
    n1 = UL.getx();
    n2 = UL.gety();
}
void Rec:: setLR(int x, int y) {
    this->LR.setx(x);
    this->LR.sety(y);
}
void Rec:: getLR(int &n1, int &n2) {
    n1 = LR.getx();
    n2 = LR.gety();
}
