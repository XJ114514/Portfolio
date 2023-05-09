#include "header.h"
/*
Returns the length of s1 - the length of s2
*/
int len_diff(char *s1,char *s2){
    int strlen01 = 0;
    int strlen02 = 0;

    while(*(s1+strlen01) != '\0'){
        strlen01++;
    }
    while(*(s2+strlen02) != '\0'){
        strlen02++;
    }
    return strlen01 - strlen02;
}
