//https://leetcode-cn.com/problems/add-two-numbers/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        ListNode* tail;
        while (l1 && l2) {
            l1->val += l2->val;
            if (l1->val >= 10) {
                l1->val -= 10;
                if (l1->next) l1->next->val++;
                else {
                    ListNode* tmp = new ListNode(1);
                    l1->next = tmp;
                }
            }
            if (!l1->next) {
                tail = l1;
            }
            else if(!l2->next) tail = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) tail->next = l2;
        else {
            while (l1) {
                if (l1->val >= 10) {
                    l1->val -= 10;
                    if (l1->next) l1->next->val++;
                    else {
                        ListNode* tmp = new ListNode(1);
                        l1->next = tmp;
                    }
                }
                l1 = l1->next;
            }
        } 
        return res;
    }
};