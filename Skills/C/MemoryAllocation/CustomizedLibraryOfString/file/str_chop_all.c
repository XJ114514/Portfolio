#include "header.h"
/*
Returns an array of string consisting of the characters in s split into tokens based on the delimiter c,
followed by a NULL pointer.
*/
char ** str_chop_all(char *s, char c){
    //request memory for return value - the array of string
    //number of strings
    int row_default = 20;
    //number of chars in one single string
    int column_default = 20;

    char **temp = (char **)malloc(row_default*column_default*sizeof(char));
    for(int i = 0; i < row_default; i++){
        *(temp+i) = (char *)malloc(column_default*sizeof(char));
    }
    //current number of strings
    int count_string = 0;
    //current number of chars in that single string
    int count_char = 0;
    //loop through s
    int strlen_s = 0;
    while(*(s+strlen_s) != '\0'){
        //if the current char is the same as delimiter c
        if(*(s+strlen_s) == c){
            //skip current char of s, (do nothing)
            // if the adding has started (either count_char is greater than 0 or count_string is greater than 0),
            //move to next position in temp, restart the count_char,
            if(count_string != 0 || count_char != 0){
                count_string++;
                count_char = 0;
            }
        }else{
            //start adding the current char to current position of temp
            *(*(temp+count_string)+count_char) = *(s+strlen_s);
            count_char++;
        }
        strlen_s++;
    }
    //if the last char of s is delimiter c, the (current position) of temp will be the end
    if(*(s+strlen_s) == c){
        *(temp+count_string) = NULL;
    }else{
        //if the last char of s is not delimiter c, the (current position +1) of temp will be  the end
        *(temp+count_string+1) = NULL;
    }
    return temp;
}
