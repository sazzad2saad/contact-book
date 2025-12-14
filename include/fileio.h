#ifndef FILEIO_H
#define FILEIO_H

#include "contacts.h"

void loadContacts(Contact *, int *);
void saveContact(Contact *, int);
void export(Contact *, int);

#endif