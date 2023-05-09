#include "header.h"
/*
Modifies s so that it consists of only its last n characters.
If the length of n is greater than the length of s, the original string is unmodified.
*/
void take_last(char *s, int n){
    char temp[n+1];
    int strlen = 0;
    //get strlen
    while(*(s+strlen) != '\0'){
        strlen++;
    }
    //if the strlen is smaller than n, use strlen as n
    if(strlen < n){
        n = strlen;
    }
    //get the last n char
    for(int i = 0; i < n; i++){
        temp[i] = *(s+strlen-n+i);
    }
    temp[n] = '\0';
    //put the temp back to s
    for(int i = 0; i < n+1; i++){
        *(s+i) = temp[i];
    }
}
