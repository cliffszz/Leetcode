//https://leetcode-cn.com/problems/leaf-similar-trees/
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
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
    void postOrder(TreeNode* root, vector<int>& leaf) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if (!cur->left && !cur->right) leaf.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        postOrder(root1, l1);
        postOrder(root2, l2);
        return l1 == l2;
        /*
        if (l1.size() != l2.size()) return false;
        int n = l1.size();
        for (int i = 0; i < n; i++) {
            if (l1[i] != l2[i]) return false;
        }
        return true;
        */
    }
};