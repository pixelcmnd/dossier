#include <stdio.h>

#include "db.h"
#include "person.h"

int main(void) {
  person test = {
      .name = "john", .surname = "doe", .phonenumber = "11231231212"};

  sqlite3 *db;
  sqlite3_open("dossier.db", &db);

  if (db_verify_table(db)) {
    printf("exist");
  } else {
    // TODO: Create people table in db
    printf("dosen't exist");
  }

  db_insert_person(db, &test);

  sqlite3_close(db);
}
