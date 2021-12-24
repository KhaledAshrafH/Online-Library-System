#include"User.h"
#include"Book.h"
#include<string>
#pragma once
class BookList
{
private:
	Book* books;
	int capacity;
public:
	int booksCount = 0;
	BookList(const BookList & anotherList);//Copy Conestractor
	BookList(int capacity);//conestractor take 1 prameter
	Book& searchBook(string name);//Seaching book From Name
	Book& searchBook(int id); //Seaching book From ID
	void deleteBook(int id); //delete a book From ID
	Book getTheHighestRatedBook();//Get The Highest Rated Book
	void addBook(Book & book);//add New Book To List Of Book
	Book* getBooksForUser(User); // get all books of this author
	Book UpdateRateBook(Book b, int rate); //Update Rate Book
	void addAuthor(Book& b);//add Author To book
	Book& operator [] (int position);//Operator[]
	friend ostream& operator<<(ostream & output, BookList & booklist); //to display all books
	static int j; //Static variable to get Users book
	~BookList();//Distractor
};