#include "../head.h"
char * a = "malloc";
char* func(){
    // char * a = (char*) malloc(4);
    
    // a[0] = 1;
    // a[3] = 3;
    cout << a[0] << endl;
    return a;
}
int main(){
    char *r = func(); 
    printf("%x\n", a); 
    printf("%x\n", r);
    for(int i = 0; i < 4; ++i){
        cout << i << "->" << r[i] << endl;
    }
    return 0;
}