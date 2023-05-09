#include "header.h"
/*
removes whitespace characters from the beginning and end of s
*/
void rm_space(char *s){
    rm_left_space(s);
    rm_right_space(s);
}
