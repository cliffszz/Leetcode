//https://leetcode-cn.com/problems/sort-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//自顶向下归并排序，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while (temp1 && temp2) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1) {
            temp->next = temp1;
        } else {
            temp->next = temp2;
        }
        return dummy->next;
    }
};

//自底向上归并排序，时间复杂度O(nlogn)，空间复杂度O(1)
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int len = 0;
        ListNode* node = head;
        while (node) {
            len++;
            node = node->next;
        }
        ListNode* dummy = new ListNode(-1, head);
        for (int subLen = 1; subLen < len; subLen *= 2) {
            ListNode* pre = dummy;
            ListNode* cur = dummy->next;
            while (cur) {
                ListNode* head1 = cur;
                for (int i = 1; i < subLen && cur->next; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < subLen && cur && cur->next; i++) {
                    cur = cur->next;
                }
                ListNode* next = nullptr;
                if (cur) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                pre->next = merged;
                while (pre->next != nullptr) {
                    pre = pre->next;
                }
                cur = next;
            }
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while (temp1 && temp2) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1) {
            temp->next = temp1;
        } else {
            temp->next = temp2;
        }
        return dummy->next;
    }
};