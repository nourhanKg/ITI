#include <iostream>

using namespace std;

class Stack {
    int stack[5];
    int top;
public:
    initTop() {
        top = 0;
    }
    void push(int);
    int pop();
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
    cout<<s.pop();
}
void Stack:: push(int n){
    if(top == 5) {
        cout<<"Stack is full\n";
    }
    else {
        stack[top] = n;
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
       eval = stack[top];
    }
    return eval;
}
