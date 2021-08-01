//https://leetcode-cn.com/problems/132-pattern/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits.h>
#include <stack>

using namespace std;    

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = INT_MIN;
        int n = nums.size();
        if (n < 3) return false;
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] >= two) {
                while(!stk.empty() && stk.top() < nums[i]) {
                    two = stk.top();
                    stk.pop();
                }
                stk.push(nums[i]);
            }
            else return true;
        }
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().find132pattern(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}