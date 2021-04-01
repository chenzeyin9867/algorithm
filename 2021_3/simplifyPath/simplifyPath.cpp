#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack <string> pStack;
        vector<string> pResult;
        int len = path.size();
        int i = 1;
        int prev_i = i;
        string cur="";
        while((i=path.find('/',i)) != string::npos){
            string med = path.substr(prev_i, i - prev_i);
            // cout << med << endl;
            prev_i = i + 1;
            i = i+1;
            if(med == ".."){
                if(pResult.size()){
                    pResult.pop_back();
                }
            }else if(med == "."){
                
            }else{
                if(med !="")
                pResult.push_back(med);
            }
        }
        string med;
        // cout << path.substr(prev_i, path.size() - prev_i) << endl;
        if(path.back()!='/'){
            med = path.substr(prev_i, path.size() - prev_i);
            // cout << med << endl;
            if(med == ".." ) 
            {
                if(pResult.size()) pResult.pop_back();
            }
            else if(med == ".");
            else pResult.push_back(path.substr(prev_i, path.size() - prev_i));
        }
        string result = "/";
        // reverse(r.begin(), r.end());
        for(int i = 0; i < pResult.size(); i++){
            result += pResult[i];
            if(i!= pResult.size()-1)
                result += '/';
        }
        // cout << "here" << endl;
        // result.erase(result.end()-1);
        // cout <<"s" << endl;
        return result;
    }
};

int main(){
    Solution s;
    string path;
    cin >> path;
    cout << s.simplifyPath(path) << endl;
    return 0;
    
}