#include "head.h"
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if( n == 0) return true;
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0) --n;
            return n == 0;
        }
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){

                if(i == 0){
                        if(flowerbed.size() > 1 && flowerbed[1] == 0){
                            flowerbed[0] = 1;
                            --n;
                            // if(n == 0) break;
                        }
                    }
                    else if ( i == flowerbed.size() - 1 && flowerbed[i-1]==0){
                        flowerbed.back() = 1;
                        --n;
                        
                    }else{
                        if( flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                            flowerbed[i] = 1;
                            --n;
                        }
                    }
            }
  
            if(n == 0) break;
        }
        return n == 0;
    }
};