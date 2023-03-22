#include <iostream>

using namespace std;

struct Complex {
    float real;
    float img;
    void setreal(float);
    void setimg(float);
    float getreal();
    float getimg();
    void print();
};


Complex Add(Complex, Complex);


int main()
{
    Complex c1, c2;
    cout<<"Enter first number real part\n";
    cin>>c1.real;
    cout<<"Enter first number img part\n";
    cin>>c1.img;
    cout<<"Enter second number real part\n";
    cin>>c2.real;
    cout<<"Enter second number img part\n";
    cin>>c2.img;

    Complex sum = Add(c1, c2);
    sum.print();

    return 0;
}


void Complex:: setreal(float r) {
    real = r;
}
void Complex:: setimg(float i) {
    img = i;
}
float Complex:: getreal() {
    return real;
}
float Complex:: getimg() {
    return real;
}
void Complex:: print() {
    if(!real)
        if(img == 0)
            cout<<"0";
        else
            if(img == 1)
                cout<<"i\n";
            else
                if(img == -1)
                    cout<<"-i\n";
                else
                    cout<<img<<"i\n";
    else
        if(img == 0)
            cout<<real<<"\n";
        else
            if(img > 0)
                if(img == 1)
                    cout<<real<<"+"<<"i\n";
                else
                    cout<<real<<"+"<<img<<"i\n";
            else
                if(img == -1)
                    cout<<real<<"-i\n";
                else
                cout<<real<<img<<"i\n";
}


Complex Add(Complex c1, Complex c2) {
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.img = c1.img + c2.img;
    return sum;
}

