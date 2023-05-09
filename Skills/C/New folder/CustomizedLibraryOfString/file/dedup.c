#include "header.h"
/*
Returns a new string based on s, but without any duplicate characters.

Warning:
The function returns the memory allocated string.
It is up to the caller to free the memory allocated by the function.
*/
char * dedup(char *s){
    //declare temp storing return string and dup storing appeared char
    char *unique = (char *)malloc(50*sizeof(char));
    //loop through s
    int count_unique = 0;
    //flag = 0, the current char is first time appearing
    //flag = 1, the current char has appeared before
    int flag = 0;
    while(*s != '\0'){
        //loop through dup
        for(int i = 0;i < count_unique ; i++){
            //if current char has appeared before
            //turn flag to 1, break the loop
            if(*s == unique[i]){
                flag = 1;
                break;
            }
        }
        //if flag = 0 , the current char is first time appearing, add it to dup
        if(flag == 0){
            unique[count_unique] = *s;
            count_unique++;
        }
        s++;
        //after adding, turn flag back to 0
        flag = 0;
    }
    unique[count_unique+1] = '\0';
    return unique;
}
