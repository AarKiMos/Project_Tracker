/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Aachman Mittal 9919103218
******************************************************************************/

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <ctime>
#include "employee.h"

using namespace std;

class dept {
public:

    int ID;
    string name;

    emp* manager;
    emp* employees; 

public:
    // TODO: Param and copy constructor

    void set_name(string);
    void set_ID(int);

    int get_ID();
    string get_name();

};


#endif