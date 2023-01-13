#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char* buf, int buf_size, FILE *fp){
    int ch;
    int len = 0;

    ch = getc(fp);

    do{
        buf[len] = ch;
        len++;
        if(len >= buf_size){
            fprintf(stderr, "too long.\n");
            exit(1);
        }
    }while((ch=getc(fp)) != EOF && isalnum(ch));

    buf[len] = '\0';
    return len;
    
}

int main(void){
    char buf[256];
    while(get_word(buf, 256, stdin) != EOF){
        printf("<<%s>>\n", buf);
    }

    return 0;
}
