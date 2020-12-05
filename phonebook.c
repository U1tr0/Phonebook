#include "phonebook.h"
#include <stdlib.h>
#include <stdio.h>

void addContact(const char* fileName, Contact* contact) {
    FILE* file = fopen(fileName, "ab");
    fwrite(contact, sizeof(Contact), 1, file);
    fputc('\n', file);
    fclose(file);
}

void removeContact(const char* fileName, const char* phoneNumber) {

}

void editContact(const char* fileName, const char* phoneNumber, const char* newPhoneNumber, const char* newName) {

}

void printContacts(const char* fileName) {

}


void clearPhonebook(const char* fileName) {
    FILE* file = fopen(fileName, "wb");
    fclose(file);
}

int rowCount(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName); // if file doesn't exist then exit(1);
    int count = 0;
    Contact temp;
    fread(&temp, sizeof(Contact), 1, file);
    fgetc(file);
    while (!feof(file)) {
        fread(&temp, sizeof(Contact), 1, file);
        fgetc(file);
        ++count;
    }
    fclose(file);
    return count;
}

Contact* getContactsArray(const char* fileName) {
    int rows = rowCount(fileName);
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName); // if file doesn't exist then exit(1);
    Contact* contactsArray = (Contact*) malloc(sizeof(Contact) * rows);
    for (int i = 0; i < rows; ++i) {
        fread(contactsArray + i, sizeof(Contact), 1, file);
        fgetc(file);
    }
    fclose(file);
    return contactsArray;
}

void sortContacts(const char* fileName) {

}

void checkFileExists(const FILE* file, const char* fileName) {
    if (!file) {
        printf("%s does not exist!\n", fileName);
        exit(1);
    }
}
