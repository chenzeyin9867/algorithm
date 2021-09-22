#include "head.h"
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int len = 0;
        while(cur){
            ++len;
            cur = cur->next;
        }
        vector<ListNode*> result;
        int segLength = 0;
        int tailLength = 0;
        if(k >= len){
            segLength = 1;
            tailLength = 0;
        }else{
            segLength = len / k;
            tailLength = len % k;
        }
        
        ListNode* prev = head;
        cur = head;
        for(int i = 0; i < k; i++){
            if(cur == nullptr){
                result.emplace_back(nullptr);
            }else{
                
                int remain = segLength - 1;
                if(tailLength){
                    remain += 1;
                    tailLength --;
                } 
                while(remain && cur){
                    cur = cur->next;
                    --remain;
                }
                ListNode* tmp = cur;
                cur = tmp->next;
                tmp->next = nullptr;
                result.emplace_back(prev);
                prev = cur;
            }
        }
        return result;
    }
};