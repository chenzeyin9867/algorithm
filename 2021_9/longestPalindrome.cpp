#include "head.h"
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> cnt;
        for(char t: s){
            cnt[t]++;
        }
        int maxoddCnt = 0;
        int sum = 0;
        int flag = 0;
        for(auto k : cnt){
            // cout << k.first << ":" << k.second << endl;
            if(cnt[k.first] % 2 == 0){
                sum += cnt[k.first];
            }else{
                sum += cnt[k.first]-1;
                flag = 1; // exists odd
            }
        }
        return sum + flag;
    }
};

int main(){
    Solution s;
    string str = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    s.longestPalindrome(str);
    return 0;
}