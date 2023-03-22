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
};


Complex Add(Complex, Complex);
int main()
{
    Complex c1, c2;
    float num;
    cout << "Enter first num real\n";
    cin>>num;
    c1.setreal(num);
    cout << "Enter first num img\n";
    cin>>num;
    c1.setimg(num);
    cout << "Enter second num real\n";
    cin>>num;
    c2.setreal(num);
    cout << "Enter second num img\n";
    cin>>num;
    c2.setimg(num);

    Complex sum = Add(c1, c2);
    sum.print();


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
