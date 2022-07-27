#include "head.h"
/* Implement a randomized set, requires each operation's avg complexity is O(1) */
class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m_map_.find(val) != m_map_.end()) return false;
        m_arr_.push_back(val);
        m_map_.insert({val, m_arr_.size() - 1});
        return true;
    }
    
    bool remove(int val) {
        if(m_map_.find(val) == m_map_.end()) return false;
        int idx = m_map_[val];
        int end = m_arr_.back();
        m_map_[end] = idx;
        m_map_.erase(val);
        std::swap(m_arr_[idx], m_arr_.back());
        m_arr_.pop_back();
        return true;
    }
    
    int getRandom() {
        int rdn_idx = rand() % m_arr_.size();
        return m_arr_[rdn_idx];
    }

    unordered_map<int, int> m_map_;
    vector<int> m_arr_;
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */