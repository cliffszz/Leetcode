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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        if (nums.size() == 1) {
            root->val = nums[0];
            return root;
        }
        int maxId = 0;
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= maxVal) {
                maxId = i;
                maxVal = nums[i];
            }
        }
        root->val = maxVal;
        if (maxId > 0) {
            vector<int> left(nums.begin(), nums.begin() + maxId);
            root->left = constructMaximumBinaryTree(left);
        }
        if (maxId < nums.size() - 1) {
            vector<int> right(nums.begin() + maxId + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};