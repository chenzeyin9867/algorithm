#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream strStream(s);
        int length = -1;
        string tmp;
        while(strStream >> tmp){
            length = tmp.size();
        }
        if(s.empty()) return 0;
        return length;
    }
};