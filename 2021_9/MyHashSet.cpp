#include "head.h"
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        numList.resize(100); // design 100 bucktes
    }
    
    void add(int key) {
        int tmp = key;
        key = key % 100; // put into current bucket
        vector<int> &v = numList[key];
        if(find(v.begin(), v.end(), tmp) == v.end()){
            v.emplace_back(tmp);
        }
        cout << "add:" << tmp << endl;
    }
    
    void remove(int key) {
        int tmp = key;
        key = key % 100; // put into current bucket
        vector<int> &v = numList[key];
        // if((std::vector<int>::iterator it = find(v.begin(), v.end(), tmp)) != v.end()){
            
        // }
        cout << "erase:" << ((find(v.begin(), v.end(), tmp) == v.end()) ? to_string(tmp) : "failer" ) << endl;
        auto it = find(v.begin(), v.end(), tmp);
        if(it != v.end()){
            cout << "remove:" << tmp << endl;
            v.erase(it);
        }else{
            cout << "remove fail" << endl;
        }
        // v.erase(find(v.begin(), v.end(), tmp));
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int tmp = key;
        key = key % 100; // put into current bucket
        vector<int> &v = numList[key];
        cout << ((find(v.begin(), v.end(), tmp) != v.end()) ? "contains:" : "not contains:" )<< tmp << endl; 
        return find(v.begin(), v.end(), tmp) != v.end();
    }

    vector<vector<int>> numList;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */