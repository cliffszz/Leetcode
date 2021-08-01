//https://leetcode-cn.com/problems/balanced-binary-tree/
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
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = getDepth(root->left);
        if (left_depth == -1) return -1;
        int right_depth = getDepth(root->right);
        if (right_depth == -1) return -1;
        return (abs(left_depth - right_depth) > 1) ? -1 : 1 + max(left_depth, right_depth);
    }
    bool isBalanced(TreeNode* root) {
        return (getDepth(root) == -1) ? false : true;
    }
};