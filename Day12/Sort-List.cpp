struct ListNode { int val; ListNode* next; };

ListNode* merge(ListNode* a, ListNode* b){
    ListNode dummy(0), *cur=&dummy;
    while(a && b){
        if(a->val < b->val) cur->next=a, a=a->next;
        else cur->next=b, b=b->next;
        cur = cur->next;
    }
    cur->next = a ? a : b;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode *slow=head, *fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = nullptr;

    return merge(sortList(head), sortList(mid));
}
