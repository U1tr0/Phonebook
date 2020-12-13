#include <stdio.h>

#ifndef PHONEBOOK
#define PHONEBOOK 

#define NameBufferSize 30
#define NumberBufferSize 20

typedef struct {
    char name[NameBufferSize];
    char number[NumberBufferSize];
} Contact;

typedef enum {
    WithoutSorting,
    WithSorting,
} SortParam; 

void addContact(const char* fileName, const Contact* contact, const SortParam param);
void removeContact(const char* fileName, const char* phoneNumber);
void editContact(const char* fileName,
                 const char* phoneNumber,
                 const Contact* newContact);
void printContacts(const char* fileName);
void clearPhonebook(const char* fileName);
int countContacts(const char* fileName);
Contact* getContacts(const char* fileName);
void sortContacts(const char* fileName);
void checkFileExists(const char* fileName);
void trimString(const size_t size, char* str);

#endif
