#include <stddef.h>
#include <stdio.h>

#include "db.h"

bool db_insert_person(sqlite3 *db, const person *p) {
  sqlite3_stmt *stmt = NULL;

  int rc =
      sqlite3_prepare_v2(db,
                         "INSERT INTO people (name, surname, email, phone) "
                         "VALUES (?1, ?2, ?3, ?4);",
                         -1, &stmt, NULL);
  if (rc != SQLITE_OK)
    return false;

  // bind every value
  const char *fields[] = {p->name, p->surname, p->email, p->phone};

  for (int i = 0; i < 4; ++i) {
    sqlite3_bind_text(stmt, i + 1, fields[i], -1, SQLITE_TRANSIENT);
  }

  bool state = (sqlite3_step(stmt) == SQLITE_DONE);
  sqlite3_finalize(stmt);
  return state;
}

bool db_verify_table(sqlite3 *db, const char *table_name) {
  sqlite3_stmt *stmt = NULL;

  int rc = sqlite3_prepare_v2(
      db, "SELECT 1 FROM sqlite_master WHERE type='table' AND name=?1;", -1,
      &stmt, NULL);
  if (rc != SQLITE_OK)
    return false;

  sqlite3_bind_text(stmt, 1, table_name, -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    sqlite3_finalize(stmt);
    return true;
  } else {
    sqlite3_finalize(stmt);
    return false;
  }
}

bool db_create_people(sqlite3 *db) {
  char *errmsg = NULL;

  int rc = sqlite3_exec(db,
                        "CREATE TABLE IF NOT EXISTS people ("
                        "contact_id INTEGER PRIMARY KEY, "
                        "name TEXT NOT NULL, "
                        "surname TEXT NOT NULL, "
                        "email TEXT NOT NULL, "
                        "phone TEXT NOT NULL)",
                        NULL, NULL, &errmsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQLite error: %s\n", errmsg);
    sqlite3_free(errmsg);
    return false;
  }

  return true;
}
