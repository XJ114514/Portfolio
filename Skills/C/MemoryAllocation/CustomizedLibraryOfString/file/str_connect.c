#include "header.h"
/*
argument strs: source string array
argument n: number of strings included (n needs to be smaller or equal to the number of strings in strs);
argument c: separator
Returns a string consisting of the first n strings in strs with the character c used as a separator.
For example, if strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+',
the function returns the string "Washington+Adams+Jefferson"


Warning:
The function returns the memory allocated string.
It is up to the caller to free the memory allocated by the function.
*/

char * str_connect(char **strs, int n, char c){
    char *temp = (char *)malloc(n*20*sizeof(char));
    int temp_len = 0;
    //loop n times to get the first n strings
    for(int i = 0 ; i < n ; i++){
        int count = 0;
        //loop through the current string and add it to the temp
        while(*(*(strs+i)+count) != '\0'){
            *(temp+temp_len) = *(*(strs+i)+count);
            temp_len++;
            count++;
        }
        //add separator to temp if it is not the last string
        if(i != n-1){
            *(temp+temp_len) = c;
            temp_len++;
        }
    }
    //add eof to temp
    *(temp+temp_len) = '\0';
    return temp;
}
