//https://leetcode-cn.com/problems/merge-k-sorted-lists/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr) cur->next = l1;
        else cur->next = l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* res = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};