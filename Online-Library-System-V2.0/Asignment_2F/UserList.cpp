#include "BookList.h"
#include "UserList.h"
#include "User.h"
#include<iostream>
using namespace std;


UserList::UserList(int capacity)//Parametres Constractor
{
	this->capacity = capacity;
	users = new User[capacity];//array dynamic allocation
}
void UserList::addUser(User & user)//add New User To list
{
	cin >> user;
	users[usersCount] = user;
	counter++;//static 
	usersCount++;
}

User& UserList::searchUser(string name) //Searching User From Name
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getName() == name)
			return users[i];
	}

}

User& UserList::searchUser(int id)//Searching User From Name
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getId() == id)
			return  users[i];
	}
}

void UserList::deleteUser(int id)//deleting User From ID And shifting 
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getId() == id) {
			users[i] = users[i + 1];
			usersCount--;
			counter--;
		}
	}
}
void UserList::deleteUser(string name)//deleting User From Name and shifing
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getName() == name) {
			users[i] = users[i + 1];
			usersCount--;
			counter--;
		}
	}
}

UserList::~UserList()//Destractor
{
	delete[] users;
}

ostream& operator<<(ostream& output, UserList& userList)//To Display 
{

	for (int i = 0; i < userList.usersCount; i++) {
		output << userList.users[i];
		output << endl;
	}
	return output;
}
int UserList::counter = 0;// Declare static variable and initial value for this static variable
