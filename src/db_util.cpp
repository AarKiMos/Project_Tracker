/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
******************************************************************************/

#include "db_util.h"

MYSQL* db_connection_setup(struct connection_details db_details)
{
    MYSQL *connection = mysql_init(NULL); // mysql instance
    
    //connect database
    if(!mysql_real_connect(connection, db_details.server, db_details.user, db_details.password, db_details.database, 0, NULL, 0)){
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
        exit(1); 
    }

    return connection;
}

MYSQL_RES* db_perform_query(MYSQL *connection, const char *sql_query)
{
    //send query to db
    if(mysql_query(connection, sql_query)){
        std::cout << "MySQL Query Error: " << mysql_error(connection) << std::endl;
        exit(1);
    }

    return mysql_use_result(connection);
}

void db_free_result(MYSQL_RES* res)
{
    mysql_free_result(res);
}

void db_close(MYSQL* conn)
{
    mysql_close(conn);
}