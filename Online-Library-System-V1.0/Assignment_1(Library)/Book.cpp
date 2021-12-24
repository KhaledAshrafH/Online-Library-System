#include "Book.h"
#include "User.h"
#pragma once
//default Constructor
Book::Book()
{
	Count++;
	id = Count;
}
//Constructor take 3 parameters.
Book::Book(string title, string isbn, string category)
{
	this->title = title;
	this->isbn = isbn;
	this->category = category;
	Count++;
	id = Count;
}
//Copy Constructor
Book::Book(const Book & book)
{
	title = book.title;
	isbn = book.id;
	id = book.id;
	category = book.category;
	averageRating = book.averageRating;
	author = book.author;
}
//calculate average rating for one book.
void Book::rateBook(int rating)
{
	averageRating += rating;
	Ratings++;
}
//operator overloading == to comparing two objects.
bool Book::operator==(const Book & book)
{
	return((title==book.title)&&(isbn==book.isbn)&&(category==book.category)&&(id==book.id)&&(author==book.author));
}
//operator overloading << to print information of object
ostream & operator<<(ostream & output, const Book & book)
{
	if (book.averageRating > 0) {
		output << endl;
		output << "============Book " << book.id << " Info============" << endl;
		output << "Title : " << book.title << " | ISBN : " << book.isbn << " | Id : " << book.id << " | Category : " << book.category << " | Avg Rating : " << book.averageRating / book.Ratings << endl;
		output << "===========================================" << endl;
		output << endl;
		output << book.author;
	}
	else {
		output << endl;
		output << "============Book " << book.id << " Info============" << endl;
		output << "Title : " << book.title << " | ISBN : " << book.isbn << " | Id : " << book.id << " | Category : " << book.category << " | Avg Rating : " << book.averageRating << endl;
		output << "===========================================" << endl;
		output << endl;
	}

	return output;
}
//operator overloading << to input information from the user.
istream & operator>>(istream & input, Book & book)
{
	if (book.id == 1) {
		cout << "Let's add a Book" << endl;
		cout << "Enter the Book Information in this order" << endl;
		cout << "Title ISBN Category (Space sparated)" << endl;
		input >> book.title >> book.isbn >> book.category;
	}
	else {
		cout << "Let's add another Book" << endl;
		cout << "Enter the Book Information in this order" << endl;
		cout << "Title ISBN Category (Space sparated)" << endl;
		input >> book.title >> book.isbn >> book.category;
	}
	return input;
}
int Book::Count = 0; //initial value for this static variable to increase IDs by 1.


