#include "stdio.h"
typedef struct st{
    int a;
    int *c;
    // int b[];
}st;
int main(){
    st c;
    printf("size:%d\n", sizeof(st));
    return 0;
}