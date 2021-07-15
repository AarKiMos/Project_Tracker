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

int emp::get_ID(){
  return ID;
}

string emp::get_name(){
  return name;
}
