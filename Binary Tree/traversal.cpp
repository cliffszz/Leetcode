#include <vector>
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

class Recursion {
public:
    void preOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }
    void inOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
    void postOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        postOrder(root->left, vec);
        postOrder(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> orderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        inOrder(root, res);
        postOrder(root, res);
        return res;
    }
};

class Iteration {
public:
    vector<int> preOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            if (cur->right != nullptr) stk.push(cur->right);
            if (cur->left != nullptr) stk.push(cur->left);
        }
        return res;
    }
    vector<int> inOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
    vector<int> postOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            if (cur->left != nullptr) stk.push(cur->left);
            if (cur->right != nullptr) stk.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};