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
    
    struct tm deadline;
    
public:

    int status; // 0- not ready, 1- ready but unassigned, 2- assigned 3-completed 
    int dtd;
    task* prev;
    task* next;    // To create data structures

    //TODO: Param and copy constructor

    void set_name(string);
    void set_PID(int);
    void set_ID(int);
    void set_deadline(struct tm);

    string get_name();
    int get_ID();
    int get_PID();
    struct tm get_deadline();

};

class task_comparator
{
 public:
   bool operator()(const task& a, const task& b)
   {
        return a.dtd < b.dtd;
   }
};





#endif