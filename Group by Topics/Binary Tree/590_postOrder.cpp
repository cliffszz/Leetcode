//https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if (cur->children.size() > 0) {
                for (int i = 0; i < cur->children.size(); i++) {
                    if (cur->children[i]) stk.push(cur->children[i]);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};