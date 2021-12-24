#include "Book.h"
#include "User.h"
#pragma once
//default Constructor
Book::Book()
{
	averageRating = 0;
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
Book::Book(const Book& book)
{
	averageRating = 0;
	title = book.title;
	isbn = book.id;
	id = book.id;
	category = book.category;
	averageRating = book.averageRating;
	author = book.author;

}
double Book::AvgRate()
{
	return averageRating / Ratings;
}
//calculate average rating for one book.
void Book::rateBook(int rating)
{
	averageRating = 0;
	averageRating += rating;
	Ratings++;
	averageRating / Ratings;
}

//operator overloading == to comparing two objects.
bool Book::operator==(const Book& book)
{
	return((title == book.title) && (isbn == book.isbn) && (category == book.category) && (id == book.id) && (author == book.author));
}
//operator overloading << to print information of object
ostream& operator<<(ostream& output, Book& book)
{

	
	if (book.getAuthor().getAge()==0) {
		output << "============Book " << book.id << " Info============" << endl;
		output << "Title : " << book.title << "\nISBN : " << book.isbn << "\nId : " << book.id << "\nCategory : " << book.category << "\nAvg Rating : " << book.averageRating << endl;
	}
	else {
		output << "============Book " << book.id << " Info============" << endl;
		output << "Title : " << book.title << "\nISBN : " << book.isbn << "\nId : " << book.id << "\nCategory : " << book.category << "\nAvg Rating : " << book.averageRating << endl;
		output << book.getAuthor();
	}

	return output;
}
//operator overloading << to input information from the user.
istream& operator>>(istream& input, Book& book)
{
	
		cout << "Let's add a Book" << endl;
		cout << "Enter the Book Information in this order" << endl;
		cout << "Title ISBN Category (Space sparated)" << endl;
		input >> book.title >> book.isbn >> book.category;
		book.setId(book.Count+1);
		book.Count++;
		
	return input;
}
int Book::Count = 0; //initial value for this static variable to increase IDs by 1.


