#include "header.h"
/*
returns the index of the first occurrence of n in the string h
or -1 if it isn't found.
*/
int find(char *h, char *n){
    if(h == NULL || n == NULL){
        return -1;
    }
    //loop through h
    int count = 0;
    while(*(h+count) != '\0'){
        //if the current char of h matches the first char of n
        if(*(h+count) == *n){
            //loop through n
            int temp = 0;
            while(*(n+temp) != '\0'){
                //compare every corresponding char
                if(*(h+count+temp) == *(n+temp)){
                    //if they are the same, continue to next char comparison
                    temp++;
                }else{
                    //if they are not the same, break the loop of iterating n
                    break;
                }
                //if either string reaches eof
                if(*(h+count+temp) == '\0' || *(n+temp) == '\0'){
                    //case 1: two string reaches eof at the same time (find)
                    //case 2: n reaches eof before h reaches eof (find)
                    //return count
                    if(*(h+count+temp) == '\0' && *(n+temp) == '\0' || *(n+temp) == '\0'){
                        return count;
                    }else{
                        //case 3, h reaches eof before n reaches eof (not find)
                        //return -1
                        return -1;
                    }
                }
            }
        }
        //if they are not the same, break the loop of iterating n, continue looping through h
        count++;
    }
    //if after looping through h, and still no finding n, return -1
    return -1;
}
