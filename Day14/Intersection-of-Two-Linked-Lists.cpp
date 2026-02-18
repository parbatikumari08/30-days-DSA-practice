#include <unordered_set>
using namespace std;
struct ListNode { int val; ListNode* next; };

ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    unordered_set<ListNode*> st;
    while(a){ st.insert(a); a = a->next; }
    while(b){
        if(st.count(b)) return b;
        b = b->next;
    }
    return nullptr;
}
