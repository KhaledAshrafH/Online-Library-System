#include <iostream>
#include<string>
#include<cstring>
#include "User.h"
#pragma once
using namespace std;
class Book
{
private:
	string title; 
	string isbn;
	int id;
	string category;
	double averageRating = 0.0;
	User author;
	double Ratings=0.0; //to know number of ratings.
public:
	Book(); //default Constructor
	Book(string title, string isbn, string category); //Constructor take 3 parameters.
	Book(const Book& book); //Copy Constructor
	//Setter and Getter Functions
	void setTitle(string title) {
		this->title = title;
	}
	string getTitle() {
		return title;
	}
	void setISBN(string isbn) {
		this->isbn = isbn;
	}
	string getISBN() {
		return isbn;
	}
	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}
	void setCategory(string category) {
		this->category = category;
	}
	string getCategory() {
		return category;
	}
	void setAuthor(User & user) {
		author.setId(user.getId());
		author.setName(user.getName());
		author.setAge(user.getAge());
		author.setEmail(user.getEmail());
	}
	User getAuthor() {
		return author;
	}
	
	void rateBook(int rating); //function calculates average rating for one book.
	bool operator==(const Book& book); //operator overloading == to comparing two objects.
	friend ostream &operator<<(ostream &output, const Book &book); //operator overloading << to print information of object
	friend istream &operator>>(istream &input, Book &book); //operator overloading << to input information from the user.
	static int Count; //static variable for IDs of Books that increasing by 1 for every object 
};


