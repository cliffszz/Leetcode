//https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        string res;
        res.push_back('[');
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur != nullptr) {
                res += (to_string(cur->val) + ',');
                que.push(cur->left);
                que.push(cur->right);
            } else {
                res += "null,";
            }
        }
        res.pop_back();
        res.push_back(']');
        return res;
    }

    std::vector<std::string> split(std::string& s, std::string delim)
    {
        std::vector< std::string > ret;
        size_t last = 0;
        size_t index=s.find_first_of(delim,last);
        while (index != std::string::npos)
        {
            ret.push_back(s.substr(last,index-last));
            last=index+1;
            index=s.find_first_of(delim,last);
        }
        if (index-last>0)
        {
            ret.push_back(s.substr(last,index-last));
        }
        return ret;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[]") return NULL;
        data.erase(data.begin());
        data.erase(--data.end());
        vector<string> vals = split(data,",");
        TreeNode* root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode*> que;
        que.push(root);
        int i = 1;
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if(vals[i] != "null") {
                node->left = new TreeNode(atoi(vals[i].c_str()));
                que.push(node->left);
            }
            i++;
            if(vals[i] != "null") {
                node->right = new TreeNode(atoi(vals[i].c_str()));
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};
