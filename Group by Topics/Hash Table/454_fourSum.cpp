//https://leetcode-cn.com/problems/4sum-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        int cnt = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(0 - (c + d)) != map.end()) {
                    cnt += map[0 - (c + d)];
                }
            }
        }
        return cnt;
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums3 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums4 = stringToIntegerVector(line);
        
        int ret = Solution().fourSumCount(nums1, nums2, nums3, nums4);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}