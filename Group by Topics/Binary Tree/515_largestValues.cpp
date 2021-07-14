//https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int s = que.size();
            int maxNum = INT_MIN;
            for (int i = 0; i < s; i++) {
                TreeNode* cur = que.front();
                que.pop();
                maxNum = max(maxNum, cur->val);
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
            res.push_back(maxNum);
        }
        return res;
    }
};