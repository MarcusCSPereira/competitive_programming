#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> _stack;
    stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        _stack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }

    void pop() {
        _stack.pop();
        minStack.pop();
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};