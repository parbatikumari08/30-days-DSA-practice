struct ListNode { int val; ListNode* next; };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *slow=&dummy, *fast=&dummy;

    while(n--) fast=fast->next;
    fast=fast->next;

    while(fast){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
}
