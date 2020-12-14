#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"

int main() {
    char fileName[30];
    char operation;
    char ch;

    printf("Enter a file name: ");
    scanf("%s", fileName);
    ch = fgetc(stdin);
    
    while (1) {
        printf("p - print sorted phonebook\n");
        printf("w - write new contact\n");
        printf("e - edit contact\n");
        printf("r - remove contact\n");
        printf("c - clear phonebook\n");
        printf("q - close programm\n");
        printf("Enter operation key: ");
        operation = fgetc(stdin);
        ch = fgetc(stdin);

        if (operation == 'p') {
            printf("==========================\n");
            printContacts(fileName);
            printf("==========================\n");
        }
        else if (operation == 'w') {
            Contact contact;
            printf("Enter name: ");
            scanf("%s", contact.name);
            ch = fgetc(stdin);
            printf("Enter phone number: "); 
            scanf("%s", contact.number);
            ch = fgetc(stdin);

            addContact(fileName, &contact, WithSorting);

            printf("==========================\n");
            printf("Contact {%s, %s} was added.\n",
                    contact.name, contact.number);
            printf("==========================\n");
        }
        else if (operation == 'e') {
            Contact contact;
            char oldNumber[NumberBufferSize];
            
            printf("Enter number: ");
            scanf("%s", oldNumber);
            ch = fgetc(stdin);
            printf("Enter new number: ");
            scanf("%s", contact.number);
            ch = fgetc(stdin);
            printf("Enter new name: ");
            scanf("%s", contact.name);
            ch = fgetc(stdin);

            editContact(fileName, oldNumber, &contact);
            
            printf("==========================\n");
            printf("Contact with number %s was changed to {%s, %s}.\n",
                    oldNumber, contact.name, contact.number);
            printf("==========================\n");
        }
        else if (operation == 'r') {
            char phoneNumber[NumberBufferSize];

            printf("Enter a phone number: ");
            scanf("%s", phoneNumber);
            ch = fgetc(stdin);
            
            removeContact(fileName, phoneNumber);

            printf("==========================\n");
            printf("Contact with number %s was removed.\n", phoneNumber);
            printf("==========================\n");
        }
        else if (operation == 'c') {
            char confirmation;

            printf("Cleare all contacts? (y/n): ");
            scanf("%c", &confirmation);
            ch = fgetc(stdin);

            if (confirmation == 'y') {
                clearPhonebook(fileName);
                printf("==========================\n");
                printf("All contacts were cleaned.\n");
                printf("==========================\n");
            }
        }
        else {
            break;
        }
    }

    return 0;
}
