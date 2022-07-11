#include "head.h"
/**
 * Used to model a trie tree.
 */
struct Node_t{
    char m_char_;
    bool m_end_;
    vector<struct Node_t*> m_branches_;
    Node_t(char ch): m_char_(ch), m_end_(false){
        m_branches_.resize(26, nullptr);
    } 
};

class Trie {
public:
    Trie() {
        m_root_ = new Node_t('1');
    }
    
    void insert(string word) {
        int l = 0;
        Node_t *cur = m_root_;
        while(l < word.size()){
            if(cur->m_branches_[word[l]-'a']){
                cur = cur->m_branches_[word[l]-'a'];
            }else{
                /* create a new Node_t */
                Node_t *new_Node_t = new Node_t(word[l]-'a');
                // cout << "create " << word[l] - 'a' << endl;
                cur->m_branches_[word[l]-'a'] = new_Node_t;
                cur = new_Node_t;
            }
            ++l;
        }
        cur->m_end_ = true;
        return;
    }
    
    bool search(string word) {
        int l = 0;
        Node_t *cur = m_root_;
        while(l < word.size()){
            if(!cur->m_branches_[word[l]-'a']){
                return false;
            }else{
                // ++l;
                cur = cur->m_branches_[word[l]-'a'];
                ++l;
            }
        }
        /* Even though found, not end */
        return cur->m_end_;
    }
    
    bool startsWith(string prefix) {
        int l = 0;
        Node_t *cur = m_root_;
        while(l < prefix.size()){
            if(!cur->m_branches_[prefix[l]-'a']){
                return false;
            }else{
                // ++l;
                cur = cur->m_branches_[prefix[l]-'a'];
                ++l;
            }
        }
        return true;
    }

    Node_t *m_root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie trie = Trie();
    trie.insert("apple");
    cout << "insert apple " << endl;  // 返回 True
    cout << "found apple: " << trie.search("apple") << endl;
    cout << "found app: " << trie.search("app") << endl;     // 返回 False
    cout << "start with app :" << trie.startsWith("app") << endl; // 返回 True
    trie.insert("app");
    cout << "found app : " << trie.search("app") << endl;     // 返回 True 
}