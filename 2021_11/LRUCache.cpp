/**
 * @file LRUCache.cpp
 * @author chenzeyin 
 * @brief 
 * @version 0.1
 * @date 2021-11-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "head.h"

class DNode{

public:
    DNode(int k, int v): key_(k), value_(v){}
public:
    int key_;
    int value_;
    DNode* next_, *prev_;
};
/**
 * @brief double Linked List
 * 
 */
class DList{
public:
    DList(): head_(nullptr), tail_(nullptr){}
    void push_front(DNode*);
    void push_back(DNode*);
    void pop_front();
    void pop_back(); 
    void delete_node(DNode*);   
public:
    DNode* head_;
    DNode* tail_;
};

void DList::push_front(DNode* node){
    node->next_ = head_;
    node->prev_ = nullptr;
    head_->prev_ = node;
    head_ = node;
}

void DList::push_back(DNode* node){
    tail_->next_ = node;
    node->prev_ = tail_;
    node->next_ = nullptr;
    tail_ = node;
}

void DList::pop_front(){
    head_ = head_->next_;
    head_->prev_ = nullptr;
}

void DList::pop_back(){
    tail_ = tail_->prev_;
    tail_->next_ = nullptr;
}

/* delete a mid-node */
void DList::delete_node(DNode* node){
    if(!node->prev_) pop_front();
    if(!node->next_) pop_back();
    /* mid case */
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
    
}

class LRUCache {
public:
    LRUCache(int capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4
    return 0;

}