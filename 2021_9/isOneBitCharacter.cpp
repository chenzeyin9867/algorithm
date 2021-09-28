#include "head.h"
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while(i < bits.size()){
            if(bits[i] ==1){
                i = i + 2;
            }else if(bits[i] == 0){
                if(i < bits.size() - 1){
                    ++i;
                }else if ( i == bits.size() - 1){
                    return true;
                }
            }
        }
        return false;
    }
};