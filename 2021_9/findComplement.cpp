#include "head.h"
class Solution {
public:
    int findComplement(int num) {
        int high = 0;
        for(int i = 1; i < 32; i++){
            if(num >> i) high = i;
        }
        
        int andNum = 1;
        for(int i = 1; i <= high; i++){
            andNum = andNum + (0x1 << i);
        }
        // cout << high << " "  << endl;
        // printf("%x\n", andNum);
        return (~num) & andNum;
    }
};

int main(){
    Solution s;
    cout << s.findComplement(1) << endl;
    return 0;
}