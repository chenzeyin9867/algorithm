#include "head.h"
bool consistOf(const string & p, const string & c){
    // whether c exist in p
    int i = 0, j = 0;
    // cout << p << " " <<  c << endl;
    while( i < p.size() && j < c.size()){
        if(p[i] == c[j]){
            ++i;
            ++j;
        }else{
            ++i;
        }
    }
    return j >= c.size();
    // cout << "consist" << endl;
    // return true;
    // while(i < p.size() && j < c.size()){
}
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int maxLengthIndex = -1;
        int maxLength = 0;
        for(auto c = dictionary.begin(); c != dictionary.end(); ++c){
            // cout << *c << endl;
            if(consistOf(s, *c)){
                // cout << *c << endl;
                // cout << "true" << endl;
                if((*c).size() >= maxLength){
                    if(maxLengthIndex == -1) maxLengthIndex = c - dictionary.begin();
                    else if((*c).size() == maxLength)
                        maxLengthIndex = (dictionary[c - dictionary.begin()] <= dictionary[maxLengthIndex])? c - dictionary.begin(): maxLengthIndex ;
                    else 
                        maxLengthIndex = c - dictionary.begin();
                    maxLength = (*c).size();
                }
            }
        }
        // cout << maxLength << ": " << dictionary[maxLengthIndex];
        return maxLengthIndex == -1 ? "" : dictionary[maxLengthIndex]; 
    }
};

int main(){
    Solution s;
    vector<string> dic{ "ale","apple","monkey","plea"};
    cout << s.findLongestWord("abpcplea", dic) << endl;
    return 0;
}