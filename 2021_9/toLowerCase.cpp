#include "head.h"
class Solution {
public:
    string toLowerCase(string s) {
        int delta = 'a' - 'A';
        for(auto & c: s){
            if(c >= 'A' && c <='Z'){
                c += delta;
            }
        }
        return s;
    }
};