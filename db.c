#include <stddef.h>
#include <stdio.h>

#include "db.h"

bool db_insert_person(sqlite3 *db, const person *p) {
  // TODO: Add function to insert people
  return true;
}

bool db_verify_table(sqlite3 *db, const char *table_name) {
  sqlite3_stmt *stmt = NULL;

  int rc = sqlite3_prepare_v2(
      db, "SELECT 1 FROM sqlite_master WHERE type='table' AND name=?1;", -1,
      &stmt, NULL);
  if (rc != SQLITE_OK) {
    return false;
  }

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

  int rc =
      sqlite3_exec(db,
                   "CREATE TABLE IF NOT EXISTS people (contact_id INTEGER "
                   "PRIMARY KEY, first_name TEXT NOT NULL, last_name TEXT NOT "
                   "NULL, email TEXT NOT NULL, phone TEXT NOT NULL)",
                   NULL, NULL, &errmsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQLite error: %s\n", errmsg);
    sqlite3_free(errmsg);
    return false;
  }

  return true;
}
