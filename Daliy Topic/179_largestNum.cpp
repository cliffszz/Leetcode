//https://leetcode-cn.com/problems/largest-number/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compare(const int& num1, const int& num2) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        return (s1 + s2) > (s2 + s1);
    }
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 1) return to_string(nums[0]);
        sort(nums.begin(), nums.end(), compare);
        //reverse(nums.begin(), nums.end());
        if(nums[0] == nums[1] && nums[0] == 0) return "0";
        string res;
        for(int& n : nums) {
            res += to_string(n);
        }
        return res;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        string ret = Solution().largestNumber(nums);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}