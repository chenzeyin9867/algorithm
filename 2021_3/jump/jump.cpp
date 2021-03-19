#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump[100000] = {0};
        int len = nums.size();
        jump[len - 1] = 0;
        for(int i = len - 2; i >= 0 ; i--){
            int gap = nums[i];
            // cout << "gap" << gap << endl;
            int min = 10000;
            for(int j = i + gap; j >= 1 + i; j--){
                if(j > len){continue;}
                if(jump[j] + 1 < min){
                    min = jump[j] + 1;
                }
            }
            jump[i] = min;
            // cout << min << endl;
        }
        for (int i = 0; i< len; i++){
            // cout << jump[i] << " " ;
        }
        // cout << endl;
        return jump[0];
    }
};
int main(){
    Solution s;
    
    vector<int> jump1{2,3,1,1,4,2,3,4,5,2,3,2,1,3,2};
    cout << s.jump(jump1) << endl;
}