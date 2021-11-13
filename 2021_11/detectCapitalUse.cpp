#include "head.h"
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        // Length > 2
        bool capital = (word[0] >= 'A' && word[0] <= 'Z');
        bool capital2 = (word[1] >= 'A' && word[1] <= 'Z');
        if(!capital && capital2) return false; //'aZ' like words
        for(size_t i = 2; i < word.size(); ++i){
            char c = word[i];
            if(capital){
                if(capital2){
                    if(c >= 'a' && c <='z'){
                        return false;
                    }
                }else{
                    if(c >= 'A' && c <= 'Z'){
                        return false;
                    }
                }
            }else{
                if(c >= 'A' && c <= 'Z') return false;
            }
        } 
        return true;
    }
};