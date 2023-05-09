#include "header.h"
/*
Changes s so that the first letter of every word is in upper case
and each additional letter is in lower case.
*/
void capitalize(char *s){
   //flag = 1 -> waiting for new word
    //flag = 0 -> still inside one single word
    int flag = 1;
    //loop through s
    while(*s != '\0'){
        //firstly put all char to lowercase
        *s = tolower(*s);
        //when flag = 1
        //convert the (first found) letter to uppercase
        if((*s >= 97 && *s <= 122)&& flag == 1){
            *s = toupper(*s);
            //turn flag to 0 -> inside one single word
            flag = 0;
        }else if(*s < 97 || *s > 122){
            //if the char was non-letter
            //turn flag back to 1 waiting for new word.
            flag = 1;
        }

        s++;
    }
}
