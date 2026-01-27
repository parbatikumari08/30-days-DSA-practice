struct ListNode { int val; ListNode* next; };

ListNode* reverseList(ListNode* h){
    ListNode* prev=nullptr;
    while(h){
        auto nxt=h->next;
        h->next=prev;
        prev=h;
        h=nxt;
    }
    return prev;
}

void reorderList(ListNode* head) {
    if(!head || !head->next) return;

    ListNode *slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode* second = reverseList(slow);
    ListNode* first = head;

    while(second->next){
        auto t1 = first->next;
        auto t2 = second->next;

        first->next = second;
        second->next = t1;

        first = t1;
        second = t2;
    }
}
