#pragma once
//shame on you
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


class String {

	char* chars;
	size_t length;
	// ...
public:

	String(const char* str) :length(strlen(str)) {// CTOR
		cout << "String CTOR" << endl;
		chars = new char[length];
		strcpy(chars, str);
	}
	String(const String& s) {// copy constructor
		cout << "String Copy CTOR" << endl;
		chars = nullptr;
		*this = s;
	}
	String& operator=(const String& s) {// OPERATOR =
		if (this != &s) {
			cout << "String op=" << endl;
			delete[] chars;
			length = s.length;
			chars = new char[length];
			strcpy(chars, s.chars);
		}
		return *this;
	}
	

	String& operator=(String&& s)noexcept { // move operator=
		if (this != &s) {
			cout << "String&& op=" << endl;
			length = s.length;
			chars = s.chars;
			s.length = 0;
			s.chars = nullptr;
		}
		return *this;
	}


	String(String&& s)noexcept { // move constructor
		cout << "String move CTOR" << endl;
		*this = move(s); // same as *this=(String&&)s
	}


	~String() {
		cout << "String DTOR";
		if (chars == nullptr) cout << " (with chars==null)";
		cout << endl;
		delete[] chars;
	}
};
class Employee
{
	String name;
public:
	Employee(String name) :name((String&&)name) {
		cout << "emp CTOR" << endl;
	}
	
	Employee(String&& name) :name(move(name)) {
		cout << "employee CTor" << endl;

	}
	~Employee() {

		cout << "employee Dtor" <<endl;
	};

};



