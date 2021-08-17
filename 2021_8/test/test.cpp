#include <iostream>
struct A{
    int *l;
    int *r;
};


int * init(){
    int *j = new int(100);
    return j;
}

int main(){
    A a;
    a.l = init();
    std::cout << *a.l << a.r << std::endl;
    
}