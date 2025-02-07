#ifndef DB_H
#define DB_H
#include "sqlite3.h"
void databaseInit(sqlite3 *db, int rc, char *err_msg);
#endif
