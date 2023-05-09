/**
Xu Jiang
02/14/2023
CIS 2107-001
Lab 4
Arrays1DDemo
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SRAND_MIN 0
#define SRAND_MAX 100
#define SIZE 40
void printArray(int array[],int size);
void fillArray(int array[],int size);
int findWithRange(int array[],int size,int start, int end);
void reverseArray(int array[], int size);
int reverseSelectedRangeWithinArray(int array[],int size,int start,int end);
int findSequence(int array[], int size,int num1,int num2);

int main(){
    int flag;
    do{
        fflush(stdin);
        //test fillArray()
        int array[SIZE];
        srand((unsigned)time(NULL));
        printf("Original array index ranged from [0,%d]:\n",SIZE-1);
        fillArray(array,SIZE);
        printArray(array,SIZE);

        //test findWithRange();
        int start01, end01, returnValue01;
        do{
            printf("\nEnter the two range number finding the max number: ");
            scanf("%d%d",&start01,&end01);
            fflush(stdin);
            returnValue01 = findWithRange(array,SIZE,start01,end01);
            if(returnValue01 != -1){
               printf("\nThe max = %d within [%d, %d]\n",returnValue01,start01,end01);
            }else{
                puts("\nPlease try again.");
            }
        }while(returnValue01 == -1);

        //test reverseArray()
        printf("\nReversed array index ranged from [0,%d]:\n",SIZE-1);
        reverseArray(array,40);
        printArray(array,SIZE);

        //test reverseSelectedRangeWithinArray()
        int start02,end02,returnValue02;
        do{
            printf("\nEnter the two range number to reverse the order: ");
            scanf("%d%d",&start02,&end02);
            fflush(stdin);
            returnValue02 = reverseSelectedRangeWithinArray(array,SIZE,start02,end02);
            if(returnValue02 != -1){
                printf("\nReversed array within range [%d, %d]\n",start02,end02);
            }else{
                puts("\nPlease try again.");
            }
        }while(returnValue02 == -1);
        printArray(array,SIZE);

        //test findSequence()
        int num1,num2,returnValue03;
        do{
            printf("%s","\nEnter two numbers to search in the array: ");
            scanf("%d%d",&num1,&num2);
            fflush(stdin);
            returnValue03 = findSequence(array,SIZE,num1,num2);
            if(returnValue03 != -1){
                printf("sequence found at index %d\n",returnValue03);
            }else{
                puts("sequence not found,Please try again.");
            }
        }while(returnValue03 == -1);

        printf("%s","\nEnter any number to rerun or enter any character to exit:");
    }while(scanf("%d",&flag)>0);
    exit(0);
}
//show the array element to screen
void printArray(int array[],int size){
    for(int i = 0; i < size; i++){
        if(i%5 == 0){
            puts("");
        }
        printf("%3d ",array[i]);
    }
    puts("");
}
//fill the array with random number ranged in [RAND_MIN , RAND_MAX]
void fillArray(int array[],int size){
    for(int i = 0 ; i < size ; i++){
        array[i] = rand()%(SRAND_MAX+1) + SRAND_MIN;
    }
}
//return the largest element within the range [start, end] of the array
int findWithRange(int array[],int size,int start, int end){
    //if index is out of bound or input the incorrect range, return -1.
    if(start < 0 || end > size-1 || start > end){
        printf("%s","\nSorry input index are out of bound");
        return -1;
    }
    int max = array[start];
    for(int i = start+1 ; i <= end ; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}
//reverse the elements order in the array
void reverseArray(int array[], int size){
    int temp = 0;
    for(int i = 0 ; i < size/2 ; i++){
        temp = array[i];
        array[i] = array[size-1-i];
        array[size-1-i] = temp;
    }
}
//reverse the element order within the range [start,end] in the array
int reverseSelectedRangeWithinArray(int array[],int size,int start,int end){
    //if indexs are out of bound or input the incorrect range, return -1.
    if(start < 0 || end > size-1 || start > end){
        printf("%s","\nSorry input index are out of bound");
        return -1;
    }
    int temp = 0;
    for(int i = start ; i <= (end+start)/2 ; i++){
        temp = array[i];
        array[i] = array[end+start-i];
        array[end+start-i] = temp;
    }
    return 0;
}
//find the sequence (num1,num2) in the array.
//return the index of num1 if the sequence is found otherwise return -1.
int findSequence(int array[], int size,int num1,int num2){
    //loop over the entire array,
    //return the index if the sequence is found
    for(int i = 0 ; i < size-1 ; i++){
        if(array[i] == num1){
            if(array[i+1] == num2){
                return i;
            }
        }
    }
    //return -1 if the loop is over and yet no value was returned
    return -1;
}

