#include <iostream>
#include<string>
#include<cstring>
#include "User.h"
#include "Book.h"
using namespace std;

int main()
{
	User u1, u2;
	Book b1, b2;
	cin >> u1;
	cout << u1;
	cin >> u2;
	cout << u2;
	cin >> b1;
	cout << b1;
	cin >> b2;
	cout << b2;
	cout << "Let's assign an author for the first book,set the first user as an a user" << endl;
	cout << "Let's rate the first book with 3 and 4 ratings and print the book info" << endl;
	b1.setAuthor(u1);
	b1.rateBook(3);
	b1.rateBook(4);
	cout << b1;
	cout << "Let's add a new rating for b1 with 5 and print the book info" << endl;
	b1.rateBook(5);
	cout << b1;
	
	return 0;
}
