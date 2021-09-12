#include "head.h"
class Solution {
public:
    bool checkValidString(string s) {  
        vector<char> stk;
        // int numStar = 0;
        // int numRight = 0;
        for(auto c:s){
            if(c == '*' || c == '('){
                stk.push_back(c);
            }else{
                // for(int i =
                auto it = stk.rbegin();
                while(it != stk.rend()){
                    if(*it == '(') break;
                    ++it;
                }
                if(it == stk.rend()){
                    auto itStar = stk.rbegin();
                    while(itStar != stk.rend()){
                        if(*itStar == '*') break;
                        ++itStar;
                    }
                    if(itStar == stk.rend()){
                        return false;
                    }
                    stk.erase((++itStar).base());
                }else{
                    stk.erase((++it).base());
                }
            }
        }
        //handle the stk left part

        stack<char> handler;
        for(auto c:stk){
            if(c == '*'){
                if(!handler.empty()){
                    handler.pop();
                }
            }else{
                handler.push('(');
            }
        }
        // while(!handler.empty()){
        //     cout << handler.top() << endl;
        //     handler.pop();
        // }
        return handler.empty();    
    }
};

int main(){
    Solution s;
    string str{"((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"};
    cout << s.checkValidString(str) << endl;
    return 0;

    
}

