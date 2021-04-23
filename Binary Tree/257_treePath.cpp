#include <vector>
#include <string>
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
    void backTracking(TreeNode* root, vector<int>& path, vector<string>& res) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string sPath;
            for (int i = 0; i < path.size(); i++) {
                sPath += to_string(path[i]);
                if (i != path.size() - 1) sPath += "->";
            }
            res.push_back(sPath);
            return;
        }
        if (root->left) {
            backTracking(root->left, path, res);
            path.pop_back();
        }
        if (root->right) {
            backTracking(root->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (!root) return res;
        backTracking(root, path, res);
        return res;
    }
};