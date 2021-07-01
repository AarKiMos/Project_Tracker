#include "department.h"

dept::set_name(string str){
  this->name=str;
}

dept::set_ID(int user_id){
  this->ID=user_id;
}

dept::get_ID(){
  return ID;
}

dept::get_name(){
  return name;
}
