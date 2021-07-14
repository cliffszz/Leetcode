//https://leetcode-cn.com/problems/design-linked-list/
class MyLinkedList {
private:
    struct ListNode {   
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    };
    int size = 0;
    ListNode* head = new ListNode(0);
    ListNode* tail = new ListNode(0);
public:
    MyLinkedList() {
        head->next = tail;
        head->prev = tail;
        tail->prev = head;
        tail->next = head;
    }

    int get(int index) {
        if (index >= size) return -1;
        ListNode* cur = head->next;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->val;
    }
    

    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        ListNode* cur = head->next;
        newHead->next = cur;
        newHead->prev = head;
        cur->prev = newHead;
        head->next = newHead;
        size++;
    }
    

    void addAtTail(int val) {
        ListNode* newTail = new ListNode(val);
        ListNode* cur = tail->prev;
        newTail->next = tail;
        newTail->prev = cur;
        cur->next = newTail;
        tail->prev = newTail;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode* cur = head->next;
        ListNode* newNode = new ListNode(val);
        for (int i = 0; i < index; i++) cur = cur->next;
        ListNode* prev = cur->prev;
        newNode->prev = prev;
        newNode->next = cur;
        cur->prev = newNode;
        prev->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        ListNode* cur = head->next;
        for (int i = 0 ; i < index; i++) cur = cur->next;
        ListNode* prev = cur->prev;
        ListNode* next = cur->next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        size--;
    }
};