/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Aachman Mittal 9919103218
******************************************************************************/

#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <ctime>
#include "task.h"

using namespace std;

class project
{
private:
    int ID;
    string name;
    struct tm deadline;

public:
    int task_count;
    task *completed;
    task *pending;

    //TODO: param and copy constructor

    void set_name(string);
    void set_ID(int);
    void set_deadline(struct tm); //read ctime tm structure for more info

    void set_task_count(int);
    void set_task_list(task*);

    string get_name();
    int get_ID();
    struct tm get_deadline();
    
    int get_task_count();
    task* get_task_list();
};

#endif