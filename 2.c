#include <stdio.h>

int main(void){
    int a[5];
    int* p;

    for(int i=0; i < 5; i++){
        a[i] = i;
    }

    for(p = &a[0]; p != &a[5]; p++){
        printf("%d\n", *p);
    }

    return 0;
}
