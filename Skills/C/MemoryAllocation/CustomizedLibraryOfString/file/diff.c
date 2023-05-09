#include "header.h"
/*
returns the number of positions in which s1 and s2 differ
Or the required number of one character substitution, an insertion, or a deletion in order to make two string the same.
*/
int diff(char *s1, char *s2){
    int count = 0;
    //loop will end when both string reach the end
    while(*s1 != '\0' || *s2 != '\0'){
        //either one string reach the end
        //It will need one deletion for every extra char
        //deletion
        if(*s1 == '\0'){
            count++;
            s2++;
            break;
        }else if(*s2 == '\0'){
            count++;
            s1++;
            break;
        }
        //It will need one deletion for every different char
        //substitution
        if(*s1 != *s2){
            //insertion
            if(*s1 == *(s2+1)){
                //if insertion need to happen in s1
                //continue compare next character of s1 and the second character of s2 after current char.
                //s1 = "...cb" s2 = "...ecg" -> compare 'b' for s1 and 'g' for s2
                count++;
                s1++;
                s2+=2;
            }else if(*(s1+1) == *s2){
                //if insertion need to happen in s2
                //continue compare second character of s1 and next character of s2 after current char.
                //s1 = "...ecg" s2 = "...cb" -> compare 'g' for s1 and 'b' for s2
                count++;
                s2++;
                s1+=2;
            }else{
                //if there is no insertion and two char are different
                //one substitution is required, go next
                count++;
                s1++;
                s2++;
            }
        }else{
            //if the two char are the same, go next
            s1++;
            s2++;
        }
    }
    return count;
}

