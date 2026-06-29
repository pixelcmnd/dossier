// declares db functions

#ifndef DB_H
#define DB_H

#include "person.h"
#include <sqlite3.h>
bool db_insert_person(sqlite3 *db, const person *p);
bool db_verify_table(sqlite3 *qb, const char *table_name);
bool db_create_people(sqlite3 *db);
#endif // !DB_H
