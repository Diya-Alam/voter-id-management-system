#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Voter
{
    char name[10];
    char address[10];
    char phoneNumber[12];
    int id;
    int age; // New field for voter's age
};

// Function to validate if the input is a valid numeric string
int isNumeric(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0; // Not a digit
        }
        str++;
    }
    return 1; // All characters are digits
}

void registerVoter(struct Voter *voter)
{
    printf("\nEnter your name: ");
    scanf("%s", voter->name);

    printf("Enter your permanent address: ");
    scanf("%s", voter->address);

    // Validate and prompt for a valid 11-digit phone number
    do
    {
        printf("Enter your phone number (11 digits): ");
        scanf("%s", voter->phoneNumber);

        if (strlen(voter->phoneNumber) != 11 || !isNumeric(voter->phoneNumber))
        {
            printf("Phone number must be 11 digits with no characters or symbols. Please try again.\n");
        }
    }
    while (strlen(voter->phoneNumber) != 11 || !isNumeric(voter->phoneNumber));

    // Ask for the voter's age
    printf("Enter your age: ");
    scanf("%d", &voter->age);

    // Check if the voter is below 18 years old
    if (voter->age < 18)
    {
        printf("Sorry, you must be 18 or older to register.\n");
        return; // Redirect to the previous menu
    }

    // Generating a random garbage value for ID
    voter->id = rand();

    printf("\nRegistration complete!\n");
    printf("\nID: %d\nName: %s\nAddress: %s\nPhone Number: %s\nAge: %d\n", voter->id, voter->name, voter->address, voter->phoneNumber, voter->age);
}

void addVoterInformation(struct Voter *voters, int *numVoters)
{
    if (*numVoters < 10)
    {
        struct Voter newVoter;
        registerVoter(&newVoter);

        // Check if the voter is below 18 years old before adding to the array
        if (newVoter.age >= 18)
        {
            voters[*numVoters] = newVoter;
            (*numVoters)++;
        }
        else
        {
            printf("Voter must be 18 or older to be added.\n");
        }
    }
    else
    {
        printf("Maximum number of voters reached.\n");
    }
}

void adminLogin()
{
    char username[20];
    char password[20];

    printf("\nEnter administrator username: ");
    scanf("%s", username);

    printf("Enter administrator password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1236") == 0)
    {
        printf("\nAdministrator login successful!\n");
    }
    else
    {
        printf("\nAdministrator login failed. Exiting program.\n");
        exit(0);
    }
}

void showAllVoters(struct Voter *voters, int numVoters)
{
    if (numVoters == 0)
    {
        printf("No voters registered yet.\n");
    }
    else
    {
        printf("\nList of Registered Voters:\n");
        for (int i = 0; i < numVoters; ++i)
        {
            printf("ID: %d, Name: %s, Address: %s, Phone Number: %s, Age: %d\n", voters[i].id, voters[i].name, voters[i].address, voters[i].phoneNumber, voters[i].age);
        }
    }
}

void searchVoterByName(struct Voter *voters, int numVoters, char *searchName)
{
    int found = 0;
    for (int i = 0; i < numVoters; ++i)
    {
        if (strcmp(voters[i].name, searchName) == 0)
        {
            printf("Voter found:\n");
            printf("ID: %d, Name: %s, Address: %s, Phone Number: %s, Age: %d\n", voters[i].id, voters[i].name, voters[i].address, voters[i].phoneNumber, voters[i].age);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No information.\n");
    }
}

void deleteVoter(struct Voter *voters, int *numVoters, int idToDelete)
{
    for (int i = 0; i < *numVoters; ++i)
    {
        if (voters[i].id == idToDelete)
        {
            for (int j = i; j < *numVoters - 1; ++j)
            {
                voters[j] = voters[j + 1];
            }
            (*numVoters)--;
            printf("Voter information with ID %d deleted.\n", idToDelete);
            return;
        }
    }
    printf("Voter with ID %d not found.\n", idToDelete);
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

// Clear the input buffer
        while ((getchar()) != '\n');

        switch (choice)
        {
        case 1:
            // New voter feature
            if (numVoters < 10)
            {
                addVoterInformation(voters, &numVoters);
            }
            else
            {
                printf("Maximum number of voters reached.\n");
            }
            break;

        case 2:
            adminLogin();
            // Administrator features
            while (1)
            {
                printf("\nAdministrator Menu:\n");
                printf("1. Show voter information as a list\n");
                printf("2. Search voters by name\n");
                printf("3. Add voter information\n");
                printf("4. Delete voter information\n");
                printf("5. Exit\n");

                int adminChoice;
                printf("\nYour choice: ");
                scanf("%d", &adminChoice);

                switch (adminChoice)
                {
                case 1:
                    showAllVoters(voters, numVoters);
                    break;

                case 2:
                {
                    char searchName[20];
                    printf("\nEnter voter name to search: ");
                    scanf("%s", searchName);
                    searchVoterByName(voters, numVoters, searchName);
                    break;
                }

                case 3:
                    addVoterInformation(voters, &numVoters);
                    break;

                case 4:
                {
                    int idToDelete;
                    printf("\nEnter ID of voter to delete: ");
                    scanf("%d", &idToDelete);
                    deleteVoter(voters, &numVoters, idToDelete);
                    break;
                }

                case 5:
                    exit(0);

                default:
                    printf("Invalid choice. Please try again.\n");
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
