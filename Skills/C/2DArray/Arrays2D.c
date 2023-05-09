#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int row,int column,const int array[row][column]);
void displayOutPuts(int row,int column,const int array[row][column]);
int rowSum(int row,int column,const int array[row][column],int x);
int columnSum(int row,int column,const int array[row][column],int y);
int isSquare(int row,int column);


int main(){
    unsigned int row,column,flag;
    srand((unsigned)time(NULL));

    puts("Let's create a 2Dim array!\n");
//user input row and column of the 2D array
    do{
        printf("\tHow many rows? ");
        flag = scanf("%d",&row);
        if(flag <= 0){
            puts("\tSorry, your input rows is invalid, Please try again.");
        }
        fflush(stdin);
    }while(flag <= 0);
    do{
        printf("\tHow many columns? ");
        flag = scanf("%d",&column);
        if(flag <= 0){
            puts("\tSorry, your input columns is invalid, Please try again.");
        }
        fflush(stdin);
    }while(flag <= 0);
    int array[row][column];
    puts("");

//initialize the array by user input
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("\tenter [%d] [%d]: ",i,j);
            do{
                flag = scanf("%d",&array[i][j]);
                if(flag <= 0){
                    puts("\tSorry, your input rows is invalid, Please try again.");
                }
                fflush(stdin);
            }while(flag <= 0);
        }
    }
    puts("");
//test rowSum() function
    for(int i = 1; i <= row; i++){
        printf("\tSum of row %d = %d\n",i,rowSum(row,column,array,i));
    }
    puts("");
//test rowSum() function
    for(int j = 1; j <= column; j++){
        printf("\tSum of column %d = %d\n",j,columnSum(row,column,array,j));
    }
    puts("");
//test isSquare() function
    if(isSquare(row,column)){
        printf("\tThis is a square array.\n");
    }else{
        printf("\tThis is not a square array.\n");

    }
//test displayOutPuts() function
    puts("");
    displayOutPuts(row,column,array);
//test max() function
    puts("");
    printf("\tThe maximum number in the random 2D array is %d.\n",max(row,column,array));





    exit(1);
}

//return the maximum number in the 2D array
int max(int row,int column,const int array[row][column]){
    int max = array[0][0];
    for(int i = 0; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            if(max < array[i][j]){
                max = array[i][j];
            }
        }
    }
    return max;
}

//print the 2D array to the screeen
void displayOutPuts(int row,int column,const int array[row][column]){
     printf("%s","\tHere is your 2Dim array:\n");
    for(int i = 0; i < row ; i++){
       printf("%s","\t[");
        for(int j = 0 ; j < column ; j++){
            if(j== column -1){
                printf("%3d",array[i][j]);
            }else if(j == 0){
                printf("%d,",array[i][j]);
            }else{
                printf("%3d,",array[i][j]);
            }
        }
        printf("%s","]");
        puts("");
    }
}
//return sum of numbers in row x.
int rowSum(int row,int column,const int array[row][column],int x){
    int sum = 0;
    for(int i = 0; i < column; i++){
        sum += array[x-1][i];
    }
    return sum;
}
//return sum of numbers in column y.
int columnSum(int row,int column,const int array[row][column],int y){
    int sum = 0;
    for(int i = 0; i < row; i++){
        sum += array[i][y-1];
    }
    return sum;
}

//return true if the 2D array is a square array
int isSquare(int row,int column){
    if(row == column){
        return 1;
    }
    return 0;
}
