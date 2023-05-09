#include "header.h"
/*
Returns a new string consisting of all of the letters of s, but padded with spaces (' ') at the end,
so that the total length of the returned string is an even multiple of d.

If the length of s is already an even multiple of d, the function returns a copy of s.
The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string.

Warning:
The function returns the memory allocated string.
It is up to the caller to free the memory allocated by the function.
*/
char * pad(char *s, int d){
    //return NULL if s is NULL or d is non-positive
    if(s == NULL || d <= 0){
        return NULL;
    }

    //get strlen
    int strlen = 0;
    while(*(s+strlen) != '\0'){
        strlen++;
    }
    char *temp = (char *)malloc((strlen+2*d+1) *sizeof(char));
    //firstly put s to temp
    for(int i = 0 ; i < strlen ; i++){
        temp[i] = *(s+i);
    }
    //get the remainder
    int remain = 0;
    if(strlen % d != 0){
        remain = strlen % d;
    }
    //get the multiple
    int multiple = (strlen - remain) /d;
    int pad_num = 0;
    //if multiple is even and remainder is 0, no padding is required
    if(multiple % 2 == 0 && remain == 0){
    }else if(multiple %2 == 0){
        //if only multiple is even but remainder is not 0, (2d - remainder) times padding is required
        pad_num = 2*d - remain;
    }else if(multiple % 2 != 0 && remain == 0){
        //if multiple is even and remainder is 0, (d) times padding is required
        pad_num = d;
    }else if(multiple % 2 != 0){
        //if only multiple is even but remainder is not 0, (d-remainder) times padding is required
        pad_num = d-remain;
    }
    //padding the temp
    for(int i = 0 ; i < pad_num ; i++){
        temp[strlen+i] = ' ';
    }
    temp[strlen+pad_num] = '\0';
    return temp;
}
