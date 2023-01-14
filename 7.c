#include <stdio.h>

#define N_MAX (100)

int used_flag[N_MAX + 1];
int result[N_MAX];
int n, r;

void permutation(int nth){
    int i,j;

    if(nth==r){
        for(i=0; i<r; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    for(j=0; j<n; j++){
        if(used_flag[j]==0){
            result[nth] = j;
            used_flag[j]=1;
            permutation(nth+1);
            used_flag[j]=0;
        }
    }

}

int main(int argc, char **argv){
    sscanf(argv[1], "%d", &n); // 使える最大数字
    sscanf(argv[2], "%d", &r); // 表示する最大数字
    permutation(0);
}