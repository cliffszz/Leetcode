//https://leetcode-cn.com/problems/path-sum/
#include <vector>
#include <stack>
#include <queue>
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
    bool backTracking(TreeNode* root, int targetSum) {
        if (!root->left && !root->right && targetSum == 0) return true;
        if (!root->left && !root->right) return false;
        if (root->left) {
            targetSum -= root->left->val;
            if(backTracking(root->left, targetSum)) return true;
            targetSum += root->left->val;
        }
        if (root->right) {
            targetSum -= root->right->val;
            if (backTracking(root->right, targetSum)) return true;
            targetSum += root->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return backTracking(root, targetSum - root->val);
    }
};