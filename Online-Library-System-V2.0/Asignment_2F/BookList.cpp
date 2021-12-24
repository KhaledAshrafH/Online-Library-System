#include "User.h"
#include"Book.h"
#include "BookList.h"

BookList::BookList(const BookList& anotherList)//Copy Constractor
{
	capacity = anotherList.capacity;
	books = anotherList.books;
	booksCount = anotherList.booksCount;
}

BookList::BookList(int capacity)//Constractor Take One Parameter
{
	this->capacity = capacity;
	books = new Book[capacity];
}

Book& BookList::searchBook(string name)//Searching book By Name
{
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getTitle() == name)
			return  books[i];
	}
}

Book& BookList::searchBook(int id)//Searching book By ID
{
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getId() == id)
			return  books[i];
	}
}

void BookList::deleteBook(int id)//Deleting book By Name
{
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getId() == id) {
			books[i] = books[i + 1];
			booksCount--;
		}
	}
}

Book BookList::getTheHighestRatedBook()//Get The Highest Rated Book
{
	Book Max;//Object From Book TO Store books 
	for (int i = 0; i < booksCount; i++) {
		Max = books[0];
		if (books[i].AvgRate() > books[0].AvgRate())
			Max = books[i];
	}
	return Max;
}
void BookList::addBook(Book & book)//add New Book To List Of book
{
	cin >> book;
	books[booksCount] = book;
	booksCount++;
}

Book* BookList::getBooksForUser(User u)//Get Books For User
{
	Book *b = new Book[booksCount];
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getAuthor().getId() == u.getId()) {
			b[j] = books[i];
			j++;
		}
	}
	return b;
}

Book BookList::UpdateRateBook(Book b, int rate)//Updating Rate Book 
{
	b.rateBook(rate);
	return b;
}

void BookList::addAuthor(Book& b)//Add Author To book
{
	books[b.getId() - 1] = b;
}

Book& BookList::operator[](int position)
{
	return books[position];
}

BookList::~BookList()//Destractor
{
	delete[] books;
}

ostream & operator<<(ostream & output, BookList & booklist)
{
	for (int i = 0; i < booklist.booksCount; i++) {
		output << booklist.books[i];
		output << endl;
	}
	return output;
}
int BookList::j = 0; // Static variable to get Users book