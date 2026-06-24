#include <stdio.h>

#include "db.h"
#include "person.h"

int main(void) {
  person test = {.name = "john"};

  sqlite3 *db;
  sqlite3_open("test.db", &db);

  db_insert_person(db, &test);

  sqlite3_close(db);
}
