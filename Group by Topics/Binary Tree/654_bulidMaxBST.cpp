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

class Solution2 {
public:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        TreeNode* root = new TreeNode(0);
        if (right - left == 1) {
            root->val = nums[left];
            return root;
        }
        int maxId = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] >= nums[maxId]) {
                maxId = i;
            }
        }
        root->val = nums[maxId];
        root->left = traversal(nums, left, maxId);
        root->right = traversal(nums, maxId + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return traversal(nums, 0, nums.size());
    }
};