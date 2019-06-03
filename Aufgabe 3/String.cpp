// String.cpp
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
	size = 0;
	while (*s != '\0') {
		s++;
		size++;
	}
	s -= size;
	str = new char[(size + 1)];
	for (int i = 0; i < size; i++) {
		str[i] = s[i];
	}
	str[size] = '\0';
}

//copy Konstruktor
String::String(const String& s) {
	size = s.size;
	str = new char[(size + 1)];
	for (int i = 0; i < size; i++) {
		str[i] = s.str[i];
	}
	str[size] = '\0';
}

//move Konstruktor
String::String(String&& s) {
	size = s.size;
	str = s.str;
	s.str = nullptr;
}

//Destruktor
String::~String() {
	delete[] str;
}

//Indexzugriff (Überladung)
char& String::operator[](int index) {
	return str[index];
}

//copy Zuweisung
String& String::operator=(const String& s) {
	if (this != &s) {
		size = s.size;
		delete[] str;
		str = new char[(size + 1)];
		for (int i = 0; i < size; i++) {
			str[i] = s.str[i];
		}
		str[size] = '\0';
	}
	return *this;
}

//move Zuweisung
String& String::operator=(String&& s) {
	if (this != &s) {
		delete[] str;
		str = s.str;
		s.str = nullptr;
		size = s.size;
	}
	return *this;
}

//Konkatenation von Strings (Überladung)
String& String::operator+=(String& s) {
  
	size += s.size;
  
  //temp char array, welches den ganzen String beinhalten soll
	char* temp = new char[(size + 1)];
  
  //Kopiere den vorderen String nach temp
	while (*str != '\0') {
		*temp = *str;
		temp++;
		str++;
	}
  //lösche das alte this.str
	delete[] str;
  
  //Kopiere den hinteren String nach temp
	while (*s.str != '\0') {
		*temp = *s.str;
		temp++;
		s.str++;
	}
  
  //Wichtig! Setzt den Pointer s.str wieder auf die eigentliche Stelle
	s.str -= s.size;
	
  *temp = '\0';
	temp -= size;
  
  //Neues this.str wird deklariert und die einzelnen chars von temp werden nach this.str kopiert
  //Wichtig! this.str MUSS neu deklariert werden, da es in Zeile 103 gelöscht wurde. Denn: Es wird am Ende der main nochmal gelöscht.
  //Wenn es nicht neu deklariert wurde wird es 2x gelöscht -> runtime-exception!
	str = new char[(size + 1)];
	for (int i = 0; i < size; i++) {
		str[i] = temp[i];
	}
	str[size] = '\0';
  //Nur wenn die einzelnen chars kopiert werden kann temp gelöscht werden. temp muss jedoch gelöscht werden, sonst gibt es ein Speicherleck
	delete[] temp;
	return *this;
}
