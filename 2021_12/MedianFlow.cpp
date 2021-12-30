class Solution {
public:
    void Insert(int num) {
        if(min_heap.empty() && max_heap.empty()) max_heap.push(num);
        else{
            if(num <= max_heap.top()){
                max_heap.push(num);
                if(max_heap.size() - min_heap.size() > 1){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }
            }else{
                min_heap.push(num);
                if(min_heap.size() - max_heap.size() > 0){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
        }
    
    }

    double GetMedian() { 
        if((min_heap.size() + max_heap.size()) % 2 == 1){
            return max_heap.top();
        }else{
            return (double)(max_heap.top() + min_heap.top()) / 2.0;
        }
    }
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
};