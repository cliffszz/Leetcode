//https://leetcode-cn.com/problems/reverse-linked-list-ii/
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;

        for(int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        ListNode* rightNode = pre;
        for(int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        ListNode* leftNode = pre->next;
        ListNode* curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        reverseLinkedList(leftNode);

        pre->next = rightNode;
        leftNode->next = curr;

        return dummy->next;
    }
};

int main(){

    int left = 2;
    int right = 4;
    vector<int> listOfNode = {1, 2, 3, 4, 5};
    ListNode* listnode[listOfNode.size()];
    ListNode* head = listnode[0];
    for(int i = 0; i < listOfNode.size(); i++){
        listnode[i]->val = listOfNode[i];
        listnode[i]->next = listnode[i + 1];
    }
    Solution solution;

    solution.reverseBetween(head, left, right);

    cout << "[";
    while(head != nullptr) {
        cout << head->val;
        head = head->next;
    }
    cout << "]";

    return 0;
}


