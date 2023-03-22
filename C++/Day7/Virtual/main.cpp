#include <iostream>

using namespace std;

class ShapeG {
protected:
    float dim1, dim2;
public:
    ShapeG() {
        dim1 = dim2 = 0;
    }
    ShapeG(float d) {
        dim1 = dim2 = d;
    }
    ShapeG(float d1, float d2) {
        dim1 = d1;
        dim2 = d2;
    }
    void setdim1(float n) {
        dim1 = n;
    }
    void setdim2(float n) {
        dim2 = n;
    }
    virtual float calcArea() {
        return 0;
    }
};

class Circle: public ShapeG {
    public:
    Circle(){
    }
    Circle(float r): ShapeG(r) {
    }
    void setr(float r) {
        dim1 = dim2 = r;
    }
    float calcArea() {
        return 3.14 * dim1 * dim2;
    }
};

class Triangle: public ShapeG {
    public:
    Triangle() {
    }
    Triangle(float d): ShapeG(d) {
    }
    Triangle(float d1, float d2): ShapeG(d1, d2) {
    }
    float calcArea() {
        return 0.5 * dim1 * dim2;
    }
};

class Rectangle: public ShapeG {
    public:
    Rectangle() {
    }
    Rectangle(float d): ShapeG(d) {
    }
    Rectangle(float d1, float d2): ShapeG(d1, d2) {
    }
    float calcArea() {
        return dim1 * dim2;
    }
};

class Square: public Rectangle {
    public:
    Square() {
    }
    Square(float d): Rectangle(d, d) {
    }
    void setd(float d) {
       dim1 = dim2 = d;
    }
    float calcArea() {
        return dim1 * dim2;
    }
};


float sumOfAreas(ShapeG *, ShapeG *, ShapeG *);
int main()
{

    Circle c1(10);

    Rectangle r1(3,4);

    Square s1(5);

    cout<<sumOfAreas(&c1, &r1, &s1)<<'\n';

    return 0;
}
float sumOfAreas(ShapeG *g1, ShapeG *g2, ShapeG *g3) {
    return g1->calcArea() +  g2->calcArea() + g3->calcArea();
}
