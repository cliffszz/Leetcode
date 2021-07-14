//https://leetcode-cn.com/problems/contains-duplicate-iii/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> s;
        for(int i = 0; i < n; i++) {
            auto it = s.lower_bound(max(nums[i], INT_MIN + t) - t);
            if(it != s.end() && *it <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            s.insert(nums[i]);
            if(i >= k) {
                s.erase(nums[i - k]);
            }
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int t = stringToInteger(line);
        
        bool ret = Solution().containsNearbyAlmostDuplicate(nums, k, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}