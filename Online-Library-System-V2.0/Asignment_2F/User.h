#include <iostream>
#include<string>
#include<cstring>
#pragma once
using namespace std;
class User
{
private:
	string name;
	int age;
	int id;
	string password;
	string email;
public:
	User(); //Default Constructor
	User(string name, int age, string email, string password); //Constructor take 4 parameters
	User(const User& U); //Copy Constructor					  

	//Setter and Getter Functions.
	void setName(string name) {
		this->name = name;
	}
	string getName() const {
		return name;
	}
	void setAge(int age) {
		this->age = age;
	}
	int getAge() {
		return age;
	}
	void setEmail(string email) {
		this->email = email;
	}
	string getEmail() {
		return email;
	}
	void setPassword(string password) {
		this->password = password;
	}
	string getPassword() {
		return password;
	}
	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}

	bool operator==(const User& user); //operator overloading == to comparing two objects.
	friend ostream& operator<<(ostream& output, const User& user); //operator overloading << to print information of object
	friend istream& operator>>(istream& input, User& user); //operator overloading << to input information from the user.
	static int count; //static variable for IDs of Users increasing by 1 for every object
};
