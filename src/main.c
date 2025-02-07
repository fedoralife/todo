#include "db.h"
#include "sqlite3.h"
#include "test.h"

// The necessary Location for the database
#define DB "../../database/database.db"

int main() {
  sqlite3 *db;
  int rc = sqlite3_open(DB, &db);
  char *err_msg = 0;
  databaseInit(db, rc, err_msg);
  insertTest(db, rc, err_msg);
  sqlite3_close(db);
  return 0;
}
