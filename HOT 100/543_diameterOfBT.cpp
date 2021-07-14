//https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
public:
    int dfs(TreeNode* root, int& maxLen) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, maxLen);
        int right = dfs(root->right, maxLen);
        maxLen = max(maxLen, left + right + 1);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 1;
        dfs(root, maxLen);
        return maxLen - 1;
    }
};