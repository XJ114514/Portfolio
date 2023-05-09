#include "header.h"
/*
returns 1 if s is NULL, consists of only the null character ('') or only whitespace (' ').
returns 0 otherwise.
*/
int is_empty(char *s){
    if(s == NULL){
        return 1;
    }
    //loop through the s
    while(*s != '\0'){
            //if the current character is not a space (not empty)
            //return 0
        if(*(s) != ' '){
            return 0;
        }
        s++;
    }
    //loop ends, return 1
    return 1;
}
