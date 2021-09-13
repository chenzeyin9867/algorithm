#include "head.h"
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        if(a.size() == b.size() && a!=b) return a.size();
        else return max(a.size(), b.size());
    }
};