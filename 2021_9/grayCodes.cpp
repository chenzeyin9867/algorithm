#include "head.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code(100, 0);
        unordered_map<int, int> numCnt;
        vector<int> result;
        result.emplace_back(0);
        numCnt[0] = 1;
        for(int i = 0; i < (int)pow(2, n); i++){
            int modify = 0;
            // if(modify) break;
            for(int j = 0; j < n ;++j){
                // int mo
                if(modify) break;
                vector<int> tmp(code.begin(), code.begin() + n);
                // cout << "here" <<endl;
                // cout << "The tmp:" << tmp.size() << endl;
                // printVector(tmp);
                if(tmp[j] == 0){
                    tmp[j] = 1;
                    int hex = binaryToHex(tmp);
                    // cout << "here1" << endl;
                    if(numCnt[hex] == 0){
                        numCnt[hex] = 1;
                        modify = 1;
                        code = tmp;
                        result.emplace_back(hex);
                        // printVector(tmp);
                    }
                    tmp[j] = 0;
                } 
                if(tmp[j] == 1 && !modify){
                    tmp[j] = 0;
                    int hex = binaryToHex(tmp);
                    if(numCnt[hex] == 0){
                        numCnt[hex] = 1;
                        modify = 1;
                        code = tmp;
                        result.emplace_back(hex);
                        // printVector(tmp);
                    }
                    tmp[j] = 1;
                }
            }
        }
        return result;
    }

    int binaryToHex(vector<int> & binaryList){
        // cout << "come here" << endl;
        
        int sum = 0;
        int prev = 1;
        for(auto i = binaryList.crbegin(); i != binaryList.crend(); ++i){
            // cout << sum << endl;
            sum += (*i) * prev;
            prev *= 2;
        }
        // cout << sum << endl;
        return sum;
    }
};

int main(){
    // int t = 100;
    // vector<int> a(t);
    Solution s;
    printVector(s.grayCode(2));
    return 0;
}