#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string multSingle(string &num1, char num2){
        string result;
        int num = num2 - '0';
        int rent = 0;
        for (int i = num1.size()-1; i >= 0; i-- ){
            int cur = (num1[i] - '0');
            int curNum = cur * num + rent;
            result += (curNum % 10) + '0';
            rent = curNum / 10;
            // cout << cur << " " << num << " " << result << " " << rent << endl;
        }
        if (rent !=0 ){
            result += rent + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    } 

    string add(string &num1, string &num2){
        string result;
        int len1 = num1.size();
        int len2 = num2.size();
        int flag = 0;
        string n1;
        string n2;
        if (len1 > len2){
            n1 = num1;
            n2 = num2;
        }else{
            n1 = num2;
            n2 = num1;
        }
        int i = 0;

        for(;i <= n2.size() - 1; i++ ){
            int cur1 = n2[n2.size()-1-i] - '0';
            int cur2 = n1[n1.size() -1 - i] - '0';
            int curNum = cur1 + cur2 + flag;
            result += curNum % 10 + '0';
            flag = curNum / 10; 
            // cout << cur1 << " "<< cur2 <<" " << curNum << " " << result << " " << flag << endl;
        }
        for (int j = n1.size() - n2.size() - 1; j >= 0 ; j--){
            int cur = n1[j] - '0';
            int curNum = cur + flag;
            result += curNum % 10 + '0';
            flag = curNum / 10;
        }
        if (flag !=0){
            result += flag + '0';
        }
        reverse(result.begin(), result.end());
        return result;

    }

    string multiply(string num1, string num2) {
       int len1 = num1.size();
       int len2 = num2.size();
       if(len1 == 1){
           if(num1[0] == '0')return "0";
           if(num1[0] == '1') return num2;
       }
       if(len2 == 1){
           if(num2[0] == '0') return "0";
           if(num2[0] == '1') return num1;
       }
       string result;
       string former = "0";
       for( int i = num2.size() - 1; i >=0; i--){
           string tmp1 = multSingle(num1, num2[i]);
           int left = num2.size() - 1 - i;
           tmp1.append(left, '0');
           former = add(former, tmp1);
        //    cout << tmp1 << " " << left << " " << tmp1 << " " << former << endl;
       }
       return former;
    }
    

};

int main(){
    Solution s;
    string num1 = "2";
    string num2 = "3";
    // cout << s.multSingle(num1, num2[0]) << endl;
    // cout << s.add(num1, num2) << endl;
    cout << s.multiply(num1, num2) << endl;
}