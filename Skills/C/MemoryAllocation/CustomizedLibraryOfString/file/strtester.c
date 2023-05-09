/*
 * Name:	Xu Jiang
 * Section:	01
 * Lab:  	CIS2107_Lab09_String_lib
 * Goal: 	To design and implement a customized string lib by using header file and a lib collection.
 */
#include "header.h"


int main(){
    //all_letters
    puts("");
    char *temp01 = NULL;
    char *temp02 = NULL;
    char *temp03 = NULL;
    temp01 = "Hello World";
    temp02 = "Hell0 World";
    printf("%s %s all letters\n",temp01,all_letters(temp01)? "is":"is not");
    printf("%s %s all letters\n",temp02,all_letters(temp02)? "is":"is not");
    puts("");

    //num_in_range
    temp01 = "yellow";
    char c1 = 'f';
    char c2 = 'm';
    printf("%s has %d count of char between %c and %c (inclusive)\n",temp01,num_in_range(temp01,c1,c2),c1,c2);
    puts("");

    //diff
    temp01 = "book";
    temp02 = "back";
    printf("\"%s\" and \"%s\" need to have %d modifications to be the same\n",temp01,temp02,diff(temp01,temp02));
    puts("");

    //new_len
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr01[12] = "Hello World";
    temp01 = arr01;
    int new_len = 5;
    printf("\"%s\" will become ",temp01);
    shorten(temp01,new_len);
    printf("\"%s\" with new length %d\n",temp01,new_len);
    puts("");

    //shorten
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr02[12] = "Hello World";
    temp01 = arr02;
    new_len = 20;
    printf("\"%s\" will become ",temp01);
    shorten(temp01,new_len);
    printf("\"%s\" with new length %d\n",temp01,new_len);
    puts("");

    //len_diff
    temp01 = "Philadelphia";
    temp02 = "Hello";
    printf("The size difference bewteen \"%s\" and \"%s\" is %d\n",temp01,temp02,len_diff(temp01,temp02));
    puts("");

    //rm_left_space
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr03[9] = "   Hello";
    temp01 = arr03;
    printf("\"%s\" become  ",temp01);
    rm_left_space(temp01);
    printf("\"%s\" after removing the left space\n",temp01);
    puts("");

    //rm_right_space
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr04[9] = "Hello   ";
    temp01 = arr04;
    printf("\"%s\" become  ",temp01);
    rm_right_space(temp01);
    printf("\"%s\" after removing the right space\n",temp01);
    puts("");

    //rm_space
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr05[12] = "   Hello   ";
    temp01 = arr05;
    printf("\"%s\" become  ",temp01);
    rm_space(temp01);
    printf("\"%s\" after removing the space\n",temp01);
    puts("");

    //find
    temp01 = "Hello";
    temp02 = "l";
    printf("\"%s\" are found the index of %d in \"%s\"\n",temp02,find(temp01,temp02),temp01);
    temp01 = "Hello";
    temp02 = "q";
    printf("\"%s\" are found the index of %d in \"%s\"\n",temp02,find(temp01,temp02),temp01);
    puts("");

    //ptr_to
    temp01 = "Hello";
    temp02 = "l";
    printf("\"%s\" are found the pointer of \"%s\" in \"%s\"\n",temp02,ptr_to(temp01,temp02),temp01);
    temp01 = "Hello";
    temp02 = "q";
    printf("\"%s\" are found the pointer of \"%s\" in \"%s\"\n",temp02,ptr_to(temp01,temp02),temp01);
    puts("");

    //is_empty
    temp01 = " ";
    temp02 = "Hello";
    printf("\"%s\" %s empty\n",temp01,is_empty(temp01)?"is":"is not");
    printf("\"%s\" %s empty\n",temp02,is_empty(temp02)?"is":"is not");
    puts("");

    //str_zip
    temp01 = "Temple";
    temp02 = "Hello";
    char *malloc01 = str_zip(temp01,temp02);
    printf("result of interleaving \"%s\" and \"%s\" is \"%s\"\n",temp01,temp02,malloc01);
    free(malloc01);
    puts("");

    //capitalize
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr06[12] = "hello world";
    temp01 = arr06;
    printf("\"%s\" become  ",temp01);
    capitalize(temp01);
    printf("\"%s\" after capitalizing\n",temp01);
    puts("");

    //strcmp_ign_case
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr07[6] = "Hello";
    char arr08[8] = "goodbye";
    temp01 = arr07;
    temp02 = arr08;
    printf("Comparing \"%s\" and \"%s\" ",temp01,temp02);
    printf("will get the result of %d\n",strcmp_ign_case(temp01,temp02));
    puts("");

    //take_last
    //if the underlying string is not an array format, the compiler will have segmentation fault error when I tried to assign value to the specific char of string.
    char arr09[6] = "Hello";
    temp01 = arr09;
    int num = 3;
    printf("The last %d char of \"%s\" ",num,temp01);
    take_last(temp01,num);
    printf("will be \"%s\"\n",temp01);
    char arr10[6] = "Hello";
    temp02 = arr10;
    num = 6;
    printf("The last %d char of \"%s\" ",num,temp02);
    take_last(temp02,num);
    printf("will be \"%s\"\n",temp02);
    puts("");

    //dedup
    temp01 = "There's always money in the banana stand.";
    printf("The unique char of \"%s\" ",temp01);
    char *malloc02 = dedup(temp01);
    printf("will be \"%s\"\n",malloc02);
    free(malloc02);
    puts("");

    //pad
    temp01 = "hello";
    num = 6;
    printf("\"%s\" after padding with number %d ",temp01,num);
    char *malloc03 = pad(temp01,num);
    printf("will be \"%s\"\n",malloc03);
    free(malloc03);
    temp02 = "hello~";
    num = 3;
    printf("\"%s\" after padding with number %d ",temp02,num);
    char *malloc04 = pad(temp02,num);
    printf("will be \"%s\"\n",malloc04);
    free(malloc04);
    puts("");

    //end_with_ignore_case
    temp01 = "coding";
    temp02 = "ing";
    printf("\"%s\" %s \"%s\" as suffix\n",temp01,end_with_ignore_case(temp01,temp02)?"has":"has not",temp02);
    temp02 = "ed";
    printf("\"%s\" %s \"%s\" as suffix\n",temp01,end_with_ignore_case(temp01,temp02)?"has":"has not",temp02);
    puts("");

    //repeat
    temp01 = "hello";
    num = 3;
    char c = '-';
    printf("repeat \"%s\" by %d times with sep \"%c\" ",temp01,num,c);
    char *malloc05 = repeat(temp01,num,c);
    printf(" will be \"%s\"\n",malloc05);
    free(malloc05);
    puts("");

    //replace
    temp01 = "Steph is the X";
    temp02 = "is";
    temp03 = "best";
    printf("replace all \"%s\" with \"%s\" in \"%s\" ",temp02,temp03,temp01);
    char *malloc06 = replace(temp01,temp02,temp03);
    printf(" will be \"%s\"\n",malloc06);
    free(malloc06);
    puts("");

    //str_connect
    char *strs01[10] = {"Hello","world","Hello","world"};
    char **strs = strs01;
    num = 4;
    c = '-';
    char *malloc07 = str_connect(strs,num,c);
    printf("Connecting result will be \"%s\"\n",malloc07);
    free(malloc07);
    puts("");

    //rm_empties
    char *strs02[10] = {"hello", "world", " ", " ", "Steph",NULL};
    int size = 5;
    puts("Before:");
    //print strs02 to screen
    int i = 0;
    while(strs02[i] != NULL) {
       printf("\"%s\" ",strs02[i]);
       i++;
    }
    puts("");
    rm_empties(strs02,size);
    puts("After removing empty string:");
    //print strs02 to screen
    i = 0;
    while(strs02[i] != NULL) {
       printf("\"%s\" ",strs02[i]);
       i++;
    }
    puts("\n");

    //str_chop_all
    temp01 = "Hello/world/hello/world";
    c = '/';
    puts("Before:");
    printf("\"%s\"\n",temp01);
    strs = str_chop_all(temp01,c);
    i = 0;
    printf("After chopping with \'%c\':\n",c);
    while(*(strs+i) != NULL){
        printf("\"%s\" ",*(strs+i));
        i++;
    }
    free(strs);
    puts("\n");

    return 0;
}
