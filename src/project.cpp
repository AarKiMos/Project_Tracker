/******************************************************************************
 * JIIT Noida 
 * Data Structures group Mini Project
 * Project: 
 * Author: Shashank Agrawal 9919103232
******************************************************************************/

#include "project.h"

void project::set_name(string str){
  this->name=str;
}

void project::set_ID(int user_id){
  this->ID=user_id;
}

void project::set_deadline(struct tm x){
  this->deadline=x;
}

int project::get_ID(){
  return ID;
}

string project::get_name(){
  return name;
}

tm project::get_deadline(){
  return deadline;
}

