#include <iostream>

using namespace std;

class Complex
{

    float real;
    float imag;

public:
    float getReal();
    void setReal(float);
    float getImag();
    void setImag(float);
};
void print(Complex);
Complex sum(Complex, Complex);
int main()
{

    float r,i, a,b;
    Complex obj1;

    cout << "Enter a real Number \t";
    cin >> r;
    obj1.setReal(r);
    cout << "Enter an imaginary Number: \t";
    cin >> i;
    obj1.setImag(i);
    print(obj1);
 //  cout << "The Complex Number is: " << obj1.getReal() << " + " << obj1.getImag()<< "i \n";

    Complex obj2;
    cout << "Enter a 2nd real Number \t";
    cin >> a;
    obj2.setReal(a);
    cout << "Enter a 2nd imaginary Number: \t";
    cin >> b;
    obj2.setImag(b);
    print(obj2);
  //  cout << "The Complex Number is: " << obj2.getReal() << " + " << obj2.getImag()<< "i \n";
    Complex result = sum(obj1, obj2);
    cout << result.getReal() << " + " <<  result.getImag() << "i" ;


    return 0;
}


float Complex::getImag()
{
    return imag;
}


void Complex:: setImag(float img)
{
    imag = img;
}


float Complex:: getReal()
{
    return real;
}


void Complex::setReal(float re)
{
    real = re;
}


Complex sum(Complex num1,Complex num2)
{
    float sum1, sum2;
    sum1 =    num1.getReal() + num2.getReal();
    sum2 =   num1.getImag() + num2.getImag();

    Complex result;
    result.setReal(sum1);
    result.setImag(sum2);

    return result;

}


void print(Complex obj){

    float x = 0;
    float y = 0;
    cout << x;
    cout << y;
    if(x == 0 && y == 0) {
        cout << "0";
    }else{

    if(obj.getReal() == 0 ) {
        cout << obj.getImag() << "i";
    }
    if(obj.getImag() == 1  ){
        cout << obj.getReal() << " + i";
    }

    if(obj.getImag() == -1  ){
        cout << obj.getReal() << " -i";
    }

    if(obj.getImag() == 0)

    cout << obj.getReal();
    }


//cout << "The Complex Number is: " << obj.getReal() << " + " << obj.getImag()<< "i \n";
    }
