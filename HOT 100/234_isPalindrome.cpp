//https://leetcode-cn.com/problems/palindrome-linked-list/
#include <type_traits>
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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int n = vec.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (vec[i] != vec[j]) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* mid = midOfList(head);
        ListNode* last = reverseList(mid->next);
        ListNode* p1 = head;
        ListNode* p2 = last;
        bool result = true;
        while (p1 && p2) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        mid->next = reverseList(last);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* midOfList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};