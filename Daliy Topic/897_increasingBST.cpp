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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> inOrder;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                inOrder.push_back(cur);
                cur = cur->right;
            }
        }
        for (int i = 0; i < inOrder.size() - 1; i++) {
            inOrder[i]->left = nullptr;
            inOrder[i]->right = inOrder[i + 1];
        }
        inOrder.back()->right = nullptr;
        return inOrder[0];
    }
    TreeNode* increasingBST2(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* last = dummy;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                last->right = cur;
                cur->left = nullptr;
                last = cur;
                cur = cur->right;
            }
        }
        return dummy->right;
    }
};