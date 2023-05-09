#include "header.h"
/*
removes whitespace characters from the beginning of s
*/
void rm_left_space (char *s){
    int count = 0;
    while(*(s+count) == ' '){
        count++;
    }
    char *temp = s+count;
    while(*temp != '\0'){
        *s = *temp;
        temp++;
        s++;
    }
    *s = '\0';
}
