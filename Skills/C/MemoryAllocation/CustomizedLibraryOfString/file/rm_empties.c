#include "header.h"
/*
The function removes any empty string from the array words
and add NULL pointer to (newSize+1)th location
*/
//I add an argument represent the number of strings (or rows for 2d array) stored in words
void rm_empties(char **words,int size){
    //the size of none empty string
    int count01 = 0;
    //loop through every string in words
    for(int i = 0; i < size; i++){
        //if the current string is not empty, increase the count
        if( !(is_empty(*(words+i))) ){
            count01++;
        }else{
            //if the current string is empty, remove the current string by shifting the entire words array to left by 1, add NULL to the end
            for(int j = i ; j < size-1 ; j++){
                *(words+j) =  *(words+j+1);
            }
            //add NULL to the end
            *(words+size-1) = NULL;
            //since we shift the words, size decreased by 1
            size--;
            //since we simply shift the words, the current i position need to be check again, decrease i by 1 too
            i--;
        }
    }
}
