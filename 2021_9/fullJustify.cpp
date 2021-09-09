#include "head.h"
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curWordIndex = 0;
        vector<string> result;
        vector<string> perLine;
        int charCnt = 0;
        int wordCnt = 0;
        while(curWordIndex < words.size()){
            // handle each line
            charCnt = 0;
            wordCnt = 0;
            perLine.clear();
            perLine.emplace_back(words[curWordIndex]);
            charCnt += words[curWordIndex].size();
            ++wordCnt;
            ++curWordIndex;
            while(curWordIndex < words.size() && (charCnt + words[curWordIndex].size() + wordCnt) <= maxWidth){
                // add as much words into perline
                perLine.emplace_back(words[curWordIndex]);
                charCnt += words[curWordIndex].size();// one blank space
                ++wordCnt;
                ++curWordIndex;
            }
            // parse per line to add to the result;
            // get space cnt
            int spaceCnt = maxWidth - charCnt;
            int aveSpaceCnt = (wordCnt == 1) ? 0 : spaceCnt / (wordCnt - 1);
            int restSpaceCnt = (wordCnt == 1) ? 0 : spaceCnt % (wordCnt - 1);
            if(curWordIndex >= words.size()) 
            {// last line   
                aveSpaceCnt = 1;
                restSpaceCnt = 0;
            }
            string curResult = perLine[0];
            // cout << curResult << endl;
            for(int i = 0; i < wordCnt - 1; i++){
                int curNum = restSpaceCnt > 0 ? 1:0;
                curResult.append(string(aveSpaceCnt+curNum ,' ') + perLine[i+1]);
                --restSpaceCnt;
            }
            // cout << curResult << endl;
        
            int sz = curResult.size();
            curResult.append(string(maxWidth - sz, ' '));
            result.emplace_back(curResult);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> strs{"What","must","be","acknowledgment","shall","be"};
    printVector(s.fullJustify(strs, 16));
    return 0;
}