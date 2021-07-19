/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
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
    int is_complete; // 0 if project has been completed else 1
    int dtd; // Days to Deadline (not in DB)
    int task_count;
    task *list;

    project *prev; //To create data structures
    project *next;

    //TODO: param and copy constructor

    void set_name(string);
    void set_ID(int);
    void set_deadline(struct tm); //read ctime tm structure for more info

    string get_name();
    int get_ID();
    struct tm get_deadline();
    
};

#endif