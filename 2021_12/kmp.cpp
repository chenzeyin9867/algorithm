/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "head.h"
class Solution {
public:
    int strStr(string haystack, string needle) {
        // implement a kmp method
        if(needle.size() == 0) return 0;
        if(needle.size() > haystack.size()) return -1;
        // create the next() array
        vector<int> next_arr;
        next_arr.push_back(0);
        int i = 1;
        int now = 0;
        while(i < needle.size()){
            if(needle[now] == needle[i]){
                ++i;
                ++now;
                next_arr.push_back(now);
            }else if(now > 0){
                now = next_arr[now-1];
            }else{
                next_arr.push_back(0);
                ++i;
            }
        }
        for(auto &n : next_arr){
            cout << n << "->";
        }
        cout << endl;
        // next() arr initialize
        // start search
        int tar = 0; // pos in haystack 
        int pos = 0; // pos in needle
        while(tar < haystack.size()){
            if(haystack[tar] == needle[pos]){
                ++pos;
                ++tar;
            }else if(pos == 0){
                ++tar;
                // ++pos;
            }else{
                pos = next_arr[pos-1];
            }
            if(pos == needle.size()) return tar - pos;
        }
        return -1;
    }
};