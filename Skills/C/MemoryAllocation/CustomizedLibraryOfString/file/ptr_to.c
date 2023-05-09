#include "header.h"
/*
returns a pointer to the first occurrence of n in the string h
or NULL if it isn't found
*/
char * ptr_to(char *h, char *n){
    if(find(h,n)==-1){
        return NULL;
    }else{
        return h+find(h,n);
    }
}
