#include "User.h"
#pragma once
//Default Constructor
User::User() :name("Unknown"), age(0), id(0), password("Unknown"), email("Unknown") {
	
}
//Constructor take 4 parameters
User::User(string name, int age, string email, string password)
{
	this->name = name;
	this->age = age;
	this->email = email;
	this->password = password;
	count++;
	id = count;
}
//Copy Constructor
User::User(const User& U)
{
	name = U.name;
	age = U.age;
	email = U.email;
	password = U.password;
	id = U.id;
}
//operator overloading == to comparing two objects.
bool User::operator==(const User& user)
{
	return((name == user.name) && (email == user.email) && (id == user.id) && (age == user.age));
}
//operator overloading << to print information of object
ostream& operator<<(ostream& output, const User& user)
{
	output << endl;
	output << "============User " << user.id << " Info============" << endl;
	output << "Name : " << user.name << "\nAge : " << user.age << "\nId : " << user.id << "\nEmail : " << user.email << endl;
	output << "===========================================" << endl;
	return output;
}
//operator overloading << to input information from the user.
istream& operator>>(istream& input, User& user)
{
	
		cout << "Enter the User Information in this order" << endl;
		cout << "Name Age Email Password (Space sparated)" << endl;
		input >> user.name >> user.age >> user.email >> user.password;
		user.setId(user.count+1);
		user.count++;
		return input;
}

int User::count = 0; //initial value for this static variable to increase IDs by 1.


