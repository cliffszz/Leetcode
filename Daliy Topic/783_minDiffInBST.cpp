//https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <limits.h>

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
private:
    void inOrder(TreeNode* root, vector<int>& v) {
        if(root == nullptr) return;
        if(root->left != nullptr) inOrder(root->left, v);
        v.push_back(root->val);
        if(root->right != nullptr) inOrder(root->right, v);
    }
    vector<int> inOrderStk(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> res;
        //inOrder(root, res);
        res = inOrderStk(root);
        int minDiff = INT_MAX;
        for(auto n : res) {
            cout << n << " ";
        }
        cout << endl;
        for(int i = 1; i < res.size(); i++) {
            minDiff = min(minDiff, res[i] - res[i - 1]);
        }
        return minDiff;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().minDiffInBST(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}