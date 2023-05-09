#include "header.h"
/*
removes whitespace characters from the end of s
*/
void rm_right_space (char *s){
    int count = 0;
    int strlen = 0;
    //get length
    while(*(s+strlen) != '\0'){
        strlen++;
    }
    //check from backward
    while(*(s+strlen-1) == ' '){
        strlen--;
    }
    *(s+strlen) = '\0';
}
