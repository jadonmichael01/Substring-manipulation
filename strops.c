#include <stdio.h>
#include <string.h>
#include "strops.h"

void insert_substring(char* str, int pos, char* substr){
  int n = strlen(str);
  int sub = strlen(substr);  
  if(pos > n){ // if pos is not within str's len start the insertion at the end of str
    pos = n;
  }
  for(int i = n; i >= pos; i--){ // this forloops creates space for the new substring
    str[sub + i] = str[i]; //start at the end of the new string length by adding sub len and str len then decrement
  }
  for(int i = 0; i < sub; i++){ //this forloop inserts the new substring 
    str[pos + i] = substr[i];
  } 
}

int delete_substring(char* str, char* substr){

  int i = 0, j = 0;
  while(*(str + j) != '\0' && (*(substr + i) != '\0')) {
      if(*(substr + i) != *(str +j)){ //this will search for the occurrence of the substring
          i = 0;
          j++;
      }else {
          i++;
          j++;
      }
  }
  
  int occurence = j - i; // this is the location of the substring's occurrence 
  int sublen = strlen(substr);
  do{
      str[occurence] = str[sublen + occurence]; //delete the substring from string
      occurence++;
  } while(str[occurence] != '\0');
  
  if(*(substr + i) != '\0'){ //if substring is not found return -1
      return - 1;
  }else {
      return j - i; //otherwise return the location of the substring
  }
  
}

int replace_substring(char* str, char* substr, char* new_substr){
    
  int i = 0, j = 0;
  while(*(str + j) != '\0' && (*(substr + i) != '\0')) {
      if(*(substr + i) != *(str +j)){
          i = 0;
          j++;
      }else {
          i++;
          j++;
      }
  }
  if(*(substr + i) != '\0'){
      return - 1;
  }
  
  int location = delete_substring(str, substr); // get location of substr removed
  insert_substring(str, location, new_substr); // insert the new_substr 
  return location; // return the location of the substr removed
}
