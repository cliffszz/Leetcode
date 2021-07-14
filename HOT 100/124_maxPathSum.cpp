//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>
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
    int maxSum = INT_MIN;
    //寻找以该节点为起点的一条路径，使得路径和最大
    int backTrack(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        //如果子节点的最大贡献值为正，则计入该节点的最大路径和
        int left = max(backTrack(root->left), 0);
        int right = max(backTrack(root->right), 0);
        int path = root->val + left + right;
        maxSum = max(maxSum, path);
        //向上回溯
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        backTrack(root);
        return maxSum;
    }
};