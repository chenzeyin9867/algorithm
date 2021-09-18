#include "head.h"
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> line1{'Q','W','E','R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        unordered_set<char> line2{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        unordered_set<char> line3{'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
        vector<string> result;
        int f = 0;
        int delta = 'a' - 'A';
        for(auto w : words){
            int consist = 1;
            char c1 = w[0];
            if(line1.find(c1)!=line1.end() || line1.find(c1 - delta) != line1.end()){
                f = 1;
            }
            if(line2.find(c1)!=line2.end() || line2.find(c1 - delta) != line2.end()){
                f = 2;
            }
            if(line3.find(c1)!=line1.end() || line3.find(c1 - delta) != line3.end()){
                f = 3;
            }
            unordered_set<char> tmp;
            if(f == 1){
                    tmp = line1;
                }else if(f == 2){
                    tmp = line2;
                }else{
                    tmp = line3;
                }
            for(auto c: w){
                if(tmp.find(c) == tmp.end() && tmp.find(c - delta) == tmp.end()){
                    consist = 0;
                    break;
                }
                
            }
            if (consist){
                result.emplace_back(w);
            }
        }
        return result;
    }
};
