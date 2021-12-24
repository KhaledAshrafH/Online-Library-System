#include<iostream>
#include "Book.h"
#include "BookList.h"
#include "User.h"
#include "UserList.h"
#include <string>
#include <cstring>
using namespace std;
UserList *userOfList; //Object Pointer From Userlist
int main() {
endingpoint0:
	char selectMenu; //variable to Main Menu
	cout << "Select one of the following choices : " << endl;
	cout << "1- Books Menu \n2- Users Menu \n3- Exit\n"; //Main Menu
	cin >> selectMenu;

	switch (selectMenu) {
		//Cases of Books Menu
	case '1': {
		int n; //variable to capacity of BookList
		User u; //object from user
		cout << "How many Books will be added?" << endl;
		cin >> n;
		BookList bookOfList(n); //object from BookList
	endingpoint3: //To return to this point
		int selectMenuBook;
		Book b; //object from book
		cout << "BOOKS MENU" << endl;
		cout << "1- Create a book and add it to the list\n2- search For a book\n3- display all books\n4- Get the highest rating book\n5- Get all books of a user\n6- Copy the current Book List to a new Book List and switch to it\n7- Back to the main menu\n";
		cin >> selectMenuBook;

		switch (selectMenuBook) {
			//Create a book and add it to the list
		case 1: {
			int assignAuthor = 0;
			bookOfList.addBook(b); //add book to BookList
		endingpoint10: //To return to this point
			cout << "1- Assign author\n2- Continue\n";
			cin >> assignAuthor;
			//when entered 1 
			if (assignAuthor == 1) {
				int id;
				cout << "Enter author (user) id:" << endl;
				cin >> id;
				//when book has author
				if (id <= userOfList->counter) {
					b.setAuthor(userOfList->searchUser(id));
					bookOfList.addAuthor(b);
					goto endingpoint3;
				}
				//when book hasn't author
				else {
					cout << "No Author Found with id = " << id << endl;
					goto endingpoint10;
				}

			}
			//when entered 2
			else goto endingpoint3;
		}
				//Searching For a book
		case 2: {
			int selectSearch = 0;
			cout << "SEARCH FOR A BOOK" << endl;
			cout << "1- Search by name\n2- Search by id\n3- Return to Books Menu\n";
			cin >> selectSearch;
			switch (selectSearch) {
				//Searching by Name
			case 1: {
				int searchByName;
				string name; //name that user search it
				string str; //new name that user input it
				cout << "Enter Name\n";
				cin >> name;
				b = bookOfList.searchBook(name); //searchName in bookList and store this in object b from book
				cout << b;
				u = bookOfList.searchBook(name).getAuthor();//search Author in bookList and store this in object u from user
				cout << endl;
			endingpoint5://To return to this point

				cout << "1- Update Author\n2- Update Name\n3- Update Category\n4- Delete Book\n5- Rate Book\n6- Get back to books menu\n";
				cin >> searchByName; //Number of Method Updating in Searcingh By Name
				switch (searchByName) {
					//Updating Author
				case 1: {
					cout << "Enter New Author : " << endl;
					cin >> str;//Updating Author from User Input it
					u = bookOfList.searchBook(name).getAuthor();//Searching by name in BookList to Get Author and Store it in object of User
					u.setName(str);//Set New Author in object of User
					bookOfList.searchBook(name).setAuthor(u);//The Author will update here  
					goto endingpoint5;//To return to this point
				}
						//Updating Name
				case 2: {
					cout << "Enter New Name : " << endl;
					cin >> str;//Updating Name from User Input it 
					bookOfList.searchBook(name).setTitle(str);//Searching by name in BookList to Set title Of Book And Updating it
					goto endingpoint5;//To return to this point
				}
						//Updating Category
				case 3: {
					cout << "Enter New Category : " << endl;
					cin >> str;//Updating Category from User Input it
					bookOfList.searchBook(name).setCategory(str);//Searching by name in BookList to Set Category Of Book And Updating it
					goto endingpoint5;//To return to this point
				}
						//Deleting Book
				case 4: {
					b = bookOfList.searchBook(name); //Searching by name in BookList And Store it in Object Of Book
					bookOfList.deleteBook(b.getId());//Deleting Book By Id
					goto endingpoint5;//To return to this point
				}
						//Updating Rateing Book
				case 5: {
					int avg; //Average Books
					cout << "Enter Rating Value : " << endl;
					cin >> avg; //Average which User Input it
					bookOfList.searchBook(name).rateBook(avg);//Searching by name in BookList And Update Rating
					goto endingpoint5;//To return to this point
				}
						//Get back to books menu
				case 6: {
					goto endingpoint3;//To return to this point
				}
				}
			}
					//Searching by ID
			case 2: {
				int searchByID;
				int id;//Searching Book with ID
				string str;//Updating String
				cout << "Enter ID" << endl;
				cin >> id;
				b = bookOfList.searchBook(id);//Searching by ID in BookList And Store it in Object Of Book
				cout << b;//Display Object OF book 
				u = bookOfList.searchBook(id).getAuthor();//Searching by ID in BookList And Get Name Of Author And Store it in Object Of User
				cout << "====================================" << endl;
			endingpoint6://To return to this point

				cout << "1- Update Author\n2- Update Name\n3- Update Category\n4- Delete Book\n5- Rate Book\n6- Get back to books menu\n";
				cin >> searchByID;
				switch (searchByID) {
					//Updating Author
				case 1: {
					cout << "Enter New Author : " << endl;
					cin >> str;//Updating Author from User Input it
					u = bookOfList.searchBook(id).getAuthor();//Searching by ID in BookList to Get Author and Store it in object of User
					u.setName(str);//Set New Author in object of User
					bookOfList.searchBook(id).setAuthor(u);// The Author will update here  
					goto endingpoint6;//To return to this point
				}
						//Updating Name
				case 2: {
					cout << "Enter New Name : " << endl;
					cin >> str;//Updating Name from User Input it 
					bookOfList.searchBook(id).setTitle(str);//Searching by ID in BookList to set title Of Book And Updating it
					goto endingpoint6;//To return to this point
				}
						//Updating Category
				case 3: {
					cout << "Enter New Category : " << endl;
					cin >> str;//Updating Category from User Input it
					bookOfList.searchBook(id).setCategory(str);//Searching by ID in BookList to Set Category Of Book And Updating it
					goto endingpoint6;//To return to this point
				}
						//Deleting Book
				case 4: {
					b = bookOfList.searchBook(id);//Searching by ID in BookList And Store it in Object Of Book
					bookOfList.deleteBook(b.getId());//Deleting Book By Id
					goto endingpoint6;//To return to this point
				}
						//Updating Rateing Book
				case 5: {
					int avg;//Average Book
					cout << "Enter Rating Value : " << endl;
					cin >> avg;//Average which User Input it
					bookOfList.searchBook(id).rateBook(avg);//Searching by ID in BookList And Update Rating
					goto endingpoint6;//To return to this point
				}
						//Get back to books menu
				case 6: {
					goto endingpoint3;//To return to this point
				}
				}

			}
					//Return to Books Menu
			case 3: {
				goto endingpoint3;//To return to this point
			}
			}
		}
				//Display all books
		case 3: {
			cout << bookOfList; //Display List Of Books
			goto endingpoint3;//To return to this point
		}
				//highest rateing book
		case 4: {
			b = bookOfList.getTheHighestRatedBook(); //Get The Highest Rated Book from Book List And Store it in Object Of Book
			cout << b;//Display Object Of This Book
			goto endingpoint3;//To return to this point
		}
				//get all books for user
		case 5: {
			int id;
			cout << "Enter Id Author : " << endl;
			cin >> id;
			Book * bookauthor = new Book[1000];//Dynamic Pointer Array From Object Book it Size = 1000 
			bookauthor = bookOfList.getBooksForUser(userOfList->searchUser(id));//Geting Books For User From Searching ID and Store it in Object Pointer  
			for (int i = 0; i < bookOfList.j; i++) { cout << bookauthor[i]; } //Static variable to get Users book

			goto endingpoint3;//To return to this point
		}
				//Copy the current book
		case 6: {
			BookList bookOfList1 = bookOfList; //Copy in New List Of Book
			cout << "Copied current list (" << bookOfList.booksCount << " books) to anew list and switched to it." << endl;;
			goto endingpoint3;//To return to this point
		}
				//back To Main Menu
		case 7: {
			goto endingpoint0;//To return to this point
		}
				//when user entered invalid number
		default: {
			cout << endl;
			cout << "Invalid Number! Try again..." << endl;
			goto endingpoint3;//To return to this point
		}
		}
	}
			  //Users Menu
	case '2': {
		int selectMenuUser;
		int n;//Number Of Users will be added(capacity)
		User *u = new User;// Object Pointer From User
		cout << "How many Users will be added?" << endl;
		cin >> n;
		userOfList = new UserList(n);//add capacity
	endingpoint1://To return to this point
		cout << "USERS MENU" << endl;
		cout << "1- Create a user and add it to the list\n2- search For a user\n3- display all users\n4- back to The Main menu \n";
		cin >> selectMenuUser;
		switch (selectMenuUser) {
			//Creating a user and add it to the list
		case 1: {
			userOfList->addUser(*u);//adding New User To List Of Users 
			goto endingpoint1;//To return to this point
		}
				//searching For a user
		case 2: {
		endpointing2:
			int selectSearch = 0;
			cout << "SEARCH FOR A USER" << endl;
			cout << "1- Search by name\n2- Search by id\n3- Return to Users Menu\n";
			cin >> selectSearch;
			switch (selectSearch) {
				//Searching by Name
			case 1: {
				int searchByName;
				string name;
				cout << "Enter Name\n";
				cin >> name;
				*u = userOfList->searchUser(name);//Searching User By Name From Users List And Store it Object Pointer Of User 
				cout << *u; //Display Object
				cout << "====================================" << endl;
				cout << "1- Delete user\n2- Return to Users Menu\n";
				cin >> searchByName;
				switch (searchByName) {
					//Deleting user
				case 1: {
					userOfList->deleteUser(name);//Deleting This user From Name 
					goto endpointing2;//To return to this point
				}
						//Return to Users Menu
				case 2: {goto endingpoint1; }//To return to this point
				}
			}
					// Searching by ID
			case 2: {
				int searchByID;
				int id;
				cout << "Enter ID" << endl;
				cin >> id;
				cout << userOfList->searchUser(id);//Display Users From ID
				cout << "====================================" << endl;
				cout << "1- Delete user\n2- Return to Users Menu\n";
				cin >> searchByID;
				switch (searchByID) {
					//Deleting user
				case 1: {
					userOfList->deleteUser(id); //Deleting This user From ID
					goto endpointing2;//To return to this point
				}
						//Return to Menu
				case 2: {goto endingpoint1; }//To return to this point
				}
			}
					//Return to Users Menu
			case 3: {
				goto endingpoint1;//To return to this point
			}

			}
		}
				//Display All Users
		case 3: {
			cout << *userOfList;
			goto endingpoint1;//To return to this point
		}
				//Back To The Main Menu
		case 4: {
			goto endingpoint0;//To return to this point
		}
				//when user entered invalid number
		default: {
			cout << endl;
			cout << "Invalid Number! Try again..." << endl;
			goto endingpoint1;//To return to this point
		}
		}
	}
			  //Exit This Program
	case '3': {
		cout << "The program ended. " << endl;
		return 0;
	}
			  //when user entered invalid number
	default: {
		cout << endl;
		cout << "Invalid Number! Try again..." << endl;
		goto endingpoint0;//To return to this point
	}
	}
	return 0;
}