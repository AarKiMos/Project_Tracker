/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
******************************************************************************/

#ifndef DB_UTIL_H
#define DB_UTIL_H

#include <iostream>
#include <mysql/mysql.h>

#define DB MYSQL
#define DB_RES MYSQL_RES
#define DB_ROW MYSQL_ROW

struct connection_details
{
    const char *server,
        *user,
        *password,
        *database;
};

MYSQL* db_connection_setup(struct connection_details);

MYSQL_RES* db_perform_query(MYSQL*, const char*);

void db_free_result(MYSQL_RES*);

void db_close(MYSQL*);




#endif