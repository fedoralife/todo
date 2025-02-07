#include "sqlite3.h"
#include <stdio.h>
void insertTest(sqlite3* db, int rc, char* err_msg) {
    err_msg = 0;

    const char *sql_insert = "INSERT INTO COMPANY (NAME, EMAIL) VALUES ('Alice', 'alice@example.com');";
    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);  // Free error message if there is one
    } else {
        fprintf(stdout, "Record inserted successfully\n");
    }

    sql_insert = "INSERT INTO COMPANY (NAME, EMAIL) VALUES ('Bob', 'bob@example.com');";
    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);  // Free error message if there is one
    } else {
        fprintf(stdout, "Record inserted successfully\n");
        printf("Test passed successfully\n");
    }
}

