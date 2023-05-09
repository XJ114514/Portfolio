/*
Name: Xu Jiang
Date: 2/28/2023
Course: CSI2107
HW#: Lab 05: ““Arrays of Pointers to Functions”

Objective: To design and implement array of function pointer.

The purpose of this program is to modify existing code related to examslecting
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average.

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>
void printArray(int students, int exams, const int grades[students][exams]);
void minimum(int students, int exams, const int grades[students][exams]);
void maximum(int students, int exams, const int grades[students][exams]);
void average(int students, int exams, const int grades[students][exams]);

int main(){
    void (*funcPtr[4])(int students, int exams, const int grades[students][exams]) = {printArray,minimum,maximum,average};
    int input,students,exams;

    puts("\n\tWelcome to \"TEMPLE GRADE\" program");
//catch user input for rows and columns
    printf("%s","\tPlease enter the rows:");
    scanf("%d",&students);
    fflush(stdin);
    printf("%s","\tPlease enter the columns:");
    scanf("%d",&exams);
    fflush(stdin);

//initialize the array by user input
    int grades[students][exams];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            printf("\tgrades [%d] [%d]: ",i,j);
            scanf("%d",&grades[i][j]);
            fflush(stdin);
        }
    }


    do{
        puts("\n\tEnter your choice:");
        puts("\t\t0  Print the array of grade");
        puts("\t\t1  Find the minimum grade");
        puts("\t\t2  Find the maximum grade");
        puts("\t\t3  Print the average on all tests for each student");
        puts("\t\t4  End Program\n");
        printf("%s","\tPlease enter your choice:");
        //catch user input
        scanf("%d",&input);
        fflush(stdin);
        //if the input is valid (0,1,2,3) run the target function
        if(input >= 0 && input <= 3){
            funcPtr[input](students,exams,grades);
            puts("");
        }
    //input any number (4 will also end the program) besides 0,1,2,3 will end the program
    }while(input >= 0 && input <= 3);
    puts("\n\tThank you for using \"TEMPLE GRADE\" program");
    exit(1);
}

void printArray(int students, int exams, const int grades[students][exams]){
    printf("%s","\t\t");
    for(int i = 0; i < exams; i++){
        printf("\texam%-5d",i);
    }
    puts("");
    for(int i = 0; i < students; i++){
            printf("\tStudent%d",i);
        for(int j = 0; j < exams; j++){
            printf("\t%-10d",grades[i][j]);
        }
        puts("");
    }
}
void minimum(int students, int exams, const int grades[students][exams]){
    int min = grades[0][0];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(min > grades[i][j]){
                min = grades[i][j];
            }
        }
    }
    printf("\tThe minimum grade is %d",min);
}
void maximum(int students, int exams, const int grades[students][exams]){
    int max = grades[0][0];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(max < grades[i][j]){
                max = grades[i][j];
            }
        }
    }
    printf("\tThe maximum grade is %d",max);
}
void average(int students, int exams, const int grades[students][exams]){
    int sum,counter;
    double average[students];
    for(int i = 0; i < students; i++){
        sum = 0;
        counter = 0;
        for(int j = 0; j < exams; j++){
            sum += grades[i][j];
            counter++;
        }
        average[i] = (double)sum/((double)counter);
    }
    puts("\t\t\taverage Grade");
    for(int i = 0; i < students; i++){
        printf("\tstudent%d\t%.1f\n",i,average[i]);
    }

}
