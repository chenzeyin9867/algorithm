#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int i = 0; i < numRows; i++){
            vector<int> cur;
            for (int j = 0; j <= i; j ++){
                if(j == 0 || j == i){
                    cur.push_back(1);
                }else{
                    cur.push_back(result[i-1][j-1] + result[i-1][j]);
                }
             }
            result.push_back(cur);
        }

        return result;
    }
};


int main(){
    Solution s;
    int row = 5;
    vector<vector<int>> r = s.generate(row);
    for ( auto i: r){
        for( auto j : i){
            cout << j << " " ;
        }
        cout << endl;
    }
    return 0;
}