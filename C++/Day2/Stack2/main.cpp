#include <iostream>

using namespace std;

class Stack {
    int *stPtr;
    int top;
    int mysize;
public:
    Stack() {
        top = 0;
        mysize = 5;
        stPtr = new int[mysize];
    }
    Stack(int s) {
        top = 0;
        mysize = s;
        stPtr = new int[mysize];
    }
    void push(int);
    int pop();
    ~Stack() {
        delete stPtr;
        cout<<"I am destructor\n";
    }
};

int main()
{
    Stack s;
    s.push(8);
    s.push(2);
    s.push(4);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<"With input size\n";
    Stack ss(3);
    ss.push(8);
    ss.push(2);
    ss.push(4);
    ss.push(4);
    cout<<ss.pop()<<"\n";
    cout<<ss.pop()<<"\n";
    cout<<ss.pop()<<"\n";
    cout<<ss.pop()<<"\n";
    return 0;
}
void Stack:: push(int n){
    if(top == mysize) {
        cout<<"Stack is full\n";
    }
    else {
        stPtr[top] = n;
        top++;
    }
}
int Stack:: pop() {
    int eval = 0;
    if(top == 0) {
        cout<<"Stack is empty\n";
    }
    else {
       top--;
       eval = stPtr[top];
    }
    return eval;
}
