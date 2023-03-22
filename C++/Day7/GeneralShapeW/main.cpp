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
    float calcArea() {
        return dim1 * dim2;
    }
};

class Circle: public ShapeG {
    public:
    Circle(){
    }
    Circle(float r): ShapeG(r) {
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
};

class Square: public Rectangle {
    public:
    Square() {
    }
    Square(float d): Rectangle(d, d) {
    }

    float calcArea() {
        return dim1 * dim2;
    }
};
int main()
{
    Circle c1;
    Circle c2(10);
    cout<<c1.calcArea()<<'\n';
    cout<<c2.calcArea()<<'\n';
    c1.setdim1(3);
    c1.setdim2(3);
    cout<<c1.calcArea()<<'\n';
    Triangle t1(10);
    Triangle t2(5,6);
    cout<<t1.calcArea()<<'\n';
    cout<<t2.calcArea()<<'\n';
    t2.setdim1(10);
    cout<<t2.calcArea()<<'\n';
    Rectangle r1(3,4);
    cout<<r1.calcArea()<<'\n';
    r1.setdim1(6);
    r1.setdim2(7);
    cout<<r1.calcArea()<<'\n';
    Square s1;
    Square s2(10);
    cout<<s1.calcArea()<<'\n';
    cout<<s2.calcArea()<<'\n';
    s1.setdim1(5);
    s1.setdim2(10);
    cout<<s1.calcArea()<<'\n';
    return 0;
}
