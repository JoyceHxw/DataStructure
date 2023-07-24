#include <iostream>
using namespace std;
#include <stack>

class MinStack {
public:
    // 难点在于当pop改变栈中元素时，如何找到对应的最小元素
    // 即把当前所有元素与其最小元素对应起来
    // 辅助栈
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        // 同步保存对应元素的最小元素
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }

};
