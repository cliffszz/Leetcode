//https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int s = que.size();
            vector<int> level;
            for (int i = 0; i < s; i++) {
                Node* cur = que.front();
                que.pop();
                level.push_back(cur->val);
                if (cur->children.size() > 0) {
                    for (int j = 0; j < cur->children.size(); j++) {
                        if (cur->children[j]) que.push(cur->children[j]);
                    }
                }
            }
            res.push_back(level);
        }
        return res;
    }
};