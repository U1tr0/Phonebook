#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"

int main() {
    char fileName[30];
    printf("Enter a file name: ");
    scanf("%s", fileName);
    char ch;
    ch = fgetc(stdin);
    char operation;
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
        int rows = countContacts(fileName);
        Contact* contacts = getContacts(fileName);
            for (int i = 0; i < rows; ++i) {
                printf("%s %s\n", contacts[i].name, contacts[i].number);
            }
            free(contacts);
        //    printContacts(fileName);
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
        }
        else if (operation == 'e') {
            Contact contact;
            char oldNumber[NumberBufferSize];
            printf("Enter number: ");
            scanf("%s", oldNumber);
            ch = fgetc(stdin);
            printf("Enter new number ");
            scanf("%s", contact.number);
            ch = fgetc(stdin);
            printf("Enter new name ");
            scanf("%s", contact.name);
            ch = fgetc(stdin);
            //editContact(fileName, oldNumber, contact);
        }
        else if (operation == 'r') {
            char phoneNumber[NumberBufferSize];
            printf("Enter a phone number: ");
            scanf("%s", phoneNumber);
            ch = fgetc(stdin);
            removeContact(fileName, phoneNumber);
        }
        else if (operation == 'c') {
            char confirmation;
            printf("Cleare all contacts? (y/n): ");
            scanf("%c", &confirmation);
            ch = fgetc(stdin);
            if (confirmation == 'y') {
                clearPhonebook(fileName);
            }
        }
        else {
            break;
        }
    }

    return 0;
}
