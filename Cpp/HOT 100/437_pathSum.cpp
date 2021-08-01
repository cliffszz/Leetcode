//https://leetcode-cn.com/problems/path-sum-iii/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int, int> preSum;
    int res = 0;
    void dfs(TreeNode* root, int target, int curSum) {
        if (root == nullptr) {
            return;
        }
        curSum += root->val;
        //前缀和之差为路径和
        if (preSum.find(curSum - target) != preSum.end()) {
            res += preSum[curSum - target];
        }
        preSum[curSum]++;
        dfs(root->left, target, curSum);
        dfs(root->right, target, curSum);
        preSum[curSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        preSum[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};