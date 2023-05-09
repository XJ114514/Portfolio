#include "header.h"
/*
argument s : source string
argument x : repeat times
argument sep : substring in between every repeat

Returns a new string consisting of the characters in s repeated x times, with the character sep in between.
For example, if s is the string "all right", x is (3), and sep is ','
the function returns the new string "all right,all right,all right".
If s is NULL, the function returns NULL.

Warning:
The function returns the memory allocated string.
It is up to the caller to free the memory allocated by the function.
*/
char * repeat(char *s, int x, char sep){
    //return NULL if s is NULL , sep is NULL or d is non-positive
    if(s == NULL || x <= 0){
        return NULL;
    }
    //get strlen
    int strlen = 0;
    while(*(s+strlen) != '\0'){
        strlen++;
    }
    char *temp = (char *)malloc((strlen*x + sep*(x-1) +1 )*sizeof(char));
    //loop x times
    for(int i = 0 ; i < x ; i++){
        //put s to temp
        for(int j = 0; j < strlen; j++){
            temp[i*(strlen+1)+j] = *(s+j);
        }
            //last time of loop put a eof instead of sep
        if(i == x-1){
            temp[(i+1)*strlen+i] = '\0';
        }else{
            //every time after putting s, put a sep to current end of temp
            temp[(i+1)*strlen+i] = sep;
        }
    }
    return temp;
}
