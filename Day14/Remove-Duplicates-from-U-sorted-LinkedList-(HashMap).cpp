#include <unordered_set>
using namespace std;

struct ListNode { int val; ListNode* next; };

ListNode* removeDuplicates(ListNode* head) {
    unordered_set<int> st;
    ListNode dummy(0); dummy.next = head;
    ListNode* cur = &dummy;

    while(cur->next){
        if(st.count(cur->next->val)){
            cur->next = cur->next->next;
        } else {
            st.insert(cur->next->val);
            cur = cur->next;
        }
    }
    return dummy.next;
}
