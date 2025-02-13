#include "db.h"
#include <stdio.h>
void databaseInit(sqlite3 *db, int rc, char *err_msg) {
  if (rc) {
    fprintf(stderr, "Cant find database: %s\n", sqlite3_errmsg(db));
    return;
  } else {
    printf("Opend database successfully\n");
  }
  const char *sql = "CREATE TABLE IF NOT EXISTS USER("
                    "UID INT NOT NULL,"
                    "NAME TEXT NOT NULL,"
                    "EMAIL TEXT NOT NULL"
                    ");";
  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
  } else {
    fprintf(stderr, "Table created successfully\n");
  }
}
