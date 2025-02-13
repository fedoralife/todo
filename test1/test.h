#ifndef TEST_H
#define TEST_H

#include "sqlite3.h"

void insertTest(sqlite3* db, int rc,char* err_msg);
void deleteTest(sqlite3* db, int rc,char* err_msg);
#endif
