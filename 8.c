#include <stdio.h>
//malloc と free について理解したい

int memory[20];
int used[20]={0}; //0:空き，1:使用中

int* my_malloc(int size){
    if(size <=0 || size>20){
        return 0;
    }

    for(int i=0; i<20-(size-1); i++){ // 必要なサイズを超過するのを防ぐ
        if(!used[i]){
            int empty=1;
            for(int j=0; j<size; j++){
                if(used[i+j]){
                    empty=0;
                }
            }
            if(empty){
                for(int j=0; j<size; j++){
                    used[i+j]=size-j; // free のために，確保分のサイズを知る 
                }
                return memory+i;
            }
        }
    }
    return 0;
}

void my_free(int* ptr){
    if(!ptr){
        return;
    }
    int index=ptr-memory;
    int size = used[index];
    for(int i=0; i<size; i++){
        used[i+index] = 0;
    }
}


int main(){
    int* a=my_malloc(5);
    int* b=my_malloc(5);

    a[0]=1;
    a[1]=2;
    b[0]=10;
    b[1]=11;

    printf("a[0]=%p\nb[0]=%p\n", &a[0], &b[0]);

    my_free(a);

    int* c = my_malloc(5);
    printf("c[0]=%p\n", &c[0]);
    return 0;
}