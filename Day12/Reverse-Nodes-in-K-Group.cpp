struct ListNode { int val; ListNode* next; };

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cur = head;  
    int cnt = 0;
    while(cur && cnt < k) cur = cur->next, cnt++;
    if(cnt < k) return head;

    cur = reverseKGroup(cur, k);
    while(cnt--){
        ListNode* nxt = head->next;
        head->next = cur;
        cur = head;
        head = nxt;
    }
    return cur;
}
