/*  Write aprogram to remove all comments from a C program
 *  Don't forget to handle quoted strings and character constants
 *  properly. C comments don't nest. */
#include "stdio.h"

void sanitize(char *stream, size_t length);

int main(int argc, char *argv) {
   
}

void sanitize(char *stream, size_t length) {
    char *sub = stream;
    int begin = 0;
    for (int c; c<length; ++c) {
        if (*sub == '/') {
            if (*(sub+1) == '*') {
                sanitize(stream, c, length);
            }
        }
    }
    return;
}

void sanitize2(char *stream, int begin, size_t length) {
    for (int c=begin; c<length; ++c) {
        if (*sub == '*') {
            if (*(sub+1) == '/') {
                sanitize3(stream, begin, c, length);
                return;
            }
        }
    }
}

void sanitize3(char *stream, int begin, int end, size_t length) {
    
}
