#include <stdio.h>
#include <stdlib.h>

int global_variable;
static int file_static_variable;

void func1(void){
    int func1_variant;
    static int local_static_variable;

    printf("func1 variable %p\n", (void*)&func1_variant);
    printf("func1 static%p\n", (void*)&local_static_variable);
}

int main(void){
    int *p;

    printf("func1 pointer %p\n", (void*)func1);
    printf("main global address %p\n", (void*)&global_variable);
    printf("main static pointer %p\n", (void*)&file_static_variable);

    func1();

    p=malloc(sizeof(int));
    printf("malloc address..%p\n", (void*)p);

    return 0;
}
