#ifndef PHONEBOOK
#define PHONEBOOK 

#define NameBufferSize 30
#define NumberBufferSize 20

typedef struct {
    char name[NameBufferSize];
    char number[NumberBufferSize];
} Contact;

void addContact(const char* fileName, Contact* contact);
void removeContact(const char* fileName, const char* phoneNumber);
void editContact(const char* fileName, const char* phoneNumber, const char* newPhoneNumber, const char* newName);
void printContacts(const char* fileName);
void clearPhonebook(const char* fileName);
int rowCount(const char* fileName);
Contact* getContactsArray(const char* fileName);
void sortContacts(const char* fileName);

#endif
