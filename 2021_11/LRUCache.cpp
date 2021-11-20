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
    DNode(int k, int v): key_(k), value_(v), next_(nullptr), prev_(nullptr){}
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
    DNode* get_head(){
        return head_;
    }
    DNode* get_tail(){
        return tail_;
    }
private:
    DNode* head_;
    DNode* tail_;
};

void DList::push_front(DNode* node){
    if(!head_){
        /* empty list */
        head_ = node;
        tail_ = node;
        return;
    }
    node->next_ = head_;
    node->prev_ = nullptr;
    head_->prev_ = node;
    head_ = node;
}

void DList::push_back(DNode* node){
    if(!tail_){
        head_ = tail_ = node;
        return;
    }
    tail_->next_ = node;
    node->prev_ = tail_;
    node->next_ = nullptr;
    tail_ = node;
}

void DList::pop_front(){
    if(head_ == tail_){
        head_ = tail_ = nullptr;
        return;
    }
    // DNode *t = head_;
    head_ = head_->next_;
    head_->prev_ = nullptr;
    // delete t;
}

void DList::pop_back(){
    if(head_ == tail_){
        head_ = tail_ = nullptr;
        return;
    }
    // DNode *t = tail_;
    tail_ = tail_->prev_;
    tail_->next_ = nullptr;
}

/* delete a mid-node */
void DList::delete_node(DNode* node){
    if(!node->prev_) {
        pop_front();
        return;
    }
    if(!node->next_) {
        pop_back();
        return;
    }
    /* mid case */
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
    node->prev_ = node->next_ = nullptr;
    
}

class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity), size_(0) {

    }
    
    int get(int key) {
        /* not exist */
        if(!node_map_.count(key)) return -1;
        else{
            DNode* cur = node_map_[key];
            int val = cur->value_;
            /* move to last */
            node_list_.delete_node(cur);
            node_list_.push_back(cur);
            return val;
        }

    }
    
    void put(int key, int value) {
        /* whether has index */
        if(!node_map_.count(key)){  /* add this index into map */
            if(size_ < capacity_){
                DNode* cur = new DNode(key, value);
                node_list_.push_back(cur);
                node_map_.insert(make_pair(key, node_list_.get_tail()));
                ++size_;
            }else{
                /* remove the first item in list, add this to last */
                DNode *head = node_list_.get_head();
                node_list_.pop_front();
                /* remove in hashMap */
                node_map_.erase(head->key_);
                delete head;
                /* add new item */
                DNode* cur = new DNode(key, value);
                node_list_.push_back(cur);
                node_map_.insert(make_pair(key, node_list_.get_tail()));
            }
        }else{
                DNode* cur = node_map_[key];
                cur->value_ = value;
                node_list_.delete_node(cur);
                node_list_.push_back(cur);
                
                
        }
    }


    DList node_list_;
    unordered_map<int, DNode*> node_map_;
    int capacity_;
    int size_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    // cout << "Hello World" << endl;
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl;    // 返回 3
    cout << lRUCache.get(4) << endl;    // 返回 4
    return 0;

}