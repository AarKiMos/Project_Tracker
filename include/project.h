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

class project {
private:

    static int auto_id;
    int ID;
    string name;
    struct tm deadline;

    int task_count;
    task task_list[10];

public:

    project();

    void set_name(string);
    void set_ID(int);
    void set_deadline(struct tm); //read ctime tm structure for more info 

    string get_name();
    int get_ID();
    struct tm get_deadline();
};




#endif