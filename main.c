#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_USERS 10

char inputUsername[50];
int i, ID;
int isUserLoggedin = -1, isAdminLoggedin = -1;

struct BankAccount {
     char UID[13];
     char fullName[100];
     char mobileNumber[11];
     char address[200];
     char email[50];
     double balance;
     char password[50];
};

struct BankAccount userAccounts[MAX_USERS];
int userCount = 0;

void Heading();
void Heading() {
     clrscr();
     printf("\n\n  \x1B[36m*****\x1B[0m         \x1B[7m Welcome to ANovative Technologies Bank Limited \x1B[0m         \x1B[36m*****\x1B[0m\n\n");
     printf("\n  ****************************************************************************\n");
}

int adminLogin();
int adminLogin() {
     const char username[] = "NitinSoge";
     const char password[] = "********";
     char inputPassword[20];
     Heading();
     printf("\n\x1B[33m  Enter admin login details\x1B[0m\n");
     printf("\n                Enter username: ");
     scanf("%s", inputUsername);

     printf("\n                Enter password: ");
     scanf("%s", inputPassword);

     if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0) {
	  return 1;
     }
     else {
	  return 0;
     }
}

int adminMenu();
int adminMenu() {
     int choice;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n\n   \x1B[33mAdmin Menu\n",inputUsername);
     printf("\n 1. Open an account");
     printf("\n 2. Check account details");
     printf("\n 3. Total available accounts");
     printf("\n 4. Balance inquiry");
     printf("\n 5. Fund Transfer");
     printf("\n 6. Deposit Cash");
     printf("\n 7. Withdraw Cash");
     printf("\n 8. Logout");
     printf("\n 9. Exit\x1B[0m");
     printf("\n\n                    Enter your choice => ");
     scanf("%d", &choice);
     return choice;
}

int userLogin();
int userLogin() {
     int userIndex;
     char inputPassword[20];
     Heading();
     printf("\n\x1B[33m  Enter user login details\x1B[0m\n");
     printf("\n                Enter username: ");
     scanf("%s", &inputUsername);

     printf("\n                Enter password: ");
     scanf("%s", &inputPassword);

     userIndex = checkUserbyUID(inputUsername);

     if(userIndex != -1) {
	  if(strcmp(userAccounts[userIndex].password, inputPassword) == 0) {
	       strcpy(inputUsername, userAccounts[userIndex].fullName);
	       ID = userIndex;
	       return 1;
	  }
	  else {
	       return 0;
	  }
     }
     else {
	  return 0;
     }
}

int userMenu();
int userMenu() {
     int choice;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n\n   \x1B[33mUser Menu\n",inputUsername);
     printf("\n 1. Check Balance");
     printf("\n 2. Check Account Details");
     printf("\n 3. Fund Transfer");
     printf("\n 4. Reset Password");
     printf("\n 5. Logout");
     printf("\n 6. Exit\x1B[0m");
     printf("\n\n                    Enter your choice => ");
     scanf("%d", &choice);
     return choice;
}

int createAccountbyAdmin();
int createAccountbyAdmin() {
     char name[100], uid[13], mobno[11], email[50];
     int len, i, onlyAlphabets, check, isValid, atPosition;
     if(userCount < MAX_USERS) {
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome: %s\x1B[0m\n   ",inputUsername);
	       printf("\n  \x1B[33mCreate new account: Enter correct details of the user\x1B[0m\n\n");
	       printf("  Full Name     : ");
	       scanf(" %[^\n]", &name);
	       len = strlen(name);
	       onlyAlphabets = 1;
	       for (i = 0; i < len; i++) {
		    if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' '))) {
		    onlyAlphabets = 0;
		    break;
		    }
	    }
	       if(onlyAlphabets == 1) {
		    strcpy(userAccounts[userCount].fullName, name);
		    break;
	       }
	       else {
		    printf("\n\n\n\n\n\n  \x1B[31mName shouldn't contain digits or special characters\n  Press any key to try again\x1B[0m");
		    getch();
	       }
	  }
	  while (1);
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome: %s\x1B[0m\n   ",inputUsername);
	       printf("\n  \x1B[33mCreate new account: Enter correct details of the user\x1B[0m\n\n");
	       printf("  Full Name     : %s\n", userAccounts[userCount].fullName);
	       printf("  UID           : ");
	       scanf(" %[^\n]", &uid);
	       len = strlen(uid);
	       onlyAlphabets = 1;
	       if(len == 12) {
		    for(i=0; i<len; i++) {
			 if(!(uid[i] >= '0' && uid[i] <= '9')) {
			      onlyAlphabets = 0;
			      break;
			 }
		    }
		    if(onlyAlphabets == 1) {
			 check = checkUserbyUID(uid);
			 if(check == -1) {
			      strcpy(userAccounts[userCount].UID, uid);
			      break;
			 }
			 else {
			      printf("\n\n  \x1B[31mMultiple accounts can't be create with the same UID\n  Press any key to go back to menu\x1B[0m");
			      getch();
			      return 0;
			 }
		    }
		    else {
			 printf("\n\n\n\n\n  \x1B[31mUID must contain only digits\n  Press any key to try again\x1B[0m");
			 getch();
		    }
	       }
	       else {
		    printf("\n\n\n\n\n  \x1B[31mLength should be 12\n  Press any key to try again\x1B[0m");
		    getch();
	       }
	  }
	  while(1);
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome: %s\x1B[0m\n   ",inputUsername);
	       printf("\n  \x1B[33mCreate new account: Enter correct details of the user\x1B[0m\n\n");
	       printf("  Full Name     : %s\n", userAccounts[userCount].fullName);
	       printf("  UID           : %s\n", userAccounts[userCount].UID);
	       printf("  Mobile Number : ");
	       scanf(" %[^\n]", &mobno);
	       len = strlen(mobno);
	       onlyAlphabets = 1;
	       if(len == 10) {
		    for(i=0; i<len; i++) {
			 if(!(mobno[i] >= '0' && mobno[i] <= '9')) {
			      onlyAlphabets = 0;
			      break;
			 }
		    }
		    if(onlyAlphabets == 1) {
			 strcpy(userAccounts[userCount].mobileNumber, mobno);
			 break;
		    }
		    else {
			 printf("\n\n\n\n  \x1B[31mMobile Number must contain only digits\n  Press any key to try again\x1B[0m");
			 getch();
		    }
	       }
	       else {
		    printf("\n\n\n\n  \x1B[31mLength should be 10\n  Press any key to try again\x1B[0m");
		    getch();
	       }
	  }
	  while(1);
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome: %s\x1B[0m\n   ",inputUsername);
	       printf("\n  \x1B[33mCreate new account: Enter correct details of the user\x1B[0m\n\n");
	       printf("  Full Name     : %s\n", userAccounts[userCount].fullName);
	       printf("  UID           : %s\n", userAccounts[userCount].UID);
	       printf("  Mobile Number : %s\n", userAccounts[userCount].mobileNumber);
	       isValid = 0;
	       atPosition = -1;
	       printf("  Email ID      : ");
	       scanf(" %[^\n]", email);
	       for(i=0; i<strlen(email); i++) {
		    if(email[i] == ' ') {
			 break;
		    }
		    if(email[i] == '@') {
			 atPosition = i;
			 isValid = 1;
			 break;
		    }
	       }
	       if(isValid) {
		    isValid = 0;
		    for(i=atPosition+1; i<strlen(email); i++) {
			 if (email[i] == '.') {
			      isValid = 1;
			      break;
			 }
		    }
		    if(isValid) {
			 for(i=0; i<=strlen(email); i++) {
			      if(email[i] == ' ') {
				   isValid = 0;
				   break;
			      }
			 }
			 if(isValid) {
			      strcpy(userAccounts[userCount].email, email);
			      break;
			 }
		    }
	       }
	       printf("\n\n\n  \x1B[31mInvalid Email ID\n  Plese enter correct details\x1B[0m");
	       getch();
	  }
	  while(1);
	  printf("  Address       : ");
	  scanf(" %[^\n]", &userAccounts[userCount].address);
	  printf("  Password      : ");
	  scanf(" %[^\n]", &userAccounts[userCount].password);
	  userAccounts[userCount].balance = 0.0;
	  userCount++;
	  printf("\n  \x1B[32mAccout Created Successfully!\n  Press any key to go back to menu\x1B[0m");
	  getch();
     }
     else {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n\n   ",inputUsername);
	  printf("\n\n  \x1B[31mMaximum number of accounts reached! New account can't be created\n  Press any key to go back to menu\x1B[0m");
	  getch();
     }
     return 0;
}

int createAccountbyUser();
int createAccountbyUser() {
     char name[100], uid[13], mobno[11], email[50];
     int len, i, onlyAlphabets, check, isValid, atPosition;
     if (userCount < MAX_USERS) {
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome to our bank! Your financial journey starts here.\x1B[0m\n   ");
	       printf("\n  \x1B[33mCreate new account: Enter your correct details\x1B[0m\n\n");
	       printf("  Full Name     : ");
	       scanf(" %[^\n]", &name);
	       len = strlen(name);
	       onlyAlphabets = 1;
	       for(i = 0; i < len; i++) {
		    if(!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' '))) {
			 onlyAlphabets = 0;
			 break;
		    }
	       }
	       if(onlyAlphabets) {
		    strcpy(userAccounts[userCount].fullName, name);
		    break;
	       }
	       else {
		    printf("\n\n\n\n\n\n  \x1B[31mName shouldn't contain digits or special characters\n  Press any key to try again\x1B[0m");
		    getch();
	       }
	  }
	  while(1);
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome to our bank! Your financial journey starts here.\x1B[0m\n");
	       printf("\n  \x1B[33mCreate new account: Enter your correct details\x1B[0m\n\n");
	       printf("  Full Name     : %s\n", userAccounts[userCount].fullName);
	       printf("  UID           : ");
	       scanf(" %[^\n]", &uid);
	       len = strlen(uid);
	       onlyAlphabets = 1;
	       if(len == 12) {
		    for(i = 0; i < len; i++) {
			 if(!(uid[i] >= '0' && uid[i] <= '9')) {
			      onlyAlphabets = 0;
			      break;
			 }
		    }
		    if(onlyAlphabets) {
			 check = checkUserbyUID(uid);
			 if(check == -1) {
			 strcpy(userAccounts[userCount].UID, uid);
			 break;
			 }
			 else {
			      printf("\n\n  \x1B[31mMultiple accounts can't be create with the same UID\n  Press any key to go back to menu\x1B[0m");
			      getch();
			      return 0;
			 }
		    }
		    else {
			 printf("\n\n\n\n\n  \x1B[31mUID must contain only digits\n  Press any key to try again\x1B[0m");
			 getch();
		    }
	       }
	       else {
		    printf("\n\n\n\n\n  \x1B[31mLength should be 12\n  Press any key to try again\x1B[0m");
		    getch();
	       }
	  }
	  while(1);
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome to our bank! Your financial journey starts here.\x1B[0m\n");
	       printf("\n  \x1B[33mCreate new account: Enter your correct details\x1B[0m\n\n");
	       printf("  Full Name     : %s\n", userAccounts[userCount].fullName);
	       printf("  UID           : %s\n", userAccounts[userCount].UID);
	       printf("  Mobile Number : ");
	       scanf(" %[^\n]", &mobno);
	       len = strlen(mobno);
	       onlyAlphabets = 1;
	       if(len == 10) {
		    for(i = 0; i < len; i++) {
			 if(!(mobno[i] >= '0' && mobno[i] <= '9')) {
			      onlyAlphabets = 0;
			      break;
			 }
		    }
		    if(onlyAlphabets) {
			 strcpy(userAccounts[userCount].mobileNumber, mobno);
			 break;
		    }
		    else {
			 printf("\n\n\n\n  \x1B[31mMobile Number must contain only digits\n  Press any key to try again\x1B[0m");
			 getch();
		    }
	       }
	       else {
		    printf("\n\n\n\n  \x1B[31mLength should be 10\n  Press any key to try again\x1B[0m");
		    getch();
	       }
	  }
	  while(1);
	  do {
	       Heading();
	       printf("\n  \x1B[32mWelcome to our bank! Your financial journey starts here.\x1B[0m\n");
	       printf("\n  \x1B[33mCreate new account: Enter your correct details\x1B[0m\n\n");
	       printf("  Full Name     : %s\n", userAccounts[userCount].fullName);
	       printf("  UID           : %s\n", userAccounts[userCount].UID);
	       printf("  Mobile Number : %s\n", userAccounts[userCount].mobileNumber);
	       isValid = 0;
	       atPosition = -1;
	       printf("  Email ID      : ");
	       scanf(" %[^\n]", email);
	       for(i = 0; i < strlen(email); i++) {
		    if(email[i] == '@') {
			 atPosition = i;
			 isValid = 1;
			 break;
		    }
	       }
	       if (isValid) {
		    isValid = 0;
		    for (i = atPosition + 1; i < strlen(email); i++) {
			 if (email[i] == '.') {
			      isValid = 1;
			      break;
			 }
		    }
		    if (isValid) {
			 for (i = 0; i <= strlen(email); i++) {
			      if (email[i] == ' ') {
				   isValid = 0;
				   break;
			      }
			 }
			 if (isValid) {
			      strcpy(userAccounts[userCount].email, email);
			      break;
			 }
		    }
	       }
	       printf("\n\n\n  \x1B[31mInvalid Email ID\n  Plese enter correct details\x1B[0m");
	       getch();
	  }
	  while(1);
	  printf("  Address       : ");
	  scanf(" %[^\n]", &userAccounts[userCount].address);
	  printf("  Password      : ");
	  scanf(" %[^\n]", &userAccounts[userCount].password);
	  userAccounts[userCount].balance = 0.0;
	  userCount++;
	  printf("\n\n  \x1B[32mAccout Created Successfully!\n  Press any key to go back to menu\x1B[0m");
	  getch();
	  return 1;
     }
     else {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n\n", inputUsername);
	  printf("\n\n  \x1B[31mMaximum number of accounts reached! New account can't be created\n  Press any key to go back to menu\x1B[0m");
	  return -1;
     }
}

int checkUserbyUID(const char UID[]);
int checkUserbyUID(const char UID[]) {
     for(i = 0; i < userCount; i++) {
	  if(strcmp(UID, userAccounts[i].UID) == 0) {
	       return i;
	  }
     }
     return -1;
}

void checkAccountDetails();
void checkAccountDetails() {
     char uidToCheck[13];
     int userIndex;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[33mCheck Account Details\e[0m\n\n\n               Enter the UID to check account details => ");
     scanf("%s", uidToCheck);

     userIndex = checkUserbyUID(uidToCheck);
     if(userIndex != -1) {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n\x1B[33m  Account details\x1B[0m\n\n ");
	  printf("\n\x1B[1m          Name\x1B[0m          : %s", userAccounts[userIndex].fullName);
	  printf("\n\x1B[1m          UID/A.c No.\x1B[0m   : %s", userAccounts[userIndex].UID);
	  printf("\n\x1B[1m          Mobile Number\x1B[0m : %s", userAccounts[userIndex].mobileNumber);
	  printf("\n\x1B[1m          Email\x1B[0m         : %s", userAccounts[userIndex].email);
	  printf("\n\x1B[1m          Address\x1B[0m       : %s", userAccounts[userIndex].address);
	  printf("\n\x1B[1m          Balance\x1B[0m       : %.2f", userAccounts[userIndex].balance);
     }
     else {
	  printf("\n\n  \x1B[31mAccount not found.\n  Press any key to go back to menu\x1B[0m");
     }
     getch();
}

void checkAccountDetailsbyUser();
void checkAccountDetailsbyUser() {
     Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n\x1B[33m     Account details\x1B[0m\n\n ");
	  printf("\n\x1B[1m          Name\x1B[0m          : %s", userAccounts[ID].fullName);
	  printf("\n\x1B[1m          UID/A.c No.\x1B[0m   : %s", userAccounts[ID].UID);
	  printf("\n\x1B[1m          Mobile Number\x1B[0m : %s", userAccounts[ID].mobileNumber);
	  printf("\n\x1B[1m          Email\x1B[0m         : %s", userAccounts[ID].email);
	  printf("\n\x1B[1m          Address\x1B[0m       : %s", userAccounts[ID].address);
	  printf("\n\x1B[1m          Balance\x1B[0m       : %.2f", userAccounts[ID].balance);
}

void transferFunds();
void transferFunds() {
     char senderUID[13], receiverUID[13];
     double amount;
     int receiverIndex, senderIndex;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[33mTransfer Funds\x1B[0m\n");
     printf("  Enter UID (Sender): ");
     scanf("%s", senderUID);
     senderIndex = checkUserbyUID(senderUID);
     if(senderIndex != -1) {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n  \x1B[33mTransfer Funds\x1B[0m\n");
	  printf("\n  \x1B[1mFrom: %s,\n  Available Funds: %.2f\x1B[0m\n",userAccounts[senderIndex].fullName, userAccounts[senderIndex].balance);
	  printf("\n  Enter UID (Receiver): ");
	  scanf("%s", receiverUID);
	  receiverIndex = checkUserbyUID(receiverUID);
	  if(receiverIndex != -1) {
	       Heading();
	       printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	       printf("\n  \x1B[33mTransfer Funds\x1B[0m\n");
	       printf("\n  \x1B[1mFrom: %s,\n  Available Funds: %.2f\x1B[0m\n",userAccounts[senderIndex].fullName, userAccounts[senderIndex].balance);
	       printf("\n  \x1B[1mTo: %s,\n  Available Funds: %.2f\x1B[0m\n",userAccounts[receiverIndex].fullName, userAccounts[receiverIndex].balance);
	       printf("\n  Amount to transfer: ");
	       scanf("%lf", &amount);
	       if(amount > 0 && amount <= userAccounts[senderIndex].balance) {
		    userAccounts[senderIndex].balance -= amount;
		    userAccounts[receiverIndex].balance += amount;
		    printf("\n\n  \x1B[32mTransfer Successful!\n");
		    printf("\n  Press any key to go back to menu\x1B[0m");
	       }
	       else {
		    printf("\n\n  \x1B[31mInvalid amount or insufficient balance. Transfer failed.\n");
		    printf("\n  Press any key to go back to menu\x1B[0m");
	       }
	  }
	  else {
	       printf("\n\n  \x1B[31mInvalid UID\n  Press any key to go back to menu\x1B[0m");
	  }
     }
     else {
	  printf("\n\n  \x1B[31mInvalid UID\n  Press any key to go back to menu\x1B[0m");
     }
     getch();
}

void transferFundsbyUser();
void transferFundsbyUser() {
     char receiverUID[13];
     double amount;
     int receiverIndex;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[33mTransfer Funds\x1B[0m\n");
     printf("\n  \x1B[1mFrom: %s,\n  Available Funds: %.2f\x1B[0m",userAccounts[ID].fullName, userAccounts[ID].balance);
     printf("\n\n  Enter UID (Receiver): ");
     scanf("%s", receiverUID);
     receiverIndex = checkUserbyUID(receiverUID);
     if(receiverIndex != -1) {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n  \x1B[33mTransfer Funds\x1B[0m\n");
	  printf("\n  \x1B[1mFrom: %s,\n  Available Funds: %.2f",userAccounts[ID].fullName, userAccounts[ID].balance);
	  printf("\n\n  To: %s,\n  Available Funds: %.2f\x1B[0m",userAccounts[receiverIndex].fullName, userAccounts[receiverIndex].balance);
	  printf("\n\n  Amount to transfer: ");
	  scanf("%lf", &amount);
	  if(amount > 0 && amount <= userAccounts[ID].balance) {
	       userAccounts[ID].balance -= amount;
	       userAccounts[receiverIndex].balance += amount;
	       printf("\n\n  \x1B[32mTransfer Successful!");
	       printf("\n  Press any key to go back to menu\x1B[0m");
	  }
	  else {
	       printf("\n\n  \x1B[31mInvalid amount or insufficient balance. Transfer failed.\n");
	       printf("  Press any key to go back to menu\x1B[0m");
	  }
     }
     else {
	  printf("\n\n  \x1B[31mInvalid UID\n  Press any key to go back to menu\x1B[0m");
     }
     getch();
}

void cashDeposit();
void cashDeposit() {
     char accountUID[13];
     int accountIndex;
     double money;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[33mCash Deposit\x1B[0m\n");
     printf("\n  Enter UID => ");
     scanf("%s",accountUID);
     accountIndex = checkUserbyUID(accountUID);
     if(accountIndex != -1) {
	  Heading();
	  printf("  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n  \x1B[33mCash Deposit\x1B[0m\n");
	  printf("\n  \x1B[1mDepositor: %s,\n  Available Funds: %.2f\x1B[0m\n",userAccounts[accountIndex].fullName, userAccounts[accountIndex].balance);
	  printf("\n  Enter Cash amount => ");
	  scanf("%lf", &money);
	  if(money>0) {
	       userAccounts[accountIndex].balance = userAccounts[accountIndex].balance + money;
	       printf("\n\n  \x1B[32mCash deposit successful!\n  New available balance is %.2f", userAccounts[accountIndex].balance);
	  }
     }
     else {
	  printf("\n\n\n  \x1B[31mInvalid UID, press any key to back to menu\x1B[0m");
     }
     getch();
}

void cashWithdrawal();
void cashWithdrawal() {
     char accountUID[13];
     double money;
     int accountIndex;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[33mCash Withdrawal\x1B[0m\n");
     printf("\n  Enter UID => ");
     scanf("%s", accountUID);
     accountIndex = checkUserbyUID(accountUID);
     if(accountIndex != -1) {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n  \x1B[33mCash Withdrawal\x1B[0m\n");
	  printf("\n  \x1B[1mWithdrawer: %s,\n  Available Funds: %.2f\x1B[0m",userAccounts[accountIndex].fullName, userAccounts[accountIndex].balance);
	  printf("\n\n  Enter Cash amount => ");
	  scanf("%lf", &money);
	  if(money > 0) {
	       if(userAccounts[accountIndex].balance >= money) {
		    userAccounts[accountIndex].balance = userAccounts[accountIndex].balance - money;
		    printf("\n\n  \x1B[32mWithdrawal successful!\n  New available balance is %.2f", userAccounts[accountIndex].balance);
	       }
	       else {
		    printf("\n\n\n   Insufficient funds\n   Press any key to go back to menu");
	       }
	  }
	  else {
	       printf("\n\n\n  \x1B[31mInvalid Amount.\n  Press any key to go back to menu\x1B[0m");
	  }
     }
     else {
	  printf("\n\n  \x1B[31mInvalid UID.\n  Press any key to go back to menu\x1B[0m");
     }
     getch();
}

void resetPassword();
void resetPassword() {
     char newPassword[50], renewPassword[50];
     int confirmation;
     do {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n  \x1B[33mReset Password\x1B[0m");
	  printf("\n\n        Enter New Password    : ");
	  scanf(" %[^\n]", &newPassword);
	  printf("\n        Re-enter New Password : ");
	  scanf(" %[^\n]", &renewPassword);
	  if (strcmp(newPassword, renewPassword) == 0) {
	       strcpy(userAccounts[ID].password, newPassword);
	       printf("\n\n  \x1B[32mPassword Changed Successfully!\n  Press any key to go back to the menu\x1B[0m");
	       getch();
	       break;
	  }
	  else {
	       printf("\n\n  \x1B[31mPasswords doesn't matched!\n  Press any key to try again\x1B[0m");
	       getch();
	  }
     }
     while(1);
}

void balanceInquiry();
void balanceInquiry() {
     char accountUID[13];
     int accountIndex;
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[33mBalance Inquiry\x1B[0m");
     printf("\n\n\n          Enter UID => ");
     scanf("%s", &accountUID);
     accountIndex = checkUserbyUID(accountUID);
     if(accountIndex != -1) {
	  Heading();
	  printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
	  printf("\n  \x1B[33mBalance Inquiry\x1B[0m");
	  printf("\n\n  \x1B[33mAccount balance fetched successfully!\x1B[0m");
	  printf("\n\n\n               \x1B[1mA/c holder Name: %s\n\n               Available Funds: %.2f\x1B[0m",userAccounts[accountIndex].fullName, userAccounts[accountIndex].balance);
	  printf("\n\n   \x1B[32mPress any key to go back to menu\x1B[0m");
     }
     else {
	  printf("\n\n\n  \x1B[31mInvalid UID.\n  Press any key to go back to menu\x1B[0m");
     }
     getch();
}

void checkBalance();
void checkBalance() {
     Heading();
     printf("\n  \x1B[32mWelcome: %s\x1B[0m\n",inputUsername);
     printf("\n  \x1B[32mBalance Check\x1B[0m");
     printf("\n\n\n\n         \x1B[5mAvailable Balance: %.2f\x1B[0m", userAccounts[ID].balance);
     getch();
}

int main() {
     int choice, Select, attempts;
     start:
     attempts = 3;
     choice = 0;
     Select = 0;
     do {
	  Heading();
	  if(isAdminLoggedin == -1 && isUserLoggedin == -1) {
	       printf("\n\x1B[33m   Select the option from the below\x1B[0m\n");
	       printf("\n1. Admint Login");
	       printf("\n2. User Login");
	       printf("\n3. Don't have an account? Create a new one");
	       printf("\n4. Exit");
	       printf("\n\n                    Enter your choice => ");
	       if (scanf("%d", &Select) != 1) {
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\n\n   \x1B[31mInvalid input. Please enter a number.\x1B[0m\n");
    getch();
    continue; // Restart the loop
}
	       switch(Select) {
		    case 1:
			 while(1) {
			      isAdminLoggedin = adminLogin();
			      if (isAdminLoggedin == 1) {
				   break;
			      } else {
				   if(attempts - 1 != 0) {
					printf("\n\n\n   \x1B[31mLogin failed. Remaining attempts: %d\x1B[0m", attempts - 1);
					getch();
					attempts--;
				   }
				   else {
					if (isAdminLoggedin != 1) {
					printf("\n\n\n   \x1B[31mMaximum login attempts reached. Access denied.\n   Press any key to exit\x1B[0m");
					getch();
					return 0;
					}
					attempts--;
				   }
			      }
			 }
			 break;
		    case 2:
			 while(1) {
			      isUserLoggedin = userLogin();
			      if(isUserLoggedin == 1) {
				   break;
			      } else {
				   if(attempts - 1 != 0) {
					printf("\n\n\n   \x1B[31mLogin failed. Remaining attempts: %d\x1B[0m", attempts - 1);
					getch();
					attempts--;
				   }
				   else {
					if (isUserLoggedin != 1) {
					printf("\n\n\n   \x1B[31mMaximum login attempts reached. Access denied.\n   Press any key to exit\x1B[0m");
					getch();
					return 0;
					}
					attempts--;
				   }
			      }
			 }
			 break;
		    case 3:
			 isUserLoggedin = createAccountbyUser();
			 if(isUserLoggedin) {
			      strcpy(inputUsername, userAccounts[userCount-1].fullName);
			 }
			 break;
		    case 4:
			 return 0;
		    default:
			 printf("\n\n   \x1B[31mInvalid Selection, plese try again\x1B[0m");
			 getch();
	       }
	  }
	  else if(isAdminLoggedin == 1) {
	       choice = 0;
	       choice = adminMenu();
	       switch (choice) {
		    case 1:
			 createAccountbyAdmin();
			 break;
		    case 2:
			 checkAccountDetails();
			 break;
		    case 3:
			 Heading();
			 printf("\n   Total available accounts: %d", userCount);
			 break;
		    case 4:
			 balanceInquiry();
			 break;
		    case 5:
			 transferFunds();
			 break;
		    case 6:
			 cashDeposit();
			 break;
		    case 7:
			 cashWithdrawal();
			 break;
		    case 8:
			 isAdminLoggedin = -1;
			 isUserLoggedin = -1;
			 Heading();
			 printf("\n\n   \x1B[33mLogged out successfully!\n   Press any key to go back to the main menu\x1B[0m");
			 getch();
			 goto start;
			 break
			 ;
		    case 9:
			 return 0;
		    default:
			 printf("   \x1B[31mInvalid Choice\x1B[0m");
	       }
	       getch();
	  }
	  else if(isUserLoggedin == 1) {
               choice = 0;
	       choice = userMenu();
	       switch (choice) {
		    case 1:
			 checkBalance();
			 break;
		    case 2:
			 checkAccountDetailsbyUser();
			 break;
		    case 3:
			 transferFundsbyUser();
			 break;
		    case 4:
			 resetPassword();
			 break;
		    case 5:
			 isAdminLoggedin = -1;
			 isUserLoggedin = -1;
			 Heading();
			 printf("\n\n   \x1B[33mLogged out successfully!\n   Press any key to go back to the main menu\x1B[0m");
			 getch();
			 goto start;
			 break;
		    case 6:
			 return 0;
		    default:
			 printf("Invalid Choice");
	       }
	       getch();
	  }
     }
     while (choice != 9);

     getch();
     return 0;

}