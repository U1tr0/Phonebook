#include "phonebook.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addContact(const char* fileName, Contact* contact, SortParam param) {
    FILE* file = fopen(fileName, "ab");
    //trimString(NameBufferSize, contact->name);
    // Write line in file. Format: "namenumber\n"
    fwrite(contact, sizeof(Contact), 1, file);
    fputc('\n', file);
    if (param == WithSorting) {
        //sortContacts(fileName);
    }
    fclose(file);
}

// Removes contact from file by phone number
void removeContact(const char* fileName, const char* phoneNumber) {
    FILE* file = fopen(fileName, "rb");
    // If file does not exist, then terminate program
    checkFileExists(file, fileName);
    Contact* contacts = getContacts(fileName);
    fclose(file);

    int rows = countContacts(fileName);
    clearPhonebook(fileName);
    for (int i = 0; i < rows; ++i) {
        if (strcmp(contacts[i].number, phoneNumber) != 0) {
            addContact(fileName, contacts + i, WithoutSorting);
        }
    }
}

// Edits contact in file by old phone number
void editContact(const char* fileName,
                 const char* phoneNumber,
                 Contact* newContact)
{
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName);
    /*
     * get contacts array: getContacts(fileName);
     * search contact in array
     * change contact name and phone
     * write contacts in file: addContact(...);
    */
    fclose(file);
    //trimString(NameBufferSize, newContact->name);
    // here you should write contacts in file 
}

// Prints sorted array of contacts
void printContacts(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName);
    /* 
     * get array of contacts
     * print array
    */
    fclose(file);
}

// Clears all file 
void clearPhonebook(const char* fileName) {
    // Opening a file in write mode clears all content
    FILE* file = fopen(fileName, "wb");
    fclose(file);
}

// Return count of rows in file
int countContacts(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName); // if file doesn't exist then exit(1);
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
    int rows = countContacts(fileName);
    FILE* file = fopen(fileName, "rb");
    checkFileExists(file, fileName); // if file doesn't exist then exit(1);
    Contact* contactsArray = (Contact*) malloc(sizeof(Contact) * rows);
    for (int i = 0; i < rows; ++i) {
        // Reads line. Format: "namenumber\n"
        fread(contactsArray + i, sizeof(Contact), 1, file);
        fgetc(file); // reads '\n'
    }
    fclose(file);
    return contactsArray;
}

void sortContacts(const char* fileName) {
    /*
     * get array contacts: getContacts(fileName);
     * sort array
     * write each contact from array in file: addContact(...);
    */
}

// Checks file. If file does not exists, then terminate program
void checkFileExists(const FILE* file, const char* fileName) {
    if (!file) {
        printf("%s does not exist!\n", fileName);
        exit(1);
    }
}

// Delets '\n' character in string
void trimString(const size_t size, char* str) {
    for (size_t i = 0; i < size; ++i) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }
}
