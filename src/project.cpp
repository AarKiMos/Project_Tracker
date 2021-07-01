#include "project.h"

project::set_name(string str){
  this->name=str;
}

project::set_ID(int user_id){
  this->ID=user_id;
}

project::set_deadline( struct tm x){
  this->deadline=x;
}

project::get_ID(){
  return ID;
}

project::get_name(){
  return name;
}

project::get_deadline(){
  return deadline;
}
