#include "header.h"
/*
Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other.
For example, if s1 is "Spongebob" and s2 is "Patrick",
the function returns the string "SPpaotnrgiecbkob"

Warning:
The function returns the memory allocated string.
It is up to the caller to free the memory allocated by the function.
*/
char * str_zip(char *s1, char *s2){
     //get the length of both string
    int strlen01 = 0;
    int strlen02 = 0;
    while(*(s1+strlen01) != '\0'){
        strlen01++;
    }
    while(*(s2+strlen02) != '\0'){
        strlen02++;
    }

    //create the string
    char *temp= (char *)malloc((strlen01+strlen02+1)*sizeof(char));

    //get the bigger length
    int max = strlen01;
    if(strlen01 < strlen02){
        max = strlen02;
    }
    //merge the two string
    for(int i = 0; i<max ;i++){
        //if either string reaches the end
        if(*(s1+i) == '\0' || *(s2+i) == '\0'){
            //if both string reaches the end, end the loop
            if(*(s1+i) == '\0' && *(s2+i) == '\0'){
                break;
            }else if(*(s1+i) == '\0'){
                //if s1 reaches eof, continue adding s2 untill the eof, then end the loop
                //record the current adding index of temp
                int current = 2*i;
                while(*(s2+i) != '\0'){
                    *(temp+current) = *(s2+i);
                    i++;
                    current++;
                }
                break;
            }else if(*(s2+i) == '\0'){
                //if s2 reaches eof, continue adding s1 untill the eof, then end the loop
                //record the current adding index of temp
                int current = 2*i;
                while(*(s1+i) != '\0'){
                    *(temp+current) = *(s1+i);
                    i++;
                    current++;
                }
                break;
            }
        }
        *(temp+2*i) = *(s1+i);
        *(temp+2*i+1) = *(s2+i);

    }
    //add eof char to (n+1)th position with n index
    *(temp+strlen01+strlen02) = '\0';
    return temp;
}
