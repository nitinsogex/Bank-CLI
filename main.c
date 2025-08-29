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