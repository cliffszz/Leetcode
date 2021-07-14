//https://leetcode-cn.com/problems/count-complete-tree-nodes/
#include <vector>
#include <stack>
#include <queue>

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
    int countNodes(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root) stk.push(root);
        int i = 0;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            i++;
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
        }
        return i;
    }

    int countNodes2(TreeNode* root) {
        queue<TreeNode*> que;
        int cnt = 0;
        if (root) que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            cnt++;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        return cnt;
    }
};