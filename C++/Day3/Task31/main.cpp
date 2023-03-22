#include <iostream>

using namespace std;

class Stack {
    int *stPtr;
    int top;
    int mysize;
    static int counter;
public:
    Stack() {
        top = 0;
        mysize = 5;
        stPtr = new int[mysize];
        counter++;
    }
    Stack(int s) {
        top = 0;
        mysize = s;
        stPtr = new int[mysize];
        counter++;
    }
    void push(int);
    int pop();
    int gettop();
    static int getcounter() {
        return counter;
    }
    ~Stack() {
        int i;
        for(i = 0; i < mysize; i++) {
            stPtr[i] = 32;
        }
        counter--;
        delete stPtr;
        cout<<"I am destructor\n";
    }
};

int Stack:: counter = 0;
void viewStack(Stack);
int main() {
    Stack s1(5);
    s1.push(6);
    s1.push(4);
    s1.push(1);
    cout<<"Top before"<<s1.gettop()<<"\n";
    viewStack(s1);
    cout<<"Top after"<<s1.gettop()<<"\n";
    cout<<s1.pop()<<"\n";
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
int Stack:: gettop() {
    return top;
}
void viewStack(Stack s) {
    int con = Stack::getcounter();
    //cout<<con<<"\n";
    int n = s.gettop();
    int i;
    for(i = 0; i < n; i++){
    cout<<s.pop()<<"\n";
    }
}
