#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_NID_LENGTH 15
#define MAX_TYPE_LENGTH 10

int totalAcntsNum = 0;
float totalMoney = 0.0;

struct node
{   
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    long long int NID;
    char accountType[MAX_TYPE_LENGTH];
    float balance;
    struct node *next;
} *head = NULL;

void displayMenu();
void registerAccount();
void listAccount();
void deleteAccount();
void deposit();
void withdrawal();
void searchAccount();
void displayBankStatus();
void freeNodes();
void loadDataFromFile();
void saveDataToFile();

int main()
{
    loadDataFromFile();
    int choice;
    printf("\n---Bank Account Management System---\n");
    displayMenu();

    while (1)
    {
        printf("\nEnter your choice (Display Menu '8'): ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            registerAccount();
            break;
        case 2:
            listAccount();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdrawal();
            break;
        case 5:
            searchAccount();
            break;
        case 6:
            deleteAccount();
            break;
        case 7:
            displayBankStatus();
            break;
        case 8:
            displayMenu();
            break;
        case 9:
            saveDataToFile();
            freeNodes();
            printf("\n---Thank You---\n\n");
            exit(1);

        default:
            printf("\nEnter the correct choice\n");
        }
    }
    return 0;
}

void displayMenu()
{
    printf("1. Register an Account\n");
    printf("2. List all Account\n");
    printf("3. Deposit\n");
    printf("4. Withdrawal\n");
    printf("5. Search an Account\n");
    printf("6. Delete an Account\n");
    printf("7. Bank Status\n");
    printf("8. Display Menu\n");
    printf("9. Exit\n");
}

void registerAccount()
{    
    printf("\n---Account Registration---\n");
    if (head == NULL)
    {   
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter customer details:\n");
        int acntnum1;
        printf("\nEnter Account Number to be registered: ");
        scanf("%d", &acntnum1);
        newnode->accountNumber = acntnum1;
        printf("Name: ");
        scanf(" %[^\n]", newnode->name);
        printf("Surname: ");
        scanf(" %[^\n]", newnode->surname);
        printf("NID (11 digits): ");
        char nidString[MAX_NID_LENGTH + 1]; 
        int nidLength;

        do {
            scanf("%s", nidString);
            nidLength = strlen(nidString);

            if (nidLength != 11) {
                printf("Please enter 11 digits for the NID: ");
            }
        } while (nidLength != 11);

        newnode->NID = atoll(nidString);
        
        printf("Address: ");
        scanf(" %[^\n]", newnode->address);
        printf("Account Type: ");
        scanf(" %[^\n]", newnode->accountType);
        printf("Balance: Tk ");
        scanf("%f", &newnode->balance);
        newnode->next = NULL;
        head = newnode;
        totalAcntsNum++;
        totalMoney = totalMoney + newnode->balance;
        printf("\n**Success**\n");
    }
    else
    {
        struct node *newnode, *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode = (struct node *)malloc(sizeof(struct node));

        

        printf("\nEnter customer details:\n");

        int acntnum1;
        printf("\nEnter Account Number to be registered: ");
        scanf("%d", &acntnum1);
        newnode->accountNumber = acntnum1;
        printf("Name: ");
        scanf(" %[^\n]", newnode->name);
        printf("Surname: ");
        scanf(" %[^\n]", newnode->surname);
        printf("NID (11 digits): ");
        char nidString[MAX_NID_LENGTH + 1];
        int nidLength;
        do {
            scanf("%s", nidString);
            nidLength = strlen(nidString);

            if (nidLength != 11) {
                printf("Please enter 11 digits for the NID: ");
            }
        } while (nidLength != 11);
        newnode->NID = atoll(nidString);
        printf("Address: ");
        scanf(" %[^\n]", newnode->address);
        printf("Account Type: ");
        scanf(" %[^\n]", newnode->accountType);
        printf("Balance: Tk ");
        scanf("%f", &newnode->balance);
        newnode->next = NULL;
        temp->next = newnode;
        totalAcntsNum++;
        totalMoney = totalMoney + newnode->balance;
        printf("\n**Success**\n");
    }
}

void listAccount()
{
    printf("\n---List of Registered Accounts---\n");

    if (head == NULL)
    {
        printf("\n**No Account Registered**\n");
    }
    else
    {
        int count = 1;
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("\nAccount Index: %d\n", count);
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n\n", temp->address);
            count++;
            temp = temp->next;
        }
    }
}

void searchAccount()
{
    printf("\n---Account Searching---\n");

    if (head == NULL)
    {
        printf("\n**No Account Registered**\n");
    }
    else
    {
        int option, flag = 0;
        struct node *temp;
        printf("\nSearching Criteria:\n");
        printf("1. Account Number\n");
        printf("2. Name\n");
        printf("3. Surname\n");
        printf("4. Address\n");
        printf("5. NID\n");
        printf("\nEnter option number: ");
        scanf("%d", &option);

        if (option == 1)
        {
            int acntNum;
            printf("\nEnter Account Number: ");
            scanf("%d", &acntNum);
            temp = head;
            while (temp->accountNumber != acntNum)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            flag = 1;
        }
        else if (option == 2)
        {
            char name2[MAX_NAME_LENGTH];
            printf("\nEnter Name: ");
            scanf(" %[^\n]", name2);

            temp = head;
            while (strcmp(temp->name, name2) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            flag = 1;
        }
        else if (option == 3)
        {
            char surname2[MAX_NAME_LENGTH];
            printf("\nEnter Name: ");
            scanf(" %[^\n]", surname2);

            temp = head;
            while (strcmp(temp->surname, surname2) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            flag = 1;
        }
        else if (option == 4)
        {
            char address2[MAX_ADDRESS_LENGTH];
            printf("\nEnter Address: ");
            scanf(" %[^\n]", address2);

            temp = head;
            while (strcmp(temp->address, address2) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            flag = 1;
        }
        else if (option == 5)
        {
            long long int NID2;
            char nidString[MAX_NID_LENGTH + 1]; 
            int nidLength;

            printf("\nEnter NID (11 digits): ");

            do {
                scanf("%s", nidString);
                nidLength = strlen(nidString);

                if (nidLength != 11) {
                    printf("Please enter 11 digits for the NID: ");
                }
            } while (nidLength != 11);
            NID2 = atoll(nidString);

            temp = head;
            while (temp->NID != NID2)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            flag = 1;
        }
        else
        {
            printf("\n**Enter Correct Option Number**\n");
        }
        if (flag == 0)
        {
            printf("\nAccount Not Found\n");
        }
    }
}

void withdrawal()
{
    printf("\n---Amount Withdrawal---\n");
    if (head == NULL)
    {
        printf("\n**No Account Registered**\n");
    }
    else
    {
        int option, flag = 0;
        float withdrawalamnt;
        struct node *temp;
        printf("\nSearching Criteria:\n");
        printf("1. Account Number\n");
        printf("2. Name\n");
        printf("3. Surname\n");
        printf("4. Address\n");
        printf("5. NID\n");
        printf("\nEnter option number: ");
        scanf("%d", &option);

        if (option == 1)
        {
            int acntNum;
            printf("\nEnter Account Number: ");
            scanf("%d", &acntNum);
            temp = head;
            while (temp->accountNumber != acntNum)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter withdrawal amount: Tk ");
            scanf("%f", &withdrawalamnt);
            temp->balance = temp->balance - withdrawalamnt;
            totalMoney = totalMoney - withdrawalamnt;
            printf("\nAmount Tk %.2f has been successfully withdrawn\n", withdrawalamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);
            flag = 1;
        }
        else if (option == 2)
        {
            char name2[MAX_NAME_LENGTH];
            printf("\nEnter Name: ");
            scanf(" %[^\n]", name2);

            temp = head;
            while (strcmp(temp->name, name2) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter withdrawal amount: Tk ");
            scanf("%f", &withdrawalamnt);
            temp->balance = temp->balance - withdrawalamnt;
            totalMoney = totalMoney - withdrawalamnt;
            printf("\nAmount Tk %.2f has been successfully withdrawn\n", withdrawalamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else if (option == 3)
        {
            char surname2[MAX_NAME_LENGTH];
            printf("\nEnter Name: ");
            scanf(" %[^\n]", surname2);

            temp = head;
            while (strcmp(temp->surname, surname2) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter withdrawal amount: ");
            scanf("%f", &withdrawalamnt);
            temp->balance = temp->balance - withdrawalamnt;
            totalMoney = totalMoney - withdrawalamnt;
            printf("\nAmount Tk %.2f has been successfully withdrawn\n", withdrawalamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else if (option == 4)
        {
            char address2[MAX_ADDRESS_LENGTH];
            printf("\nEnter Address: ");
            scanf(" %[^\n]", address2);

            temp = head;
            while (strcmp(temp->address, address2) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter withdrawal amount: ");
            scanf("%f", &withdrawalamnt);
            temp->balance = temp->balance - withdrawalamnt;
            totalMoney = totalMoney - withdrawalamnt;
            printf("\nAmount Tk %.2f has been successfully withdrawn\n", withdrawalamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else if (option == 5)
        {
            long long int NID2;
            char nidString[MAX_NID_LENGTH + 1]; 
            int nidLength;

            printf("\nEnter NID (11 digits): ");

            do {
                scanf("%s", nidString);
                nidLength = strlen(nidString);

                if (nidLength != 11) {
                    printf("Please enter 11 digits for the NID: ");
                }
            } while (nidLength != 11);
            NID2 = atoll(nidString);

            temp = head;
            while (temp->NID != NID2)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter withdrawal amount: ");
            scanf("%f", &withdrawalamnt);
            temp->balance = temp->balance - withdrawalamnt;
            totalMoney = totalMoney - withdrawalamnt;
            printf("\nAmount Tk %.2f has been successfully withdrawn\n", withdrawalamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else
        {
            printf("\n**Enter Correct Option Number**\n");
        }
        if (flag == 0)
        {
            printf("\nAccount Not Found\n");
        }
    }
}

void deposit()
{
    printf("\n---Account Deposit---\n");
    if (head == NULL)
    {
        printf("\n**No Account Registered**\n");
    }
    else
    {
        int option, flag = 0;
        float depositamnt;
        struct node *temp;
        printf("\nSearching Criteria:\n");
        printf("1. Account Number\n");
        printf("2. Name\n");
        printf("3. Surname\n");
        printf("4. Address\n");
        printf("5. NID\n");
        printf("\nEnter option number: ");
        scanf("%d", &option);

        if (option == 1)
        {
            int acntNum1;
            printf("\nEnter Account Number: ");
            scanf("%d", &acntNum1);
            temp = head;
            while (temp->accountNumber != acntNum1)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter deposit amount: Tk ");
            scanf("%f", &depositamnt);
            temp->balance = temp->balance + depositamnt;
            totalMoney = totalMoney + depositamnt;
            printf("\nAmount Tk %.2f has been successfully deposited\n", depositamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);
            flag = 1;
        }
        else if (option == 2)
        {
            char name3[MAX_NAME_LENGTH];
            printf("\nEnter Name: ");
            scanf(" %[^\n]", name3);

            temp = head;
            while (strcmp(temp->name, name3) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter deposit amount: Tk ");
            scanf("%f", &depositamnt);
            temp->balance = temp->balance + depositamnt;
            totalMoney = totalMoney + depositamnt;
            printf("\nAmount Tk %.2f has been successfully deposited\n", depositamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else if (option == 3)
        {
            char surname3[MAX_NAME_LENGTH];
            printf("\nEnter Name: ");
            scanf(" %[^\n]", surname3);

            temp = head;
            while (strcmp(temp->surname, surname3) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter deposit amount: Tk ");
            scanf("%f", &depositamnt);
            temp->balance = temp->balance + depositamnt;
            totalMoney = totalMoney + depositamnt;
            printf("\nAmount Tk %.2f has been successfully deposited\n", depositamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else if (option == 4)
        {
            char address3[MAX_ADDRESS_LENGTH];
            printf("\nEnter Address: ");
            scanf(" %[^\n]", address3);

            temp = head;
            while (strcmp(temp->address, address3) != 0)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter deposit amount: ");
            scanf("%f", &depositamnt);
            temp->balance = temp->balance + depositamnt;
            totalMoney = totalMoney + depositamnt;
            printf("\nAmount Tk %.2f has been successfully deposited\n", depositamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else if (option == 5)
        {
            long long int NID2;
            char nidString[MAX_NID_LENGTH + 1]; 
            int nidLength;

            printf("\nEnter NID (11 digits): ");

            do {
                scanf("%s", nidString);
                nidLength = strlen(nidString);

                if (nidLength != 11) {
                    printf("Please enter 11 digits for the NID: ");
                }
            } while (nidLength != 11);
            NID2 = atoll(nidString);

            temp = head;
            while (temp->NID != NID2)
            {
                temp = temp->next;
            }

            printf("\n--Account Found!--\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Accccount Type: %s\n", temp->accountType);
            printf("Customer Balance: Tk %.2f\n", temp->balance);
            printf("Customer Name: %s %s\n", temp->name, temp->surname);
            printf("Customer NID: %lld\n", temp->NID);
            printf("Customer Address: %s\n", temp->address);

            printf("\nEnter deposit amount: ");
            scanf("%f", &depositamnt);
            temp->balance = temp->balance + depositamnt;
            totalMoney = totalMoney + depositamnt;
            printf("\nAmount Tk %.2f has been successfully deposited\n", depositamnt);
            printf("\nNew balance: Tk %.2f\n", temp->balance);

            flag = 1;
        }
        else
        {
            printf("\n**Enter Correct Option Number**\n");
        }
        if (flag == 0)
        {
            printf("\nAccount Not Found\n");
        }
    }
}

void deleteAccount()
{
    printf("\n---Account Deletion---\n");
    listAccount();
    if (head == NULL)
    {
        return;
    }
    else
    {
        int indexNum;
        printf("\nEnter the index of Account to Delete it: ");
        scanf("%d", &indexNum);

        if (indexNum == 1)
        {
            struct node *temp;
            temp = head;
            head = head->next;
            free(temp);
            totalAcntsNum--;
            printf("\n**Account Successfully Deleted**\n");
        }
        else if (indexNum > 1 && indexNum < totalAcntsNum)
        {
            struct node *temp, *previous, *after;
            temp = head;
            for (int i = 2; i <= indexNum; i++)
            {
                previous = temp;
                temp = temp->next;
            }
            after = temp->next;
            previous->next = after;
            free(temp);
            totalAcntsNum--;
            printf("\n**Account Successfully Deleted**\n");
        }
        else if (indexNum == totalAcntsNum)
        {
            struct node *temp, *previous;
            temp = head;
            while (temp->next != NULL)
            {
                previous = temp;
                temp = temp->next;
            }
            previous->next = NULL;
            free(temp);
            totalAcntsNum--;
            printf("\n**Account Successfully Deleted**\n");
        }
        else
        {
            printf("\n**Enter the Corrrect Index**\n");
        }
    }
}

void displayBankStatus()
{
    printf("\n---Bank Status---\n");
    printf("\nTotal Number of Registered Accounts: %d\n", totalAcntsNum);
    printf("\nTotal Sum of Money Present: Tk %.2f\n", totalMoney);
}

void saveDataToFile()
{
    FILE *file = fopen("bank_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening the file for writing.\n");
        return;
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            fprintf(file, "%d %s %s %lld %s %.2f %s\n", temp->accountNumber, temp->name, temp->surname, temp->NID, temp->address, temp->balance, temp->accountType);
            temp = temp->next;
        }
        fclose(file);
    }
}

void freeNodes()
{
    while (head != NULL)
        {
            struct node *temp = head;
            head = head->next;
            free(temp);
        }
}

void loadDataFromFile()
{
    FILE *file = fopen("bank_data.txt", "r");
    if (file == NULL)
    {
        printf("No data file found.\n");
        return;
    }
    else
    {
        freeNodes();

        struct node *newnode;

        while (1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (fscanf(file, "%d %s %s %lld %s %f %s\n", &newnode->accountNumber, newnode->name, newnode->surname, &newnode->NID, newnode->address, &newnode->balance, newnode->accountType) != 7)
            {
                free(newnode);
                break;  // Exit the loop if reading fails
            }

            newnode->next = NULL;

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                struct node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            totalAcntsNum++;
            totalMoney += newnode->balance;
        }

        fclose(file);
    }
}

