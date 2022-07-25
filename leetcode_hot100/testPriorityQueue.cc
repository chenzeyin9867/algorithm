#include "head.h"

struct my_t{
    int name;
    int age;
    my_t (int n, int ag): name(n), age(ag){

    }
};

// bool cmp(my_t &t1, my_t &t2){
//     return t1.age < t2.age;    
// }

struct cmp{
    bool operator()(my_t &t1, my_t &t2){
        if(t1.age == t2.age) return t1.name < t2.name;
        return t1.age < t2.age;
    }
};


int main(){
    priority_queue<my_t, vector<my_t>, cmp> q;
    for(int i = 0; i < 10; i++){
        q.push(my_t(i, i % 5 + i));
    }

    while(!q.empty()){
        cout << q.top().name << " " << q.top().age << endl;
        q.pop();
    }
    return 0;
    
}