/**
Xu Jiang
02/07/2023
CIS 2107-001
Lab 3
ATM Machine
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PIN 3014
#define INITIAL_BALANCE 5000
#define DEPOSITION_LIMITE 10000
#define WITHDRAWAL_LIMITE 1000

float Balance(float balance);
float cashWithdraw(float balance,int *withdrawalCounter);
float cashDeposit(float balance,int *depositionCounter);
void quit(float balance, int withdrawalCounter, int withdrawTimes, int depositionCounter, int depositionTimes);

int main(void){
    unsigned int pin;
    float balance;
    unsigned int choice;
    int flag01, counter, withdrawalCounter, withdrawTimes, depositionCounter, depositionTimes;

    pin = 3014;
    balance = INITIAL_BALANCE;
    choice = 0;
    flag01 = 0;
    counter = 0;
    withdrawalCounter = 0;
    withdrawTimes = 0;
    depositionCounter = 0;
    depositionTimes = 0;

    //welcome message and pin number
    puts("\tDear customer Nana, welcome to \"TEMPLE ATM\"");
    printf("\tPlease Enter your account pin number:");
    flag01 = scanf("%u",&pin);
    fflush(stdin);
    while(flag01 <= 0 || pin != PIN){
        counter++;
        if(counter >= 3){
            puts("\n\tThe attempts exceed limit, \"TEMPLE ATM\" shut down.");
            exit(0);
        }
        puts("\n\tSorry, the input pin is invalid, Please try again.");
        printf("\tPlease Enter your account pin number:");
        flag01 = scanf("%u",&pin);
        fflush(stdin);
    }

    //menu choice, exit the loop when the choice is 4
    while(choice != 4){
        puts("\n\tTEMPLE ATM Menu: \n\t1. Balance. \n\t2. Cash withdrawal. \n\t3. Cash deposition. \n\t4. Quit. ");
        printf("\n\tPlease input your choice:");
        flag01 = scanf("%u",&choice);
        fflush(stdin);
        //invalid input
        while(flag01 <= 0 || choice < 1 || choice > 4){
            puts("\n\tSorry, the input choice is invalid, Please try again.");
            printf("\tPlease input your choice:");
            flag01 = scanf("%u",&choice);
            fflush(stdin);
        }
        //calling function according to user input
        switch(choice){
        case 1:
            Balance(balance);
            break;
        case 2:
            if(withdrawalCounter >= WITHDRAWAL_LIMITE){
                puts("\tSorry, you have reach the day-limit for withdrawal. \n\tWe have helped you to withdraw all the money under the limit.");
            }else{
                balance = cashWithdraw(balance,&withdrawalCounter);
                withdrawTimes++;
            }
            break;
        case 3:
            if(depositionCounter >= DEPOSITION_LIMITE){
                puts("\tSorry, you have reach the day-limit for deposition. \n\tWe have helped you to deposit all the money under the limit.");
            }else{
                balance = cashDeposit(balance,&depositionCounter);
                depositionTimes++;
            }

        }
    }
    //Only choice 4 will exit the loop, which is quit the system
    quit(balance, withdrawalCounter, withdrawTimes, depositionCounter, depositionTimes);
}
float Balance(float balance){
    printf("\n\tDear Nana, your current balance is $%.1f\n",balance);
}
float cashWithdraw(float balance, int *withdrawalCounter){
    double cashFromUser;
    double intPart;
    unsigned int cash;
    unsigned int answer;
    int flag01;

    cashFromUser = 0;
    intPart = 0;
    cash = 0;
    answer = 0;
    flag01 = 0;

    //enter withdrawing cash
    printf("\tPlease enter cash amount you wish to withdraw (at a multiples of 20):");
    flag01 = scanf("%lf",&cashFromUser);
    fflush(stdin);
    //invalid input, wrong type, negative and zero, decimal number, not a multiples of 20
    while(flag01 <= 0 || cashFromUser <= 0 || modf(cashFromUser,&intPart) != 0 || (int)intPart%20 != 0){
        puts("\n\tSorry, the input cash amount is invalid, Please try again.");
        printf("\tPlease enter cash amount you wish to withdraw (at a multiples of 20):");
        flag01 = scanf("%lf",&cashFromUser);
        fflush(stdin);
    }

    //add the withdrawing cash to counter,
    //if the total amount exceed the limit, withdraw all the available money under the limit.
    cash = (int) intPart;
    *withdrawalCounter += cash;
    if(*withdrawalCounter >= WITHDRAWAL_LIMITE){
        cash = WITHDRAWAL_LIMITE - *withdrawalCounter+cash;
        *withdrawalCounter = WITHDRAWAL_LIMITE;
        puts("\tSorry, you have reached the day-limit for withdrawal. \n\tWe have helped you to withdraw all the money under the limit.");
    }

    //print receipt information according to user input.
    puts("\n\tDo you wish to have your receipt?");
    printf("\tPlease input your answer(1 for YES,2 for NO):");
    flag01 = scanf("%u",&answer);
    fflush(stdin);
    while(flag01 <= 0 || (answer != 1 && answer != 2)){
        puts("\n\tSorry, the input choice is invalid, Please try again.");
        printf("\tPlease input your answer(1 for YES,2 for NO):");
        flag01 = scanf("%u",&answer);
        fflush(stdin);
    }
    if(answer == 1){
        if(*withdrawalCounter >= WITHDRAWAL_LIMITE){
            puts("\tYou withdrew $1000 today.");
        }else{
            printf("\tYou withdrew $%d today.",*withdrawalCounter);
        }
        Balance(balance - cash);
    }

    return balance - cash;
}
float cashDeposit(float balance,int *depositionCounter){
    double cashFromUser;
    double intPart;
    unsigned int cash;
    unsigned int answer;
    int flag01;

    cashFromUser = 0;
    intPart = 0;
    cash = 0;
    answer = 0;
    flag01 = 0;


    //Enter depositing cash
    printf("\tPlease enter cash amount you wish to deposit (No coins are accepted):");
    flag01 = scanf("%lf",&cashFromUser);
    fflush(stdin);
    //invalid input, wrong type, negative and zero, decimal number
    while(flag01 <= 0 || cashFromUser <= 0 || modf(cashFromUser,&intPart) != 0){
            puts("\n\tSorry, the input cash amount is invalid, Please try again.");
            printf("\tPlease enter cash amount you wish to deposit (No coins are accepted):");
            flag01 = scanf("%lf",&cashFromUser);
            fflush(stdin);
    }

    //add depositing cash to counter
    cash = (int) intPart;
    *depositionCounter += cash;
    //if the overall counter exceeds limit, deposit all available money under the limit.
    if(*depositionCounter >= DEPOSITION_LIMITE){
        cash = DEPOSITION_LIMITE - *depositionCounter+cash;
        *depositionCounter = DEPOSITION_LIMITE;
        puts("\tSorry, you have reached the day-limit for deposition. \n\tWe have helped you to deposit all the money under the limit.");
    }

    //print receipt information according to user input
    puts("\n\tDo you wish to have your receipt?");
    printf("\tPlease input your answer(1 for YES,2 for NO):");
    flag01 = scanf("%u",&answer);
    fflush(stdin);
    while(flag01 <= 0 || (answer != 1 && answer != 2)){
        puts("\n\tSorry, the input choice is invalid, Please try again.");
        printf("\tPlease input your answer(1 for YES,2 for NO):");
        flag01 = scanf("%u",&answer);
        fflush(stdin);
    }
    if(answer == 1){
        if(*depositionCounter >= DEPOSITION_LIMITE){
            puts("\tYou deposited $10000 today.");
        }else{
            printf("\tYou deposited $%d today.",*depositionCounter);
        }
        Balance(balance + cash);
    }
    return balance + cash;
}
void quit(float balance, int withdrawalCounter, int withdrawTimes, int depositionCounter, int depositionTimes){
    //print out information and shut the system
    Balance(balance);
    printf("\tYou withdrew %d times and deposited %d times today.\n",withdrawTimes, depositionTimes);
    printf("\tYou total withdrawal is $%d and total deposition is $%d today\n",withdrawalCounter,depositionCounter);
    puts("\tThank you for using \"TEMPLE ATM\",Have a great day!");
    exit(1);
}
