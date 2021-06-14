//https://leetcode-cn.com/problems/invert-binary-tree/
#include <queue>
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
    void backTrack(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        backTrack(root->left);
        backTrack(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        backTrack(root);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        return root;
    }
};