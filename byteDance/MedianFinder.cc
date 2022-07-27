#include "head.h"
class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(heap1.empty()){
            heap1.push(num);
        }else{
            if(num <= heap1.top()){
                heap1.push(num);
                if(heap1.size() >= heap2.size() + 2){
                    int x = heap1.top();
                    heap1.pop();
                    heap2.push(x);
                }
            }else{
                heap2.push(num);
                if(heap1.size() + 2 <= heap2.size()){
                    int x = heap2.top();
                    heap2.pop();
                    heap1.push(x);
                }
            }
        }
    }
    
    double findMedian() {
        if(heap1.size() == heap2.size()){
            double x = heap1.top(), y = heap2.top();
            cout << "h1:" << heap1.top() << "  h2:" << heap2.top() << endl;
            return static_cast<double>((x + y) / (double)2.0);
        }else if(heap1.size() > heap2.size()){
            return heap1.top();
        }else{
            return heap2.top();
        }
    }

    priority_queue<int, vector<int>, less<int>> heap1; // max heap
    priority_queue<int, vector<int>, greater<int>> heap2; // little heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */