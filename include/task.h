/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Aachman Mittal 9919103218
******************************************************************************/

#ifndef TASK_H
#define TASK_H

#include <ctime>
#include <string>

using namespace std;

class task {
private:

    int ID;
    int PID;
    string name;
    string dept;
    bool is_complete;
    
    task* prev;
    task* next;

public:

    //TODO: Param and copy constructor

    void set_name(string);
    void set_ID(int);
    void set_deadline(struct tm);

    string get_name();
    int get_ID();
    struct tm get_deadline();

};





#endif