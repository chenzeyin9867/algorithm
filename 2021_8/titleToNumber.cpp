#include "head.h"
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total = 0;
        int len = columnTitle.size();
        for(int i = 0; i < columnTitle.size(); i++){
            int cur = columnTitle[i] - 'A' + 1;
            total = total * 26 + cur;
        }
        return total;

    }
};

int main(){
    Solution s;
    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("AB") << endl;
    cout << s.titleToNumber("ZY") << endl;
    cout << s.titleToNumber("FXSHRXW") << endl;
    return 0;
    
}