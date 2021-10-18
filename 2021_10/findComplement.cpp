class Solution {
public:
    int findComplement(int num) {
        long result = 0;
        long cur = 1;
        while(num){
            long div = num % 2;
            div = (div == 0) ? 1 : 0;
            result = result + cur * div;
            cur *= 2;
            num = num / 2;
        }
        return result;
    }
};