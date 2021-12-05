#include "head.h"
class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        int i = 0;
        stack<char> stk;
        string ret;
        string cur;
        while(i < len){
            if(s[i] != ']'){
                if(s[i] == '[') stk.push(s[i]);
                else{
                    if(stk.empty() && isalpha(s[i])) ret.push_back(s[i]);
                    else stk.push(s[i]);
                }

            }else if(s[i] == ']'){
                string temp; 
                char c;
                while((c = stk.top()) != '['){
                    temp.insert(temp.begin(), c);
                    stk.pop();
                }
                // a '['
                stk.pop();
                string num;
                while(!stk.empty() && isdigit(stk.top())){
                    num.push_back(stk.top());
                    stk.pop();
                }
                reverse(num.begin(), num.end());
                
                int repeat_num = atoi(num.c_str());
                // stk.pop();
                for(int j = 0; j < repeat_num; ++j){
                    cur.append(temp);
                }
                // cout << cur << endl;
                if(stk.empty()){
                    ret.append(cur);
                }else{
                    for(auto &ch: cur){
                        stk.push(ch);
                    }
                }
                cur = "";
            }
            ++i;
        }
        return ret;        
    }

};

/**
 * @brief recursive version
 */
// class Solution {
// public:
//     string src; 
//     size_t ptr;

//     int getDigits() {
//         int ret = 0;
//         while (ptr < src.size() && isdigit(src[ptr])) {
//             ret = ret * 10 + src[ptr++] - '0';
//         }
//         return ret;
//     }

//     string getString() {
//         if (ptr == src.size() || src[ptr] == ']') {
//             // String -> EPS
//             return "";
//         }

//         char cur = src[ptr]; int repTime = 1;
//         string ret;

//         if (isdigit(cur)) {
//             // String -> Digits [ String ] String
//             // 解析 Digits
//             repTime = getDigits(); 
//             // 过滤左括号
//             ++ptr;
//             // 解析 String
//             string str = getString(); 
//             // 过滤右括号
//             ++ptr;
//             // 构造字符串
//             while (repTime--) ret += str; 
//         } else if (isalpha(cur)) {
//             // String -> Char String
//             // 解析 Char
//             ret = string(1, src[ptr++]);
//         }
        
//         return ret + getString();
//     }

//     string decodeString(string s) {
//         src = s;
//         ptr = 0;
//         return getString();
//     }
// };



int main(){
    Solution s;
    string str = "abc3[cd]xyz";
    cout << s.decodeString(str) << endl;
    return 0;
}