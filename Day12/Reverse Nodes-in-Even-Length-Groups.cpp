struct ListNode { int val; ListNode* next; };

ListNode* reverseEvenLengthGroups(ListNode* head) {
    ListNode dummy(0); dummy.next=head;
    ListNode* prev=&dummy; int size=1;
 
    while(head){
        ListNode* cur=head;
        int cnt=0;

        while(cur && cnt<size) cur=cur->next, cnt++;

        if(cnt%2==0){
            ListNode* rev=cur;
            ListNode* tmp=head;
            for(int i=0;i<cnt;i++){
                ListNode* nxt=tmp->next;
                tmp->next=rev;
                rev=tmp;
                tmp=nxt;
            }
            prev->next=rev;
            prev=head;
            head=cur;
        }else{
            for(int i=0;i<cnt;i++){
                prev=head;
                head=head->next;
            }
        }
        size++;
    }
    return dummy.next;
}
