#include <iostream>

using namespace std;
class Complex {
    float real;
    float img;
public:
    float getreal();
    void  setreal(float);
    float getimg();
    void  setimg(float);
    void print();
    Complex() {
        real = 1;
        img = 1;
    }
    Complex(float r, float i) {
        real = r;
        img = i;
    }
    Complex(float n) {
        real = n;
        img =n;
    }
    ~Complex() {
        //cout<<"I am destructor\n";
    }

};


Complex Add(Complex, Complex);
Complex Add(float, Complex);
Complex Add(Complex, float);
Complex Add(Complex, Complex, Complex);
int main()
{
    Complex c1;
    Complex c2(5.5, -3.2);
    Complex c3(2);
    c1.print();
    c2.print();
    c3.print();
    Complex sum1 = Add(c2, c3);
    sum1.print();
    Complex sum2 = Add(1, c2);
    sum2.print();
    Complex sum3 = Add(c2, -2);
    sum3.print();
    Complex sum4 = Add(c1, c2, c3);
    sum4.print();
    return 0;
}

float Complex:: getreal(){
    return real;
}
void Complex:: setreal(float r){
    real = r;
}
float Complex:: getimg(){
    return img;
}
void Complex:: setimg(float i){
    img = i;
}
void Complex:: print(){
    if(!real)
        cout <<img<<"i\n";
    else
        if(img == 0)
            cout<<real<<"\n";
        else
            if(img > 0)
                cout<<real<<"+"<<img<<"i\n";
            else
                cout<<real<<img<<"i\n";
}


Complex Add(Complex c1, Complex c2) {
    Complex sum;
    sum.setreal(c1.getreal() + c2.getreal());
    sum.setimg(c1.getimg() + c2.getimg());
    return sum;
}
Complex Add(float c1, Complex c2) {
    Complex sum;
    sum.setreal(c1 + c2.getreal());
    sum.setimg(c2.getimg());
    return sum;
}
Complex Add(Complex c1, float c2) {
    Complex sum;
    sum.setreal(c1.getreal() + c2);
    sum.setimg(c1.getimg());
    return sum;
}
Complex Add(Complex c1, Complex c2, Complex c3) {
    Complex sum;
    sum.setreal(c1.getreal() + c2.getreal() + c3.getreal());
    sum.setimg(c1.getimg() + c2.getimg() + c3.getimg());
    return sum;
}
