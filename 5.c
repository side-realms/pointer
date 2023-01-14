#include<stdio.h>
// BOF

void hello(void){
    fprintf(stderr, "hello!\n");
}

void func(void){
    void* buf[10];
    static int i;

    for(i=0; i<100; i++){
        buf[i]=hello; // リターンアドレスを hello の先頭アドレスに上書きしてしまう
    }
}

int main(void){
    int buf[1000];
    buf[999]=10;

    func();

    return 0;
}
