// declares db functions

#ifndef DB_H
#define DB_H

#include "person.h"
#include <sqlite3.h>
int db_insert_person(sqlite3 *db, const person *p);
#endif // !DB_H
