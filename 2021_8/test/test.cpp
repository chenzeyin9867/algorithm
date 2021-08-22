#include "head.h"
struct A{
    int *l;
    int *r;
};


int * init(){
    int *j = new int(100);
    return j;
}

void print(int & a, int & b){
    cout << "a = " << a << endl << "b = " << b << endl;
}

int a = 100;
int& rt(){
    // int a = 10;
    return a;
}
int main(){
    A a;
    // a.l = init();
    // std::cout << *a.l << a.r << std::endl;
    rt() = 1;
    print(rt(), rt());
}