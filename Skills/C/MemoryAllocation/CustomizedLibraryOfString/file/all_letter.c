#include "header.h"
/*
if all of the characters in the string are either upper- or lower-case letters of the alphabet
    Returns 1
otherwise
    Returns 0

*/
int all_letters(char *s){
    while(*s != '\0'){
        char template = tolower(*s);
        //if the char is not within ascii table a(97) ~ z(122)
        //and is not a space
        if((template < 97 || template > 122) && template != ' '){
            return 0;
        }
        s++;
    }
    return 1;
}
