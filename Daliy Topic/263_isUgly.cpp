//https://leetcode-cn.com/problems/ugly-number/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            }
            else if(n % 3 == 0) {
                n /= 3;
            }
            else if(n % 5 == 0) {
                n /= 5;
            }
            else {
                return false;
            }
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
        
        bool ret = Solution().isUgly(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}