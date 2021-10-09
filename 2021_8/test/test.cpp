#include "../head.h"
// struct A{
//     int *l;
//     int *r;
// };

class A{
public:
    int num = 100;
    int val = 200;
};

struct B{
    int a;
    int b;
};

// int * init(){
//     int *j = new int(100);
//     return j;
// }

// void print(int & a, int & b){
//     cout << "a = " << a << endl << "b = " << b << endl;
// }

// int a = 100;
// int& rt(){
//     // int a = 10;
//     return a;
// }
int t(){
    int a[10];
    for(auto i:a){
        cout << i << endl; 
    }
    int *p = a;
    p = p + 100;
    cout << p << endl;
    return 0;
}
int main(){
    // A a;
    // // a.l = init();
    // // std::cout << *a.l << a.r << std::endl;
    // rt() = 1;
    // print(rt(), rt());
    // signed int a = 1000000000000;
    // int a = 134480385;    // 二进制0000 1000 0000 0100 0000 0010 0000 0001
    // char *p = (char *)&a; // 一次操作一个字节
    // printf("%c\n", p[0] + '0');
    // printf("%c\n", p[1] + '0');
    // printf("%c\n", p[2] + '0');
    // printf("%c\n", p[3] + '0');
    // int b = -1;
    // printf("%x\n", b);
    // cout << ~b << endl;
    int p = 1;
    // // int *t(&p);
    // *t = 10;
    // cout << p << endl;
    A a;
    B b;
    // cout << a.num << " " << a.val << endl;
    // cout << b.a << " " << b.b << endl;
    string str = "11";
    // printf("%x\n", str.size());
    // cout << (str.size() < -1) << endl;
    // int &aa = 1;
    // while(getline(cin, str)){
    //     cout << str << endl;
    // }
    // int t[10];
    // t();
    // char *c  = {'1', '2'};
    // cout << sizeof(c) << endl;
    return 0;
}