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


class Picture {
    int cNum;
    int lNum;
    int rNum;
    Line *linesPtr;
    Circle *cirPtr;
    Rec *recPtr;

public:
    Picture() {
        cNum = lNum = rNum = 0;
        linesPtr = NULL;
        cirPtr = NULL;
        recPtr = NULL;
    }
    Picture(int c, int l, int r, Circle *cPt, Line *lPt, Rec *rPt) {
        cNum = c;
        lNum = l;
        rNum = r;
        linesPtr = lPt;
        cirPtr = cPt;
        recPtr = rPt;
    }
    void setCir(int c, Circle *cPt) {
        cNum = c;
        cirPtr = cPt;
    }
    void setLine(int l, Line *lPt) {
        lNum = l;
        linesPtr = lPt;
    }
    void setRec(int r, Rec *rPt) {
        rNum = r;
        recPtr = rPt;
    }
    void drawPic();
};

int main()
{
    initgraph();
    /*int c, r, l;
    cout<<"Enter number of circles:\n";
    cin<<c;
    cout<<"Enter number of recs:\n";
    cin<<r;
    cout<<"Enter number of lines:\n";
    cin<<r;*/

    Circle *cPt = new Circle[2];
    Line *lPt = new Line[2];
    Rec *rPt = new Rec[2];

    cPt[0] = Circle(100, 200, 100);
    cPt[1] = Circle(150, 200, 120);
    lPt[0] = Line(350, 200, 500, 400);
    lPt[1] = Line(450, 200, 600, 400);
    rPt[0] = Rec(150, 500, 300, 700);
    rPt[1] = Rec(350, 500, 500, 700);

    Picture myPic(2, 2, 2, cPt, lPt, rPt);
    myPic.drawPic();
    //cPt[0].draw();

    /*Circle c4(150, 300, 200);
    c4.draw();
    Line l4(350, 300, 500, 600);
    l4.draw();
    Rec rec1(500, 300, 800, 400);
    rec1.draw();*/
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

void Picture::drawPic() {
    int i;
    for(i = 0; i < cNum; i++) {
        cirPtr[i].draw();
    }
    for(i = 0; i < lNum; i++) {
        linesPtr[i].draw();
    }
    for(i = 0; i < rNum; i++) {
        recPtr[i].draw();
    }

}
