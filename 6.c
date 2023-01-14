#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char* format, ...){
    int i;
    va_list ap;
    va_start(ap, format);

    for(i=0; format[i]!='\0'; i++){
        switch(format[i]){
            case 's': // s が入力されているなら次は文字列
                printf("%s", va_arg(ap, char*));
                break;
            case 'd':
                printf("%d", va_arg(ap, int));
                break;
            default:
                assert(0);
        }
    }

    va_end(ap);
    putchar('\n');

}

int main(void){
    tiny_printf("sdd", "result..", 3, 5); // s: 文字列リテラル，d: 整数
    return 0;
}
