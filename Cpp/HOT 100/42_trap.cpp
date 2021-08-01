//https://leetcode-cn.com/problems/trapping-rain-water/
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            //第一列和最后一列不接雨水
            if (i == 0 || i == height.size() - 1) continue;
            int lH = height[i], rH = height[i];
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > lH) lH = height[j];
            }
            for (int j = i + 1; j < height.size(); j++) {
                if (height[j] > rH) rH = height[j];
            }
            sum += min(lH, rH) - height[i];
        }
        return sum;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int sum = 0;
        vector<int> lH(n, 0);
        vector<int> rH(n, 0);
        lH[0] = height[0];
        for (int i = 1; i < n; i++) {
            lH[i] = max(height[i], lH[i - 1]);
        }
        rH[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rH[i] = max(height[i], rH[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            sum += min(lH[i], rH[i]) - height[i];
        }
        return sum;
    }
};

class Solution3 {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int sum = 0;
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[stk.top()]) {
                stk.push(i);
            } else if (height[i] == height[stk.top()]) {
                stk.pop();
                stk.push(i);
            } else {
                while (!stk.empty() && height[i] > height[stk.top()]) {
                    int m = stk.top();
                    stk.pop();
                    if (!stk.empty()) {
                        int w = i - stk.top() - 1;
                        int h = min(height[i], height[stk.top()]) - height[m];
                        sum += h * w;
                    }
                }
                stk.push(i);
            }
        }
        return sum;
    }
};