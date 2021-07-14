//https://leetcode-cn.com/problems/validate-binary-search-tree/
#include <vector>
#include <stack>
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

//递归
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

//中序遍历
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!root->left && !root->right) return true;
        stack<TreeNode*> stk;
        vector<int> vec;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                vec.push_back(cur->val);
                cur = cur->right;
            }
        }
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] < vec[i - 1]) return false;
        }
        return true;
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!root->left && !root->right) return true;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        long long preVal = (long long)INT_MIN - 1;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if (cur->val <= preVal) return false;
                preVal = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
};