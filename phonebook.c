#include "phonebook.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addContact(const char* fileName, const Contact* contact, const SortParam param) {
    FILE* file = fopen(fileName, "ab");
    // Write line in file. Format: "namenumber\n"
    fwrite(contact, sizeof(Contact), 1, file);
    fputc('\n', file);
    fclose(file);

    if (param == WithSorting) {
        sortContacts(fileName);
    }
}

// Removes contact from file by phone number
void removeContact(const char* fileName, const char* phoneNumber) {
    // If file does not exist, then terminate program
    checkFileExists(fileName);
    Contact* contacts = getContacts(fileName);
    int rows = countContacts(fileName);

    clearPhonebook(fileName);
    for (int i = 0; i < rows; ++i) {
        if (strcmp(contacts[i].number, phoneNumber) != 0) {
            addContact(fileName, contacts + i, WithoutSorting);
        }
    }

    free(contacts);
}

// Edits contact in file by old phone number
void editContact(const char* fileName,
                 const char* phoneNumber,
                 const Contact* newContact)
{
    checkFileExists(fileName);
    removeContact(fileName, phoneNumber);
    addContact(fileName, newContact, WithSorting);
}

// Prints sorted array of contacts
void printContacts(const char* fileName) {
    checkFileExists(fileName);
    int rows = countContacts(fileName);
    sortContacts(fileName);
    Contact* contacts = getContacts(fileName);

    for (int i = 0; i < rows; ++i) {
        printf("%s %s\n", contacts[i].name, contacts[i].number);
    }
}

// Clears all file 
void clearPhonebook(const char* fileName) {
    // Opening a file in write mode clears all content
    FILE* file = fopen(fileName, "wb");
    fclose(file);
}

// Return count of rows in file
int countContacts(const char* fileName) {
    checkFileExists(fileName); // if file doesn't exist then exit(1);
    FILE* file = fopen(fileName, "rb");
    int count = 0;
    Contact temp;
    
    fread(&temp, sizeof(Contact), 1, file);
    fgetc(file); // reads '\n'
    // reads lines while does not reach end of file
    while (!feof(file)) {
        // Reads line. Format: "namenumber\n"
        fread(&temp, sizeof(Contact), 1, file);
        fgetc(file); // reads '\n'
        ++count;
    }
    
    fclose(file);

    return count;
}

// Returns contacts array from file
Contact* getContacts(const char* fileName) {
    checkFileExists(fileName); // if file doesn't exist then exit(1);
    int rows = countContacts(fileName);
    FILE* file = fopen(fileName, "rb");
    Contact* contactsArray = (Contact*) malloc(sizeof(Contact) * rows);

    for (int i = 0; i < rows; ++i) {
        // Reads line. Format: "namenumber\n"
        fread(contactsArray + i, sizeof(Contact), 1, file);
        fgetc(file); // reads '\n'
    }

    fclose(file);

    return contactsArray;
}

// Sorts lines in file
void sortContacts(const char* fileName) {
    Contact* contacts = getContacts(fileName);
    int rows = countContacts(fileName);
    clearPhonebook(fileName);
    Contact temp;

    for (int j = rows - 1; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            if (strcmp(contacts[i].name, contacts[i + 1].name) > 0) {
                temp = contacts[i];
                contacts[i] = contacts[i + 1];
                contacts[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        addContact(fileName, contacts + i, WithoutSorting);
    }

    free(contacts);
}

// Checks file. If file does not exists, then terminate program
void checkFileExists(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("%s does not exist!\n", fileName);
        exit(1);
    }
    fclose(file);
}

// Delets '\n' character in string
void trimString(const size_t size, char* str) {
    for (size_t i = 0; i < size; ++i) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }
}
