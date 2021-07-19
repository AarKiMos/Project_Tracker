/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
******************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ctime>

using namespace std;

class emp {
private:

    int ID;
    string name;
    string access_level;
    
public:

    emp *prev;
    emp *next;
    
    // TODO: Param and copy constructor
     
    void set_name(string);
    void set_ID(int);
    void set_access_level(string);

    int get_ID();
    string get_name();
    string get_access_level();
};




#endif