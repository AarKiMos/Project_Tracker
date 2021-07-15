/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Shashank Agrawal 9919103232
******************************************************************************/

#include "department.h"

void dept::set_name(string str){
  this->name=str;
}

void dept::set_ID(int user_id){
  this->ID=user_id;
}

int dept::get_ID(){
  return ID;
}

string dept::get_name(){
  return name;
}
