//https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        int size = 0;
        while (head) {
            head = head->next;
            size++;
        }
        head = dummy;
        for (int i = 0; i < size - n; i++) {
            head = head->next;
        }
        ListNode* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* slow = dummy;
        head = dummy;
        while (n-- && head) {
            head = head->next;
        }
        head = head->next;
        while (head) {
            head = head->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};