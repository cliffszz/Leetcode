//https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
#include <vector>
#include <stack>
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* pre = nullptr;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (pre != nullptr) {
                pre->left = nullptr;
                pre->right = cur;
            }
            if(cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
            pre = cur;
        }
    }
};