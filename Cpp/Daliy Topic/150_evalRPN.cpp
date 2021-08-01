//https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int num = 0;
        for(string s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                if(s == "+") num = num1 + num2;
                else if(s == "-") num = num1 - num2;
                else if(s == "*") num = num1 * num2;
                else if(s == "/") num = num1 / num2;
                stk.push(num);
            }
            else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};

int main() {

    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution solution;
    int ret = solution.evalRPN(tokens);
    cout << ret << endl;

    return 0;
}