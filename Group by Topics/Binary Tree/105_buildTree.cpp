//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        int delId;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                delId = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delId);
        vector<int> rightInorder(inorder.begin() + delId + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return traversal(preorder, inorder);
    }
};

class Solution2 {
public:
    TreeNode* traversal(vector<int>& preorder, int leftPre, int rightPre, vector<int>& inorder, int leftIn, int rightIn) {
        if (leftPre == rightPre) return nullptr;
        int rootVal = preorder[leftPre];
        TreeNode* root = new TreeNode(rootVal);
        if (rightPre - leftPre == 1) return root;
        int delId;
        for (int i = leftIn; i <= rightIn; i++) {
            if (inorder[i] == rootVal) {
                delId = i;
                break;
            }
        }

        root->left = traversal(preorder, leftPre + 1, leftPre + 1 + delId - leftIn, inorder, leftIn, delId);
        root->right = traversal(preorder, leftPre + 1 + delId - leftIn, rightPre, inorder, delId + 1, rightIn);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};