/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Aachman Mittal 9919103218
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
    int DID;
    string dept_name;
    
public:
    // TODO: Param and copy constructor
     
    void set_name(string);
    void set_ID(int);
    void set_DID(int);
    void set_dept_name(string);

    int get_ID();
    string get_name();
    int get_DID();
    string get_dept_name();
};




#endif