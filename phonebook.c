#include "phonebook.h"
#include <stdlib.h>
#include <stdio.h>

void addContact(const char* fileName, Contact* contact) {
    FILE* file = fopen(fileName, "ab");
    fwrite(contact, sizeof(Contact), 1, file);
    fclose(file);
}

void removeContact(const char* fileName, const char* phoneNumber) {

}

void editContact(const char* fileName, const char* phoneNumber, const char* newPhoneNumber, const char* newName) {

}

void printContacts(const char* fileName) {

}

void sortContacts(const char* fileName) {

}

void clearPhonebook(const char* fileName) {
    FILE* file = fopen(fileName, "wb");
    fclose(file);
}

int rowCount(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("%s does not exist!\n", fileName);
        exit(1);
    }
    int count = 0;
    Contact temp;
    fread(&temp, sizeof(Contact), 1, file);
    while (!feof(file)) {
        fread(&temp, sizeof(Contact), 1, file);
        ++count;
    }
    fclose(file);
    return count;
}

Contact* getContactsArray(const char* fileName) {
    int rows = rowCount(fileName);
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("%s does not exist!\n", fileName);
        exit(1);
    }
    Contact* contactsArray = (Contact*) malloc(sizeof(Contact) * rows);
    printf("%d\n", rows);
    for (int i = 0; i < rows; ++i) {
        fread(contactsArray + i, sizeof(Contact), 1, file);
        printf("%s %s\n", contactsArray[i].name, contactsArray[i].number);
    }
    fclose(file);
    return contactsArray;
}

