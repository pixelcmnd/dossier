#include <stdio.h>

#include "db.h"
#include "person.h"

int main(void) {
  person test = {.name = "john",
                 .surname = "doe",
                 .email = "test@example.com",
                 .phone = "+11231231212"};

  sqlite3 *db;
  sqlite3_open("dossier.db", &db);

  // verify if table "people" exist within db
  if (!db_verify_table(db, "people")) {
    db_create_people(db);
  }

  if (!db_insert_person(db, &test)) {
    fprintf(stderr, "insert failed: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_close(db);
}
