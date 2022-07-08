#include "head.h"
/* Node on List */
typedef struct ListNode_t{
    int m_key_;
    int m_val_;
    struct ListNode_t* next;
    struct ListNode_t* prev;
    ListNode_t(int key, int val): m_key_(key), m_val_(val), 
                            next(nullptr), prev(nullptr){
    }
}ListNode_t;

/* List to store the ListNode_t */
class List{
public: 
    List(): m_head_(nullptr), m_tail_(nullptr){
    } 
    
    /* Push a Node to the head of the List */
    void pushFront(ListNode_t *node){
        if(!m_head_){
            m_head_ = node;
            m_tail_ = node;
            return;
        }
        ListNode_t *tmp = m_head_;
        m_head_ = node;
        m_head_->next = tmp;
        tmp->prev = m_head_;
        return;
    }

    /* Remove a node from the List */
    void remove(ListNode_t *node){
        ListNode_t *prev_node = node->prev;
        ListNode_t *next_node = node->next;
        if(node == m_head_ && node == m_tail_){
            m_head_ = m_tail_ = nullptr;
        }
        else if(node == m_head_){    // head
            m_head_ = next_node;
            next_node->prev = m_head_;
        }
        else if(node == m_tail_){
            m_tail_ = prev_node;
            m_tail_->next = nullptr;
        }else{
            /* Mid Node */
            prev_node->next = next_node;
            next_node->prev = prev_node;
        }
        node->prev = node->next = nullptr;
    }

    
public:
    ListNode_t *m_head_;
    ListNode_t *m_tail_;
    
};

class LRUCache {
public:
    LRUCache(int capacity): m_capacity_(capacity), m_size_(0), m_list_(new List()) {
    }
    
    int get(int key) {
        if(m_node_map_.find(key) == m_node_map_.end()){
            return -1;
        }else{
            ListNode_t *node = m_node_map_[key];
            int ret = node->m_val_;
            m_list_->remove(node);
            m_list_->pushFront(node);
            m_node_map_[key] = m_list_->m_head_;
            return ret;
        }
    }
    
    void put(int key, int value) {
        if(m_node_map_.find(key) != m_node_map_.end()){
            /* Already in List */
            ListNode_t *node = m_node_map_[key];
            node->m_val_ = value;
            m_list_->remove(node);
            m_list_->pushFront(node);
            m_node_map_[key] = m_list_->m_head_;
        }else{
            /* Not Full */
            ListNode_t *node = new ListNode_t(key, value);
            if(m_size_ < m_capacity_){
                // std::cout << "New a Node" << std::endl;
                ++m_size_;
                m_list_->pushFront(node);
                // std::cout << "Push Front " << std::endl;
                m_node_map_[key] = m_list_->m_head_;
                std::cout << "Finish New a Node" << std::endl;
            }else{
                /* m_size_ == m_capacity_ */
                ListNode_t *tail_node = m_list_->m_tail_;
                m_node_map_.erase(tail_node->m_key_);
                m_list_->remove(tail_node);
                delete tail_node;
                m_list_->pushFront(node);
                m_node_map_[key] = m_list_->m_head_;                
            }
        }
    }

private:
    uint64_t m_capacity_;
    uint64_t m_size_;
    List *m_list_;
    unordered_map<int, ListNode_t*> m_node_map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    // LRUCache *obj = new LRUCache(2);
    LRUCache lRUCache = LRUCache(2);
    std::cout << "Initialize the LRUCache. " << std::endl;
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    std::cout << "Success to Put." << std::endl;
    std::cout << "1:" <<  lRUCache.get(1) << std::endl;   // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    std::cout << "2:" <<  lRUCache.get(2) << std::endl;  // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    std::cout << "1:" <<  lRUCache.get(1) << std::endl;   // 返回 -1 (未找到)
    std::cout << "3:" <<  lRUCache.get(3) << std::endl;  // 返回 3
    std::cout << "4:" <<  lRUCache.get(4) << std::endl;   // 返回 4
}

