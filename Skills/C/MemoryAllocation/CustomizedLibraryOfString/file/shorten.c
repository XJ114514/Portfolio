#include "header.h"
/*
Shortens the string s to new_len.
If the original length of s is less than or equal to new_len, s is unchanged
*/
void shorten(char *s, int new_len){
    int strlen = 0;
    //get the strlen of s
    while(*(s+strlen) != '\0'){
        strlen++;
    }
    //put eof at the end if the strlen is greater than new_len
    if(strlen > new_len){
        *(s+new_len) = '\0';
    }
}
