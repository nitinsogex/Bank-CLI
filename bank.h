#ifndef BANK_H
#define BANK_H

#define MAX_USERS 10

// This file contains the declarations of the functions that are defined in bank.c


// Structure to define a bank account

struct BankAccount {
     char UID[13];
     char fullName[100];
     char mobileNumber[11];
     char address[200];
     char email[50];
     double balance;
     char password[50];
};


// Global variables (declared here, defined in bank.c)
extern struct BankAccount userAccounts[MAX_USERS];
extern char inputUsername[50];
extern int i;
extern int ID;
extern int userCount;
extern int isUserLoggedin;
extern int isAdminLoggedin;


// Function prototype for printing the Heading
void Heading();

// Function prototype for logging in as an admin
int adminLogin();

// Function prototype to display the menu options to the admin
int adminMenu();

// Function prototype for logging in as a user
int userLogin();

// Function prototype to display the menu options to the user
int userMenu();

// Function prototype for creating an account through admin
int createAccountbyAdmin();

// Function prototype for creating an account as a user
int createAccountbyUser();

// Function prototype for checking if the account exist or not
int checkUserbyUID(const char UID[]);

// Function prototype for checking account details (By admin)
void checkAccountDetails();

// Function prototype for checking account details (By user)
void checkAccountDetailsbyUser();

// Function prototype for transferring funds from one account to another (By admin)
void transferFunds();

// Function prototype for transferring funds from one account to another (By user)
void transferFundsbyUser();

// Function prototype for cash deposit (Through admin only)
void cashDeposit();

// Function prototype for cash withdrawal (Through admin only)
void cashWithdrawal();

// Function prototype for resetting password
void resetPassword();

// Function prototype for balance inquiry
void balanceInquiry();

// Function prototype for validating available balance
void checkBalance();

#endif // BANK_H