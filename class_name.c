#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX 32

void read_name(FILE *fp, char **name){
    char buf[NAME_MAX];
    for(int i=0; i<5; i++){
        fgets(buf, NAME_MAX, fp);

        int length = strlen(buf);
        if(length > 32){
            fprintf(stderr, "too long.\n");
            exit(1);
        }

        buf[length-1] = '\0'; // 終端文字を付加する(ファイルでは改行)
        name[i] = malloc(sizeof(char)*length);
        strcpy(name[i], buf);
    }
}

int main(void){
    char* name[5];
    FILE* fp;
    fp = fopen("./name.txt", "r");
    read_name(fp , name);

    for(int i=0; i<5; i++){
        printf("%s\n", name[i]);
    }

}