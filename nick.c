/*  Write aprogram to remove all comments from a C program
 *  Don't forget to handle quoted strings and character constants
 *  properly. C comments don't nest. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tuple_s {
    int x;
    int y;
    struct tuple_s *next;
} tuple;

void sanitize(char *dst, char *src, size_t length);
int strcut(char *dst, char *src, size_t length);

int main(void) {
    char str[] = "this /*demo*/ is a /*dummy*/ string";

    char *s = malloc(sizeof(str));

    strcut(s,str,sizeof(str));

    printf("%s\n", s);
}

int strcut(char *dst, char *src, size_t length) {
    int new_length = length;
    char *_src = src;
    char *_dst = dst;

    tuple *range = (tuple *) malloc(sizeof(tuple));
    *range = (tuple){0,length,NULL};
    tuple *t = range;

    for (int c=0; c<length; ++c) {
        if (_src[c] == '/' && _src[c+1] == '*') {
            t->y = c;
            t->next = (tuple *) malloc(sizeof(tuple));
            t = t->next;
            *t = (tuple){c+2,length,0};
        }
        else if (_src[c] == '*' && _src[c+1] == '/') {
            t->x = c+2;
        }
    }

    t = range;

    while (t != 0) {
        int begin = t->x;
        int end = t->y;
        for (int c=begin; c<end; ++c)
            *(_dst++) = _src[c];
        t = t->next;
        free(range);
        range = t;
    }

    _dst -= new_length;
    return new_length;
}
