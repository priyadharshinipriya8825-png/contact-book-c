#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0, choice, i;
    char search[50];

    while (1) {
        printf("\n===== Contact Book =====\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_CONTACTS) {
                    printf("Enter Name: ");
                    scanf(" %[^\n]", contacts[count].name);
                    printf("Enter Phone: ");
                    scanf(" %[^\n]", contacts[count].phone);
                    printf("Enter Email: ");
                    scanf(" %[^\n]", contacts[count].email);
                    count++;
                    printf("Contact Added Successfully!\n");
                } else {
                    printf("Contact Book is Full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No contacts available.\n");
                } else {
                    printf("\n--- Contact List ---\n");
                    for (i = 0; i < count; i++) {
                        printf("%d. %s | %s | %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
                    }
                }
                break;

            case 3:
                printf("Enter Name to Search: ");
                scanf(" %[^\n]", search);
                for (i = 0; i < count; i++) {
                    if (strcmp(contacts[i].name, search) == 0) {
                        printf("Found: %s | %s | %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
                        break;
                    }
                }
                if (i == count) printf("Contact not found!\n");
                break;

            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
