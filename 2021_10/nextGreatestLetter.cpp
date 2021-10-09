#include "head.h"
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = -1;
        for(int i = 0; i < letters.size(); ++i){
            if(target < letters[i]){
                return letters[i];
            }
        }
        return letters[0];
    }
};