#ifndef PHONE_DATA_BASE
#define PHONE_DATA_BASE 

typedef struct {
    char* phoneNumber;
    char* name;
} Contact;

void addContact(File* file, char* phoneNumber, char* name);
void removeContact(File* file, char* phoneNumber);
void editContact(File* file, char* phoneNumber, char* newPhoneNumber, char* newName);
char* getName(File* file, char* phoneNumber);
void printContacts();



#endif
