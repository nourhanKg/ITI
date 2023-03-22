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
    ~Complex() {
        //cout<<"I am destructor\n";
    }

    Complex operator+(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }
    Complex operator-(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.img = img - c.img;
        return result;
    }
    Complex operator=(Complex c) {
        real = c.real;
        img = c.img;
        return *this;
    }
    void operator++() {
        real++;
        img++;
    }
    Complex operator++(int n) {
        Complex result = *this;
        real++;
        img++;
        return result;
    }
    void operator--() {
        real--;
        img--;
    }
    Complex operator--(int n) {
        Complex result = *this;
        real--;
        img--;
        return result;
    }

    void operator+=(Complex c) {
        real = real + c.real;
        img = img + c.img;
    }
    void operator-=(Complex c) {
        real = real - c.real;
        img = img - c.img;
    }
    Complex operator*(Complex c) {
        Complex result;
        result.real = (real * c.real) + ((img * c.img)) * (-1);
        result.img = (real * c.img) + (img * c.real);
        return result;
    }

    int operator==(Complex c) {
        return (real == c.real && img == c.img);
    }
    int operator!=(Complex c) {
        return (real != c.real || img != c.img);
    }
    int operator>(Complex c) {
        if(real > c.real)
            return 1;
        else
            if(real == c.real)
                if(img > c.img)
                    return 1;
                else
                    return 0;
            else
                return 0;
    }
    int operator<(Complex c) {
        if(c.real > real)
            return 1;
        else
            if(c.real == real)
                if(c.img > img)
                    return 1;
                else
                    return 0;
            else
                return 0;
    }
    operator float() {
        return real;
    }
    operator int() {
        return (int)real;
    }
};

int main()
{
    Complex c1(2,5);
    Complex c2(-1, 3);

    Complex res1 = c1 + c2;
    res1.print();
    Complex res2 = c1 - c2;
    res2.print();
    Complex res3 = c2;
    res3.print();


    ++c1;
    c1.print();
    Complex res4 = c1++;
    res4.print();
    c1.print();

    --c1;
    c1.print();
    Complex res5 = c1--;
    res5.print();
    c1.print();

    c1 += c2;
    c1.print();
    c1 -= c2;
    c2.print();


    Complex res6 = c1 * c2;
    res6.print();


    Complex c3 = c2;
    if(c3 == c2) {
        cout<<"Equal\n";
    }
    else {
        cout<<"Not Equal\n";
    }
    if(c1 != c2) {
        cout<<"Not Equal\n";
    }
    else {
        cout<<"Equal\n";
    }


    if(c1 > c2) {
        cout<<"C1 is greater\n";
    }
    else {
        cout<<"C2 is greater\n";
    }

    if(c1 < c2) {
        cout<<"C1 is lesser\n";
    }
    else {
        cout<<"C2 is lesser\n";
    }

    float res7 = (float)c1;
    cout<<res7<<"\n";
    Complex c4(2.5, 5);
    int res8 = (int)c4;
    cout<<res8;
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
