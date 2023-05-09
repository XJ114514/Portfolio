#include "header.h"
/*
returns the number of characters c in s1
such that c is every char that belongs to (b<=c<=t)
*/
int num_in_range (char *s1,char b, char t){
    //the size of all char between b and c (both inclusive)
    int size = t-b+1;
    char arr[size];
    //get all the char between b and c and store them in arr
    for(int i = 0 ; i < size ; i++){
        arr[i] = b+i;
    }
    int count = 0;
    while(*s1 != '\0'){
        for(int i = 0; i< size; i++){
            if(*s1 == arr[i]){
                count++;
                break;
            }
        }
        s1++;
    }
    return count;
}
