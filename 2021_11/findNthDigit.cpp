/**
 * @brief       find n'th integer in a string list
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-30
 */
#include "head.h"
class Solution {
public:
    int findNthDigit(int n) {
        int index = 1;
        while(n > 0){
            string cur = to_string(index);
            int inner_index = 0;
            if(n > cur.size()){
                n -= cur.size();
            }else{
                cout << cur[n-1] << endl;
                return cur[n-1] - '0';
            }
            ++index;
        }
        return 0;
    }
};

int main(){
    Solution s;
    cout << s.findNthDigit(11);
    return 0;
}