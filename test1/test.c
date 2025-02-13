#include "sqlite3.h"
#include <stdio.h>
void insertTest(sqlite3* db, int rc, char* err_msg) {
    const char *sql_insert = "INSERT INTO USER (NAME, EMAIL) VALUES ('Alice', 'alice@example.com');";
    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Record inserted successfully\n");
    }

    sql_insert = "INSERT INTO USER (NAME, EMAIL) VALUES ('Bob', 'bob@example.com');";
    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Record inserted successfully\n");
        printf("Test passed successfully\n");
    }
}

void deleteTest(sqlite3 *db, int rc, char *err_msg){
    const char *sql_delete = "DELETE FROM USER WHERE NAME like '%Alice';";
    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Record deleted successfully\n");
    }

    sql_delete = "DELETE FROM USER WHERE NAME like '%Bob';";
    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Record deleted successfully\n");
        printf("Test passed successfully\n");
    }
}


