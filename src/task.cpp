/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
******************************************************************************/

#include "task.h"

void task::set_name(string t_name) {
    this->name = t_name;
}

void task::set_ID(int t_id) {
    this->ID = t_id;
}

void task::set_PID(int p_id) {
    this->ID = p_id;
}

void task::set_deadline(struct tm t_dd) {
    this->deadline = t_dd;
}

string task::get_name() {
    return name;
}

int task::get_ID() {
    return ID;
}

int task::get_PID() {
    return PID;
}

struct tm task::get_deadline() {
    return deadline;
}