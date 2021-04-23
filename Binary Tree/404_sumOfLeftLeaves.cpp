//https://leetcode-cn.com/problems/sum-of-left-leaves/
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leftIsLeftLeaf(TreeNode* root) {
        if (root->left && !root->left->left && !root->left->right) {
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> que;
        int sum = 0;
        if (root) que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (leftIsLeftLeaf(cur)) sum += cur->left->val;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        return sum;
    }
};