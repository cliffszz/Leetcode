//https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
#include <vector>
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
    void dfs(TreeNode* root, int& val) {
        if (root == nullptr) {
            return;
        }
        dfs(root->right, val);
        root->val += val;
        val = root->val;
        dfs(root->left, val);
    }
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        dfs(root, val);
        return root;
    }
};