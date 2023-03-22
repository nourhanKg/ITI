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
    friend ostream& operator<<(ostream& os, Complex &c) {
    if(!c.real)
        if(c.img == 0)
            os<<'0';
        else
            if(c.img == 1)
                os<<'i';
            else
                if(c.img == -1)
                    os<<'-'<<'i';
                else
                    os<<c.img<<'i';
    else
        if(c.img == 0)
            os<<c.real;
        else
            if(c.img > 0)
                if(c.img == 1)
                    os<<c.real<<'+i';
                else
                    os<<c.real<<'+'<<c.img<<'i';
            else
                if(c.img == -1)
                    os<<c.real<<'-i';
                else
                os<<c.real<<c.img<<'i';
    return os;
    }
    friend istream & operator >> (istream &in,  Complex &c) {
        in>> c.real;
        in>> c.img;
        return in;
    }
};

int main()
{
    Complex c1(2,5);
    Complex c2(-1, 3);
    Complex c3(0, -1);
    Complex c4;
    cout<< c1<<"\n";
    cout<< c2<<"\n";
    cout<< c3;
    cout<<"\nEnter complex:\n";
    cin>>c4;
    cout<<c4;
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
