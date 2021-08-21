#include "head.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        stk.emplace_back(val);
        if(minstk.size()==0){
            minstk.emplace_back(val);
        }else{
            if(val < minstk.back()){
                minstk.emplace_back(val);
            }else{
                int m = minstk.back();
                minstk.emplace_back(m);
            }
        }
    }
    
    void pop() {
        stk.pop_back();
        minstk.pop_back();

    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minstk.back();
    }

private:
    vector<int> stk;
    vector<int> minstk;
    
};


int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;;   //--> 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;;      //--> 返回 0.
    cout << minStack.getMin() << endl;;   //--> 返回 -2.
    vector<int> a{1,2,3};
    // cout << a[-1] << " " << a[-2] << endl;
    return 0;

}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */