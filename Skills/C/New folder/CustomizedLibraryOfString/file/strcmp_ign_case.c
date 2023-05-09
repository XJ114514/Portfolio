#include "header.h"
/*
Compares s1 and s2 ignoring case.
Returns a positive number if s1 would appear after s2 in the dictionary,
Returns a negative number if it would appear before s2,
or Returns 0 if the two are equal.
*/
int strcmp_ign_case(char *s1, char *s2){
    //loop through s1
   int count = 0;
   while(*(s1+count) != '\0'){
        //convert to all lowercase
        *(s1+count) = tolower(*(s1+count));
        *(s2+count) = tolower(*(s2+count));
        //if the current char of s1 is different from the current char s2, return difference
        if(*(s1+count) != *(s2+count)){
            return *(s1+count) - *(s2+count);
        }
        count++;
        //if either s1 or s2 reaches eof
        if(*(s1+count) == '\0' || *(s2+count) == '\0'){
            //if both string reaches the end and are not different, return 0
            if(*(s1+count) == '\0' && *(s2+count) == '\0'){
                return 0;
            }else if(*(s1+count) == '\0'){
                //if s1 firstly reaches eof, return 1
                return 1;
            }else if(*(s2+count) == '\0'){
                //if s2 firstly reaches eof, return -1
                return -1;
            }
        }
   }
}
