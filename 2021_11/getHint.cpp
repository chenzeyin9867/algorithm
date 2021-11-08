#include "head.h"
class Solution {
public:
    string getHint(string secret, string guess) {
        // first compute the A num
        std::string result;
        int A = 0;
        int B = 0;
        std::unordered_map<int, int> secret_map;
        std::unordered_map<int, int> guess_map;
        for(size_t i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]) ++A; // right bit and num
            else{
                // storage the different num
                ++secret_map[secret[i]];
                ++guess_map[guess[i]];
            }
        }
        for(auto key: secret_map){
            B += min(key.second, guess_map[key.first]);
        }
        result += to_string(A);
        result.push_back('A');
        result += to_string(B);
        result.push_back('B');
    
        return result; 
    }
};

int main(){
    Solution s;
    std::string secret("1");
    std::string guess("1");
    std::cout << s.getHint(secret, guess) << std::endl;
    return 0; 
}