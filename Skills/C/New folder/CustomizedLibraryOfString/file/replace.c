#include "header.h"
/*
argument s : source string
argument pat : target substring
argument rep : substitution substring

Returns a copy of the string s, but with each instance of pat replaced with rep,
The length of pat can be less than, greater than, or equal to length of rep.

Warning:
The function returns the memory allocated string.
It is up to the caller to free the memory allocated by the function.
*/
char * replace(char *s, char *pat, char *rep){
    //get strlen
    int strlen01 = 0;
    int strlen02 = 0;
    int strlen03 = 0;
    while(*(s+strlen01) != '\0'){
        strlen01++;
    }
    while(*(pat+strlen02) != '\0'){
        strlen02++;
    }
    while(*(rep+strlen03) != '\0'){
        strlen03++;
    }

    char *temp = (char *)malloc((strlen01*strlen03+1) *sizeof(char));
    int count_temp = 0;
    //loop through s
    for(int i = 0; i < strlen01 ; i++){
        //if current char of s is different from pat, add current char of s to temp
        if(*(s+i) != *pat){
            temp[count_temp++] = *(s+i);
        }else{
            //if they are the same, compare rest of the pat with the corresponding substring of s
            //loop through pat
            //flag = 1 -> find the same pat in s; flag = 0 -> not find the same pat
            int flag = 1;
            for(int j = 1 ; j < strlen02 ; j++){
                //if the current char of pat is different from the current char of s,
                //add outer loop's current char of s - '*(s+i)' to temp, break the loop
                //turn flag to 0
                if(*(s+i+j) != *(pat+j)){
                    temp[count_temp++] = *(s+i);
                    flag = 0;
                    break;
                }
            }
            //if pat is found in s
            if(flag == 1){
                //move i to the correct index of original s
                i += strlen02-1;
                //add the entire rep to temp
                for(int n = 0 ; n < strlen03 ; n++){
                    temp[count_temp++] = *(rep+n);
                }
            }
        }
        temp[count_temp] = '\0';
    }
    return temp;
}
