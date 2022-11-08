#include<bits/stdc++.h>
using namespace std;

void pushAtEnd(stack<int> &s, int data) {
    stack<int> temp;

    while(!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    s.push(data);

    while(!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

}

void display(stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    pushAtEnd(s, 4);
    pushAtEnd(s, 5);
    pushAtEnd(s, 6);

    display(s);

}