#include <stdio.h>
#include "myBank.h"

int main()
{
    char c = 0;
    double amount = 0;
    int account_num = 0;
    double rate = 0;

    Init();
    do 
    {
        printf("Transaction type?: ");
        while(scanf(" %c", &c) != 1)
        {
            printf("Illegal operation ! try again\n");
        }
        switch(c)
        {
            case 'O': 
            {
                printf("Initial deposit?: ");
                scanf("%lf", &amount);
                Open(amount);
            } break;
            case 'B':
            {
                printf("Account number?: ");
                scanf("%d", &account_num);
                Balance(account_num);
            } break;
            case 'D':
            {
                printf("Account number?: ");
                scanf("%d", &account_num);
                printf("Amount?: ");
                scanf("%lf", &amount);
                Deposit(account_num, amount);
            } break;
            case 'W':
            {
                printf("Account number?: ");
                scanf("%d", &account_num);
                printf("Amount?: ");
                scanf("%lf", &amount);
                Withdrawal(account_num, amount);
            } break;
            case 'C':
            {
                printf("Account number?: ");
                scanf("%d", &account_num);
                Close(account_num);
            } break;
            case 'I':
            {
                printf("‫‪Interest‬‬ rate?: ");
                scanf("%lf", &rate);
                Rate(rate);
            } break;
            case 'P':
            {
                printAll();
            } break;   
            case 'E':
            {
                closeAll();                
                Init();
                printf("‫‪Existing!\n");
            } break;   
            default:
            {
                printf("Illegal operation ! try again\n");
            } break;
        }
    } while(c != 'E');

    return 0;
}