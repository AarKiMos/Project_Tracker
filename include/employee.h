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
    
public:
    // TODO: Param and copy constructor
     
    void set_name(string);
    void set_ID(int);

    int get_ID();
    string get_name();
};




#endif