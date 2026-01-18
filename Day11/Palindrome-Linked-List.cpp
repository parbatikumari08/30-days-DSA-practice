struct ListNode { int val; ListNode* next; };

ListNode* rev(ListNode* head){
    ListNode *prev=nullptr, *cur=head;
    while(cur){ auto nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* second = rev(slow);
    while(second){
        if(head->val != second->val) return false;
        head=head->next;
        second=second->next;
    }
    return true;
}
