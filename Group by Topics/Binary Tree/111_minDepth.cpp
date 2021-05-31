//https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int s = que.size();
            depth++;
            bool flag = false;
            for (int i = 0; i < s; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (!cur->left && !cur->right) {
                    flag = true;
                    break;
                }
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            if (flag) break;
        }
        return depth;
    }
};