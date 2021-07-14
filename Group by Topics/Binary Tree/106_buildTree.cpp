//https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        //数组大小为零，说明是空节点
        if (postorder.size() == 0) return nullptr;
        //后序遍历数组的最后一个节点为根节点
        int rootVal = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootVal);
        //叶子结点
        if (postorder.size() == 1) return root;
        //找切割点
        int delId;
        for (delId = 0; delId < inorder.size(); delId++) {
            if (inorder[delId] == rootVal) break;
        }
        //切割中序数组和后续数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delId);
        vector<int> rightInorder(inorder.begin() + delId + 1, inorder.end());
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostOrder(postorder.begin() + leftInorder.size(), postorder.end());
        //递归
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostOrder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};

class Solution2 {
public:
    TreeNode* traversal(vector<int>& inorder, int leftIn, int rightIn ,vector<int>& postorder, int leftPost, int rightPost) {
        //数组大小为零，说明是空节点
        if (leftPost == rightPost) return nullptr;
        //后序遍历数组的最后一个节点为根节点
        int rootVal = postorder[rightPost - 1];
        TreeNode* root = new TreeNode(rootVal);
        //叶子结点
        if (rightPost - leftPost == 1) return root;
        //找切割点
        int delId;
        for (delId = leftIn; delId < rightIn; delId++) {
            if (inorder[delId] == rootVal) break;
        }
        //切割中序数组和后续数组
        //递归
        root->left = traversal(inorder, leftIn, delId, postorder, leftPost, leftPost + delId - leftIn);
        root->right = traversal(inorder, delId + 1, rightIn, postorder, leftPost + delId - leftIn, rightPost - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};