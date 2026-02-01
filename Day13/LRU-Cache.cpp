#include <unordered_map>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void remove(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert(Node* n){
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
        n->prev = head;
    }

public:
    LRUCache(int capacity){
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(!mp.count(key)) return -1;
        Node* n = mp[key];
        remove(n);
        insert(n);
        return n->val;
    }

    void put(int key, int value){
        if(mp.count(key)){
            remove(mp[key]);
            mp.erase(key);
        }
        if(mp.size() == cap){
            Node* del = tail->prev;
            remove(del);
            mp.erase(del->key);
        }
        Node* n = new Node(key,value);
        insert(n);
        mp[key] = n;
    }
};
