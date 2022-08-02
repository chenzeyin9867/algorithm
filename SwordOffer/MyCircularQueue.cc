#include "basic_head.h"
/** Dequeue Implementation. */
class MyCircularQueue {
public:
    MyCircularQueue(int k): m_size_(k+1) {
        m_q_ = new int[k+1];
        m_front_ = m_rear_ = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        m_q_[m_rear_] = value;
        m_rear_ = (m_rear_ + 1) % m_size_;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        m_front_ = (m_front_ + 1) % m_size_;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return m_q_[m_front_];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return m_q_[(m_rear_-1+m_size_)%m_size_];
    }
    
    bool isEmpty() {
        return m_rear_ == m_front_;
    }
    
    bool isFull() {
        return ((m_rear_ + 1) % m_size_) == m_front_;
    }

    ~MyCircularQueue(){
        delete []m_q_;
    }

private:
    int *m_q_;
    int m_size_;
    int m_front_;
    int m_rear_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */