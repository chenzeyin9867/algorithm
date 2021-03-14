#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for(int i= 0; i< digits.size(); i++){
            int cur = digits[digits.size() - 1 - i];
            int tmp = flag; 
            flag = (cur + flag) / 10;
            digits[digits.size() - 1 -i] = (cur + tmp) % 10;
        }
        if( flag == 1){
            digits.insert(digits.begin(),  1);
        }
        return digits;
    }
};
int main(){
    Solution s;
    vector<int> nums = {9,9,9};

    vector<int> ret = s.plusOne(nums); 
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;

}