#include "head.h"
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> char_arr(26, 0);
        for(auto &c: licensePlate){
            if(isalpha(c)){
                ++char_arr[tolower(c) - 'a'];
            }
        }

        for(int i = 0; i < 26; ++i){
            printf("%c:%d ", 'a'+i, char_arr[i]);
        }
        cout << endl;
        
        string result = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
        for (auto &word: words){
            vector<int> tmp = char_arr;
            for(auto &c : word){
                if(isalpha(c)){
                    --tmp[tolower(c) - 'a'];
                }
            }
            // check is tmp empty
            int flag = 0;
            for(int i =0 ; i < tmp.size(); ++i){
                if(tmp[i] > 0) {
                    flag = 1;
                    break;
                }
            }
            cout << flag << " ";
            if(flag == 0){
                cout << result << " " << result.size() << " " << word << " " << word.size() << endl;
                // if(word.size() < result.size()) {
                //     result = word;
                // }

                result = ((word.size() < result.size()) ? word : result); 
                // result = (result.size() < word.size()) ? result: word;
                cout << result << endl;
            }
        }
        return result;
    
    }
};

int main(){
    Solution s;
    string liscensePlate = "1s3 456";
    vector<string> words{"looks","pest","stew","show"};
    cout << s.shortestCompletingWord(liscensePlate, words) << endl;
    return 0; 
}