//https://leetcode-cn.com/problems/merge-two-binary-trees/
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        TreeNode* merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);
        return merged;
    }
};

//BFS
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        auto q = queue<TreeNode*>();
        auto queue1 = queue<TreeNode*>();
        auto queue2 = queue<TreeNode*>();
        q.push(merged);
        queue1.push(t1);
        queue2.push(t2);
        while (!queue1.empty() && !queue2.empty()) {
            auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
            q.pop();
            queue1.pop();
            queue2.pop();
            auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
            if (left1 != nullptr || left2 != nullptr) {
                if (left1 != nullptr && left2 != nullptr) {
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    q.push(left);
                    queue1.push(left1);
                    queue2.push(left2);
                } else if (left1 != nullptr) {
                    node->left = left1;
                } else if (left2 != nullptr) {
                    node->left = left2;
                }
            }
            if (right1 != nullptr || right2 != nullptr) {
                if (right1 != nullptr && right2 != nullptr) {
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    queue1.push(right1);
                    queue2.push(right2);
                } else if (right1 != nullptr) {
                    node->right = right1;
                } else {
                    node->right = right2;
                }
            }
        }
        return merged;
    }
};