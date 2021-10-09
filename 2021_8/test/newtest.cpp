#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print(const int *begin, const int* end){
    while(begin !=  end){
        cout << *begin ++ << endl;
    }
}

void print2(const int (*a)[10]){
    // cout << *a << endl;
    // cout << (*(a+))<< " " << *(*a + 10) << endl;
    while(a){
        for(int i = 0; i < 10; i++){
            cout << " " <<  (*a)[i];
        }
        ++a;
        cout << endl;
    }
}
int main(){
    int a[10][10] = { {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            a[i][j] = i + j;
    // print(begin(a), end(a));
    print2(a);
    return 0;
}