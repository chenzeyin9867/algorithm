#include "head.h"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        auto t = 0;
        auto n = 0;
        int v1_len = version1.size();
        while(t < v1_len){
            if(version1[n] == '.' || n == v1_len){
                string tmp = version1.substr(t, n-t);
                v1.emplace_back(stoi(tmp));
                t = n + 1;
            }
            n++;
        } 

        vector<int> v2;
        t = 0;
        n = 0;
        int v2_len = version2.size();
        while(t < v2_len){
            if(version2[n] == '.' || n == v2_len){
                string tmp = version2.substr(t, n-t);
                v2.emplace_back(stoi(tmp));
                t = n + 1;
            }
            n++;
        } 
        printVector(v1);
        printVector(v2);
        int flag = 1;
        if(v1.size() > v2.size()){
            swap(v1, v2);
            flag = -1;
        }

        for(int i = 0; i < v1.size(); i ++){
            if(v1[i] > v2[i]) return flag;
            if(v1[i] < v2[i]) return -flag;
        }

        for(int j = v1.size(); j < v2.size(); j++){
            if(v2[j]) return -flag;
        }

        return 0;
    }
};

int main(){
    Solution s;
    string v1 = "1.00.1";
    string v2 = "1.0.2";
    cout << s.compareVersion(v1, v2) << endl;
    return 0;

}