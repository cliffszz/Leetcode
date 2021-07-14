//https://leetcode-cn.com/problems/linked-list-cycle-ii/
#include <unordered_set>
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while (head) {
            if (set.count(head)) return head;
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};