#include <stdio.h>
#include "myBank.h"

extern double bank_accounts[NUN_Of_ACCOUNTS][2];

static int isAccountNumValid(int account_num)
{
    if (account_num >= 901 && account_num<= 950)
    {
        return 0;
    }
    printf("Illegal account number!\n");
    return 1;
}

static int isAccountExist(int account_num)
{
    if (isAccountNumValid(account_num) == 1)
        return 1;
    if (bank_accounts[account_num-901][1] == 1)
        return 0;
    printf("no account: %d\n", account_num);
    return 1;
}

int Init()
{
    for (int i=0; i<NUN_Of_ACCOUNTS; i++)
    {
        bank_accounts[i][0] = 0;
        bank_accounts[i][1] = 0;
    }
    return 0;
}

int Open(double amount)
{
    if(amount < 0)
    {
        printf("cannot open account with debt!\n");
        return 1;
    }
    for (int i=0; i<NUN_Of_ACCOUNTS; i++)
    {
        if (bank_accounts[i][1] == 0)
        {
            bank_accounts[i][1] = 1;
            bank_accounts[i][0] = amount;
            printf("opened account: %d\n", 901+i);
            return 0;
        }
    }
    printf("cannot open account ! all accounts are occupied ! \n");
    return 1;
}

int Balance(int account_num)
{
    if (isAccountExist(account_num) == 1)
        return 1;
    printf("account %d balance: %0.2f\n", 
        account_num, bank_accounts[account_num-901][0]);
    return 0;
}

int Deposit(int account_num, double amount)
{
    if (isAccountExist(account_num) == 1)
        return 1;
    if (amount<0)
    {
        printf("cannot deposit negative ammount of money!\n");
        return 1;
    }
    bank_accounts[account_num-901][0] += amount;
    return Balance(account_num);
}

int Withdrawal(int account_num,double amount)
{
    if (isAccountExist(account_num) == 1)
        return 1;
    if (amount<0)
    {
        printf("cannot withdrawal negative ammount of money!\n");
        return 1;
    }
    if (amount > bank_accounts[account_num-901][0])
    {
        printf("cannot withdrawal !\n");
        printf("requested: %0.2lf, account has only %0.2lf\n", 
            amount, bank_accounts[account_num-901][0]);
        return 1;
    }
    bank_accounts[account_num-901][0] -= amount;
    return Balance(account_num);
}

int Close(int account_num)
{
    if (isAccountExist(account_num) == 1)
        return 1;
    bank_accounts[account_num-901][1] = 0;
    return 0;
}

int Rate(double rate)
{
    if(rate < 0)
    {
        printf("Illegal rate!\n");
        return 1;
    }
    double p = (rate/100)+1;
    for (int i=0; i<NUN_Of_ACCOUNTS; i++)
    {
        if (bank_accounts[i][1] != 0)
        {
            bank_accounts[i][0]*=p;
        }
    }
    return 0;
}

void printAll()
{
    for (int i=0; i<NUN_Of_ACCOUNTS; i++)
    {
        if (bank_accounts[i][1] != 0)
        {
            Balance(901+i);
        }
    }
}

void closeAll()
{
    for (int i=0; i<NUN_Of_ACCOUNTS; i++)
    {
        if (bank_accounts[i][1] != 0)
        {
            Close(901+i);
        }
    }
}