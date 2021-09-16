#include "head.h"
class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): chilrden(vector<Trie*>(26, nullptr)), end(false){
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(auto w: word){
            int delta = w - 'a';
            if(cur->chilrden[delta]){
                cur = cur->chilrden[delta];
            }else{
                Trie* node = new Trie();
                node->val = w;
                cur->chilrden[delta] = node;
                cur = node;
            }
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(auto c: word){
            if(!cur->chilrden[c-'a']){
                return false;
            }
            cur = cur->chilrden[c-'a'];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(auto c: prefix){
            if(!cur->chilrden[c-'a']){
                return false;
            }
            cur = cur->chilrden[c-'a'];
        }
        return true;
    }

    vector<Trie*>chilrden;
    char val;
    bool end;
};

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << boolalpha;
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
    return 0;
}