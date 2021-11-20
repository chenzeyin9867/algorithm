/**
 * @file LRUCache_std_list_version.cpp
 * @author chenzeyin (you@domain.com)
 * @brief Using the std::list to implement this question
 * @version 0.2
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "head.h"

class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {

    }
    
    int get(int key) {
        if(!map_.count(key)) return -1;
        else{
            int r_v = map_[key].first;
            list_.erase(map_[key].second);
            list_.push_back(key);
            map_[key].second = --list_.end();
            return r_v;
        }

    }
    
    void put(int key, int value) {
        if(map_.count(key)){
            map_[key].first = value; /* update the value */
            // map_.erase(map_[key].second);
            list_.erase(map_[key].second);
            list_.push_back(key);
            map_[key].second = (--list_.end());
        }else{
            if(list_.size() < capacity_){
                list_.push_back(key);
                map_.insert(make_pair(key, make_pair(value, --list_.end())));
            }else{
                /* remove the first item in list_ */
                int rm_key = list_.front();
                list_.pop_front();
                map_.erase(rm_key);
                list_.push_back(key);
                map_.insert(make_pair(key, make_pair(value, --list_.end())));
                // map_.erase(rm_key);
                // list_.erase(map_[rm_key]);
            }
        }
    }
    
private:
    const int capacity_;
    unordered_map<int, pair<int, std::list<int>::iterator>> map_;
    list<int> list_; /* store the sorting rank */
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */