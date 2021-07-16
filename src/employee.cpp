/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Shashank Agrawal 9919103232
******************************************************************************/

#include "employee.h"

void emp::set_name(string str){
  this->name=str;
}

void emp::set_ID(int user_id){
  this->ID=user_id;
}

void emp::set_DID(int dept_id){
  this->ID=dept_id;
}

void emp::set_dept_name(string str){
  this->dept_name=str;
}



int emp::get_ID(){
  return ID;
}

string emp::get_name(){
  return name;
}

int emp:: get_DID(){
    return DID;
}

string emp::get_dept_name(){
    return dept_name;
}