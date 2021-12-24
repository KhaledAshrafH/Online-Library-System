#include "User.h"
#include <string>
#pragma once
class UserList
{
private:
	User* users;//Object Pointer From User
	int capacity;//size
	int usersCount = 0;
public:
	UserList(int capacity); //Parametres Constractor
	void addUser(User & user); //To add User To List Of User
	User& searchUser(string name);//Seaching By name
	User& searchUser(int id);//Seaching By ID
	void deleteUser(int id);//Deleting User By ID
	void deleteUser(string name);//Deleting User By Name
	friend ostream& operator<<(ostream& output, UserList& userList);//Operator<<
	static int counter;// Counter Of Objects
	~UserList();//Distractor
};

