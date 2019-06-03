#include <iostream>
using namespace std;

#include "String.h"

String::String() {
  size = 0;
  str = new char[1];
  str[0] = '\0';
}

String::String(char c) {
  size = 1;
  str = new char[2];
  str[0] = c;
  str[1] = '\0';
}

String::String(const char* s) {
  //TODO
  int i = 0;
  size = 0;
  while (s[i++]) {
    size++;
  }
  str = new char[size + 1];
  for (i=0; i < size; i++){
    str[i] = s[i];
  }
  str[size] = '\0';
}

String::String(const String& s) : size(s.size), str(s.str)  {
  //TODO
  size = s.size;
  str =  new char[size + 1];
  for (int i=0; i < size; i++){
    str[i] = s.str[i];
  }
  str[size] = '\0';
}

String::String(String&& s) : size(s.size), str(s.str) {
  //TODO
  s.size = 0;
  s.str = nullptr;
}

String::~String() { delete[] str;}

char& String::operator[] (int index) {
  //TODO
  if (str[0] == '\0'){
    return str[0];
  }
  return str[index];
}

String& String::operator=(const String& s) {
  //TODO
  if (&s == this) {
    return *this; }
  delete[] str;
  size = s.size;
  str =  new char[size + 1];
  for (int i=0; i <= size; i++){
    str[i] = s.str[i];
  }
  str[size] = '\0';
  return *this;
}

String& String::operator=(String&& s) {
  //TODO
  if (&s == this) {
    return *this;
  }
  delete[] str;
  size = s.size;
  str = s.str;
  s.size = 0;
  s.str = nullptr;
  return *this;
}

String& String::operator+=(String& s) {
  //TODO
  char* temp = new char[size + s.size + 1];
  int i = 0;
  for (i = 0; i < size; i++) {
    temp[i] = str[i];
  }
  delete[] str;
  for (int j = 0, i = size; i <= size + s.size; i++, j++) {
    temp[i] = s.str[j];
  }
  temp[size + s.size] = '\0';
  str = new char[size + s.size + 1];
  for (i = 0; i < size + s.size; i++) {
    str[i] = temp[i];
  }
  str[size + s.size] = '\0';
  delete[] temp;
  size += s.size;
  return *this;
}
