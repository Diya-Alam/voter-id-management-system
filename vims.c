#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Voter
{
    char name[10];
    char address[10];
    char phoneNumber[12];
    int id;
};

void registerVoter(struct Voter *voter)
{
    printf("\nEnter your name: ");
    scanf("%s", voter->name);

    printf("Enter your permanent address: ");
    scanf("%s", voter->address);

    printf("Enter your phone number: ");
    scanf("%s", voter->phoneNumber);

    // Generating a random garbage value for ID
    voter->id = rand();

    printf("\nRegistration complete!\n");
    printf("\nID: %d\nName: %s\nAddress: %s\nPhone Number: %s\n", voter->id, voter->name, voter->address, voter->phoneNumber);

    exit(0);
}

void adminLogin()
{
    char username[20];
    char password[20];

    printf("\nEnter administrator username: ");
    scanf("%s", username);

    printf("Enter administrator password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "87654321") == 0)
    {
        printf("\nAdministrator login successful.\n");
        exit(0); //temporary
    }
    else
    {
        printf("\nAdministrator login failed. Exiting program.\n");
        exit(0);
    }
}

int main()
{
    struct Voter voters[10];
    int numVoters = 0;

    printf("Voter Management System\n");

    while (1)
    {
        printf("\nMenu:\n\n");
        printf("1. Register as a voter\n");
        printf("2. Login or register as an administrator\n");
        printf("3. Exit\n");

        int choice;
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (numVoters < 10)
            {
                struct Voter newVoter;
                registerVoter(&newVoter);
                voters[numVoters] = newVoter;
                numVoters++;
            }
            else
            {
                printf("Maximum number of voters reached.\n");
            }
            break;

        case 2:
            adminLogin();

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
