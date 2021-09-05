#include "head.h"
int rand7(){

    return (int)(1 + 6 * (rand() / double(RAND_MAX)));
}
class Solution {
public:
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};


int main(){
    Solution s;
    for(int i = 0; i < 10; i++){
        cout << s.rand10() << endl;
    }
    return 0;
}