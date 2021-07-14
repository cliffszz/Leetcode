//https://leetcode-cn.com/problems/happy-number/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        set.insert(n);
        while (n != 1) {
            n = getSum(n);
            if (set.find(n) != set.end()) {
                return false;
            }
            else set.insert(n);
        }
        return true;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}