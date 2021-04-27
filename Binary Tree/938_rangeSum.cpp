//https://leetcode-cn.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> stk;
        int sum = 0;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
                if (cur && cur->val < low) {
                    cur = cur->right;
                }
            } else {
                cur = stk.top();
                stk.pop();
                if (low <= cur->val && cur->val <= high) {
                    sum += cur->val;
                }
                else if (cur->val > high) break;
                cur = cur->right;
            }
        }
        return sum;
    }
};

class Solution2 {
public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

class Solution3 {
public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        int sum = 0;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            if (node->val > high) {
                q.push(node->left);
            } else if (node->val < low) {
                q.push(node->right);
            } else {
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return sum;
    }
};