
/*
Name: Xu Jiang
Date: 3/14/2023
Course: CSI2107
HW#: Lab 06: “Race”
*/
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos =1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos != 70 && tPos!=70){
		sleep(1);			//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
    }
    //print the winning statement
    if(hPos == 70 && tPos == 70){
        puts("It is a tie");
    }else if(hPos == 70){
        puts("Hare wins. Yuch.");
    }else{
        puts("TORTOISE WINS!!! YAY!!!");
    }
    exit(0);

}

//Finds minimum of hare or tortoise position to decide which position to print first
//return 1(true) if hare is minimum
//otherwise return 0(false) if tortoise is minimum
//return -1 if hare and tortoise is at the same location
int min(int hMin, int tMin){
    if(hMin==tMin){
        return -1;
    }
    if(hMin < tMin){
        return 1;
    }else{
         return 0;
    }

}

//Prints the position of the H and T
void printRace(int hPos,int tPos){
    //the tortoise bite hare at the same location
    if(min(hPos,tPos) == -1){
        for(int i = 1 ; i < hPos; i++){
            printf("%s"," ");
        }
        printf("OUCH!!!");
        //finish line
        for(int i = 7; i < (70-tPos) ; i++){
            printf("%s"," ");
        }
        printf("%1s","|");
        puts("");
        return;
    }
    //hare is minimum
    if(min(hPos,tPos)){
        //print spaces before hare
        for(int i = 1 ; i < hPos; i++){
            printf("%s"," ");
        }
        printf("%s","H");
        //print the spaces between hare and tortoise
        for(int i = 1; i < (tPos - hPos);i++){
            printf("%s"," ");
        }
        printf("%s","T");

        //finish line
        for(int i = 1; i < (70-tPos) ; i++){
            printf("%s"," ");
        }
        if((70-tPos) != 0)
        printf("%s","|");
    //tortoise is minimum
    }else{
        //print spaces before tortoise
        for(int i = 1 ; i < tPos; i++){
            printf("%s"," ");
        }
        printf("%s","T");
        //print the spaces between tortoise and hare
        for(int i = 1; i < (hPos - tPos);i++){
            printf("%s"," ");
        }
        printf("%s","H");

        //finish line
        for(int i = 1; i < (70-hPos) ; i++){
            printf("%s"," ");
        }
        if((70-hPos) != 0)
        printf("%s","|");
    }
    puts("");
}

//Controls the tortoise movement
/*Tortoise  movement
Fast plod 1-5(50%)  : 3 squares to the right
Slip      6-7(20%)  : 6 squares to the left
Slow plod 8-10(30%) : 1 square to the right
*/
//The tortoise will only return to the starting point (1) in minimum and reach the destination (70) in maximum
void tortMove(int *tPtr){
    int moveChoice = randomNumberGenerator();
    if(moveChoice <= 5){
        *tPtr += 3;
    }else if(moveChoice <= 7){
        *tPtr -= 6;
    }else{
        *tPtr += 1;
    }
    //ensure the tortoise stays in track 1-70
    if(*tPtr > 70){
        *tPtr = 70;
    }else if(*tPtr < 1){
        *tPtr = 1;
    }
}

//Controls the hare movement
/*Hare movement
Sleep       1-2(20%)  : No move at all
Big hop     3-4(20%)  : 9 squares to the right
Big slip    5(10%)    : 12 squares to the left
Small hop   6-8(30%)  : 1 square to the right
Small slip  9-10(20%) : 2 squares to the left
*/
//The hare will only return to the starting point (1) in minimum and reach the destination (70) in maximum
void hareMove(int *hPtr){
    int moveChoice = randomNumberGenerator();
    if(moveChoice <= 2){
    }else if(moveChoice <= 4){
        *hPtr += 9;
    }else if(moveChoice <= 5){
        *hPtr -= 12;
    }else if(moveChoice <= 8){
        *hPtr += 1;
    }else{
        *hPtr -= 2;
    }
    //ensure the hare stays in track 1-70
    if(*hPtr > 70){
        *hPtr = 70;
    }else if(*hPtr < 1){
        *hPtr = 1;
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
    return rand()%INT_MAX+INT_MIN;
}
