#ifndef FILEIO_H
#define FILEIO_H

#include "contacts.h"

void loadContatcts(Contact *, int *);
void saveContact(Contact *, int);
void export(Contact *, int);

#endif