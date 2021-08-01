//https://leetcode-cn.com/problems/subtree-of-another-tree/
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
    bool check(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t || s->val != t->val) return false;
        return check(s->left, t->left) && check(s->right, t->right);
    }
    bool dfs(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return check(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }
};