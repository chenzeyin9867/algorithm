class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int> day_to_rot;
        int num = days.size();
        int cnt = 0;
        int i = 0;
        while(1){
            if(i < apples.size() && apples[i] != 0){
                day_to_rot[i + days[i]] += apples[i];
            }
            // choose a most likly rot apple to eat
            for(auto &p : day_to_rot){
                if(p.first <= i){
                    day_to_rot.erase(p.first);
                }else{
                    --p.second;
                    ++cnt;
                    if(p.second == 0){
                        day_to_rot.erase(p.first);
                        // ++cnt;
                    }
                    break;
                }
            }
            ++i;
            if(day_to_rot.empty() && i > num) break;
        }
        return cnt;
    }
};