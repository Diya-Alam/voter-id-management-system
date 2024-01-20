#include<stdio.h>
//#include <stdlib.h>
//#include <string.h>

struct Voter {
    char name[50];
    char address[100];
    char phoneNumber[15];
};

void registerVoter(struct Voter *voter) {
    printf("Enter your name: ");
    scanf("%s", voter->name);

    printf("Enter your permanent address: ");
    scanf("%s", voter->address);

    printf("Enter your phone number: ");
    scanf("%s", voter->phoneNumber);

    printf("Registration complete!.\n");
    printf("Name: %s\nAddress: %s\nPhone Number: %s\n", voter->name, voter->address, voter->phoneNumber);
}

int main() {
    struct Voter voters[100];
    int numVoters = 0;

    printf("Voter Management System");

    while (1) {
        printf("\nMenu:\n\n");
        printf("1. Register as a voter\n");
        printf("2. Login or register as an administrator\n");
        printf("3. Exit\n");

        int choice;
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numVoters < 100) {
                    struct Voter newVoter;
                    registerVoter(&newVoter);
                    voters[numVoters] = newVoter;
                    numVoters++;
                } else {
                    printf("Maximum number of voters reached.\n");
                }
                break;

            case 2: {
                // Administrator login and features 
                break;
            }

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

