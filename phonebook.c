#include "phonebook.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addContact(const char* fileName, Contact* contact) {
    FILE* file = fopen(fileName, "ab");
    //trimString(NameBufferSize, contact->name);
    fwrite(contact, sizeof(Contact), 1, file);
    fputc('\n', file);
    fclose(file);
}

void removeContact(const char* fileName, const char* phoneNumber) {
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName);
    Contact* contacts = getContactsArray(fileName);
    fclose(file);
    int rows = rowCount(fileName);
    file = fopen(fileName, "wb");
    for (int i = 0; i < rows; ++i) {
        if (strcmp(contacts[i].number, phoneNumber) != 0) {
            fwrite(contacts + i, sizeof(Contact), 1, file);
            fputc('\n', file);
        }
    }
    fclose(file);
}

void editContact(const char* fileName, const char* phoneNumber, Contact* newContact) {
    FILE* file = fopen(fileName, "rab");
    checkFileExists(file, fileName);
    trimString(NameBufferSize, newContact->name);
    // implementation
    fclose(file);
}

void printContacts(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName);
    // implementation
    fclose(file);
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

void trimString(const size_t size, char* str) {
    for (size_t i = 0; i < size; ++i) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }
}
