#include "header.h"
/*
Returns 1 if suff is a suffix of s (ignoring case)
Otherwise returns 0.
*/
int end_with_ignore_case(char *s,char *stuff){
    //get strlen
    int strlen01 = 0;
    int strlen02 = 0;
    if(s == NULL || stuff == NULL){
        return 0;
    }

    while(*(s+strlen01) != '\0'){
        strlen01++;
    }
    while(*(stuff+strlen02) != '\0'){
        strlen02++;
    }

    //if suffix is longer than s, return 0
    if(strlen02 > strlen01){
        return 0;
    }
    //loop through stuff
    for(int i= 0 ; i < strlen02 ; i++){
        //convert to all lowercase
        char arr01 = tolower(*(s+strlen01-strlen02+i));
        char arr02 = tolower(*(stuff+i));
        //if current char is not the same in stuff and s, return 0
        if(arr01 != arr02){
            return 0;
        }
    }
    //if function runs here, s has stuff as suffix ,return 1
    return 1;
}
