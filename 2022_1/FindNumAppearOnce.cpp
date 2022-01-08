class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int> ans;
        int n = array.size();
        int s = 0;    // a ^ b
        for(int i = 0; i < n; i++) s ^= array[i];
        int mask = lowbit(s);
        int a = 0, b;
        for(int i = 0; i < n; i++){
            if(mask & array[i]) a ^= array[i];
            }
        b = s ^ a;
        ans.push_back(a);
        ans.push_back(b);
        if(ans[0] > ans[1]) swap(ans[0], ans[1]);
        return ans;
    }
 
    int lowbit(int x){
        return x & -x;
    }
};
