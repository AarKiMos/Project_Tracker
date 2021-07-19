/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: PROJECT TRACKING, TASK MANAGEMENT AND JOB SCHEDULING SYSTEM
 * Author: Aachman Mittal 9919103218
 *         Ishan 9919103216
 *         Shashank Agrawal 9919103232 
******************************************************************************/

#include "employee.h"

void emp::set_name(string str){
  this->name=str;
}

void emp::set_ID(int user_id){
  this->ID=user_id;
}

void emp::set_access_level(string str)
{
    this->access_level= str;
}

int emp::get_ID(){
  return ID;
}

string emp::get_name(){
  return name;
}

string emp::get_access_level()
{
    return access_level;
}