#define DB "../../database/database.db"
#include "db.h"
#include "gui.h"
#include "sqlite3.h"
#include "test.h"
#include <stdio.h>
void init(void) {
  sqlite3 *db;
  int opt = 0;
  int rc = sqlite3_open(DB, &db);
  char *err_msg = 0;
  databaseInit(db, rc, err_msg);
  printf("Enter option\n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  scanf("%d", &opt);
  if (opt == 1) {
    insertTest(db, rc, err_msg);
  } else if (opt == 2) {
    deleteTest(db, rc, err_msg);
  } else {
    printf("No input specified\n");
  }
  sqlite3_close(db);
}
void test(void) {}
int main(void) { return 0; }
