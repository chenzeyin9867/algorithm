#include "head.h"
int main(){
    int windows;
    while (cin >> windows){
        int total;
        cin >> total;
        int wait_t = 0;
        vector<int> arrive_time(total, 0);
        vector<int> duration(total, 0);
        for(int i = 0; i< total; ++i){
            cin >> arrive_time[i] >> duration[i];
        }
        
        /* Now we get the arrival time and 
           the duration the custom deal with
           the things. */

        /* Free list stores the free time for each window */
        vector<int> free_list(windows, 0);
        /* Busy list stores the least busy time for each window */ 
        vector<int> busy_list(windows, 0);
        for(int i = 0; i < total; ++i){
            int arrival_t = arrive_time[i];
            int duration_t = duration[i];
            // First to see whether has a busy list 
            int idx = -1;
            int idx_min = 0; 
            for(int j = 0; j < windows; ++j){
                if(busy_list[j] <= arrival_t){
                    if(idx >= 0 && busy_list[j] < busy_list[idx]){
                        idx = j; // means got a longer free time 
                    }else if (idx == -1){
                        idx = j;
                    }
                }
                if(busy_list[j] < busy_list[idx_min]){
                    idx_min = j;
                }
            }
            // If idx != -1, update the info
            if(idx != -1){
                busy_list[idx] = arrival_t + duration_t;
            }else{
                // should wait, use the idx_min windows
                wait_t += busy_list[idx_min] - arrival_t;
                busy_list[idx_min] += duration_t;
            }
        }
        double avg_wait_t = static_cast<double>(wait_t) / static_cast<double>(total);
        cout << "avg wait time:" << avg_wait_t << endl;
    }
    return 0;
}