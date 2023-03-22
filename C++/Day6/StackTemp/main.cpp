#include <iostream>

using namespace std;

template <class T>
class Stack {
    T *stPtr;
    int top;
    int mysize;
    static int counter;
public:
    Stack(Stack&);
    Stack() {
        top = 0;
        mysize = 5;
        stPtr = new T[mysize];
        counter++;
    }
    Stack(int s) {
        top = 0;
        mysize = s;
        stPtr = new T[mysize];
        counter++;
    }
    void push(T);
    T pop();
    int gettop();
    static int getcounter() {
        return counter;
    }
    friend void viewStack(Stack &);
    ~Stack() {
        int i;
        int n = top;
        for(i = 0; i < top; i++) {
            stPtr[i] = 0;
        }
        counter--;
        delete []stPtr;
        cout<<"I am destructor\n";
    }
};

template <class T>
int Stack<T>:: counter =0;

int main() {
    Stack<int> s1(5), s2(4);
    s1.push(6);
    s1.push(4);
    s2.push(1);
    //Stack<int>:: viewStack(s1);
    cout<<"check int\n";
    cout<<s1.pop()<<"\n";
    cout<<s2.pop()<<"\n";
    cout<<Stack<int>::getcounter()<<"\n";

    Stack<char> c1(5), c2(4), c3;
    c1.push('A');
    c1.push('B');
    c2.push('C');

    //Stack<int>:: viewStack(s1);
    cout<<"check int\n";
    cout<<c1.pop()<<"\n";
    cout<<c2.pop()<<"\n";
    cout<<c3.pop()<<"\n";
    cout<<Stack<char>::getcounter()<<"\n";
    return 0;
}

template <class T>
void Stack<T>:: push(T n){
    if(top == mysize) {
        cout<<"Stack is full\n";
    }
    else {
        stPtr[top] = n;
        top++;
    }
}
template <class T>
T Stack<T>:: pop() {
    T eval = 0;
    if(top == 0) {
        cout<<"Stack is empty\n";
    }
    else {
       top--;
       eval = stPtr[top];
    }
    return eval;
}

template <class T>
int Stack<T>:: gettop() {
    return top;
}

template <class T>
void viewStack(Stack<T> &s) {
  int n = s.top;
  int i;
  for(i = 0; i < n; i++){
    cout<<s.stPtr[i]<<"\n";
  }
}

template <class T>
Stack<T>:: Stack(Stack<T> &s) {
    this->top = s.top;
    this->mysize = s.mysize;
    counter++;
    this->stPtr = new T[s.mysize];
    int i;
    for(i = 0; i < this->top; i++) {
        this->stPtr[i] = s.stPtr[i];
    }
}
