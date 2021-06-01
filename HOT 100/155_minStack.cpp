//https://leetcode-cn.com/problems/min-stack/
#include <stack>
#include <limits.h>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> min;
public:
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        int tmp = min.top();
        if (val < tmp) {
            min.push(val);
        } else min.push(tmp);
    }
    
    void pop() {
        stk.pop();
        min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min.top();
    }
};