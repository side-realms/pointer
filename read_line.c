#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define ALLOC_SIZE (256)

static char *st_line_buffer = NULL;
static int  st_current_buffer_size = 0;
static int  st_current_used_size = 0;
int ch;

static void
add_character(int ch)
{
    /*
     * st_current_used_sizeは必ず 1づつ増えるので、
     * いきなり抜かれていることはないはず。
     */
    assert(st_current_buffer_size >= st_current_used_size);

    /*
     * st_current_used_sizeがst_current_buffer_sizeに追い付いたら、
     * バッファを拡張する。
     */
    if (st_current_buffer_size == st_current_used_size) {
        st_line_buffer = realloc(st_line_buffer,
                                 (st_current_buffer_size + ALLOC_SIZE)
                                 * sizeof(char));
        st_current_buffer_size += ALLOC_SIZE;
    }
    /* バッファの末尾に1文字追加 */
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
}

char* read_line(FILE* fp){
    st_current_used_size=0;
    while((ch=getc(fp)) != EOF){
        if(ch == '\n'){
            add_character('\0');
            break;
        }
        add_character(ch);
    }
    if(ch == EOF){
        add_character('\0');
    }
    char* line = malloc(st_current_used_size*sizeof(char));
    strcpy(line, st_line_buffer);
    return line;
}

void free_buffer(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}


int main(void)
{
    char *line;

    while ((line = read_line(stdin)) != NULL) {
	printf("%s\n", line);
    }
    free_buffer();
}

