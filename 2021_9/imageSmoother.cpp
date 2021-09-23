#include "head.h"
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> result = img;
        for(int i = 0; i < img.size(); ++i){
            for(int j = 0; j < img[0].size(); ++j){
                int newPixel = smooth(img, i, j);
                result[i][j] = newPixel;
            }
        }
        return result;
    }

    int smooth(vector<vector<int>> & img, int r, int c){
        int pixel = 0;
        int cnt = 0;
        for(int i = -1; i <= 1; ++i){
            for(int j = -1; j <=1; ++j){
                int f = 0;
                pixel += getPixel(img, r+i, c + j, f);
                if(f == 1){
                    ++ cnt;
                }
            }
        }
        cout << "r:" << r << " c:" << c << " cnt:" << cnt << endl;
        return pixel / cnt;
    }

    int getPixel(vector<vector<int>> &img, int i, int j, int & flag){
        if(i >= 0 && i < img.size() && j >= 0 && j < img[0].size()){
            flag = 1;
            return img[i][j];
            
        }else{
            return 0;
        }
    }
};