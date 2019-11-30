#ifndef __MYBANK_H__
#define __MYBANK_H__

#define NUN_Of_ACCOUNTS 50

double bank_accounts[NUN_Of_ACCOUNTS][2];

int Init();
int Open(double amount);
int Balance(int account_num);
int Deposit(int account_num, double amount);
int Withdrawal(int account_num,double amount);
int Close(int account_num);
int Rate(double rate);
void printAll();
void closeAll();

#endif