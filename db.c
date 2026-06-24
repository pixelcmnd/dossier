#include <stddef.h>

#include "db.h"

bool db_insert_person(sqlite3 *db, const person *p) {
  // TODO: Add function to insert people
  return true;
}

bool db_verify_table(sqlite3 *db) {
  sqlite3_stmt *stmt = NULL;

  sqlite3_prepare_v2(
      db, "SELECT 1 FROM sqlite_master WHERE type='table' AND name=?1;", -1,
      &stmt, NULL);

  sqlite3_bind_text(stmt, 1, "people", -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    sqlite3_finalize(stmt);
    return true;
  } else {
    sqlite3_finalize(stmt);
    return false;
  }
}
