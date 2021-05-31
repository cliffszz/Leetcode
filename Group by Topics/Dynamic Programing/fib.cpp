//https://leetcode-cn.com/problems/fibonacci-number/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, sum = 0;
        for(int i = 1; i <= n; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().fib(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}