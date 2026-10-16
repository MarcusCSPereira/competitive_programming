#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, val;
    Node *next, *prev;
    Node(int k, int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    Node *head;
    Node *tail;
    int cap;
    unordered_map <int, Node *> mp;

    void remove(Node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert_begin(Node *n){
        n->next = head->next;
        head->next->prev = n;
        n->prev = head;
        head->next = n;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node *n = mp[key];
        remove(n);
        insert_begin(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *n = mp[key];
            n->val = value;
            remove(n);
            insert_begin(n);
            return;
        }else{
            if(mp.size()==cap){
                Node *last = tail->prev;
                remove(last);
                mp.erase(last->key);
                delete last;
            }
            Node *n = new Node(key,value);
            insert_begin(n);
            mp[key] = n;
            return;
        }
    }
};