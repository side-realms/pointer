#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    char buf[256];
    int size;

    printf("input size of array\n");
    fgets(buf, 256, stdin);
    sscanf(buf, "%d", &size);

    int* array = malloc(size * sizeof(int));

    for(int i=0; i<size; i++){
        array[i] = i;
    }

    for(int i=0; i<size; i++){
        printf("array[%d] is %d \n", i, array[i]);
    }

}
