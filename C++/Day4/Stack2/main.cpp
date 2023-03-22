#include <iostream>

using namespace std;

class Stack {
    int *stPtr;
    int top;
    int mysize;
    static int counter;
public:
    //Stack(Stack&);
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
    int gettop();
    Stack& operator=(Stack &s) {
        delete this->stPtr;
        top = s.top;
        mysize = s.mysize;
        int i;
        for(i = 0; i < top; i++) {
            stPtr[i] = s.stPtr[i];
        }
        return *this;
    }
    int& operator[](int n) {
        int i = n-1;
        if(i > top || i < 0) {
            cout<<"Out of Stack\n";
        }
        else {
            return stPtr[i];
        }
    }

    static int getcounter() {
        return counter;
    }
    ~Stack() {
        int i;
        int n = top;
        for(i = 0; i < top; i++) {
            stPtr[i] = 32;
        }
        counter--;
        delete stPtr;
        cout<<"I am destructor\n";
    }
};

int Stack:: counter = 0;
//void viewStack(Stack);

int main() {
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<<s1.pop()<<"\n";
    cout<<s1.pop()<<"\n";
    Stack s2(3);
    s2.push(10);
    s2.push(20);
    s2.push(30);

    Stack s3 = s2;
    cout<<s3.pop()<<"\n";
    cout<<s3.pop()<<"\n";

    cout<<s2[3]<<"\n";
    cout<<s2[1]<<"\n";
    cout<<s2[5]<<"\n";

    s2[2]= 500;
    cout<<s2[2]<<"\n";
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

/*void viewStack(Stack s) {
  int n = s.gettop();
  int i;
  for(i = 0; i < n; i++){
    cout<<s.pop()<<"\n";
  }
}*/

