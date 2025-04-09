#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#include <iomanip>  //for setw( width set)

string toLowerString(const char* str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Book class
class Book   
{
    int bookID;
    char bookName[30];
    char author[30];
    char category[30];
    double price;
    float rating;
    int studentID;  // Added studentID

public:
	//DC
    Book()
	{
    	this->bookID=0;
    	this->price=0.0;
    	this->rating=0.0;
    	this->studentID=0;
        strcpy(this->bookName, "Unknown");
        strcpy(this->author, "Unknown");
        strcpy(this->category, "Unknown");
    }
    

	//PC
    Book(int id, const char* name, const char* auth, const char* cat, double pr, float rt)
	{
		this->bookID= id;
        strcpy(this->bookName, name);
        strcpy(this->author, auth);
        strcpy(this->category, cat);
        this->price=pr;
        this->rating= rt;
    }

	//Setter
	void setPrice(double price) {
    this->price = price;
	}
	
	void setRating(float rating) {
	    this->rating = rating;
	}
	
	void displayOneBook() const {
	    display();  // reuse existing display method
	}
	
    void setBookDetails(int id, const char* name, const char* auth, const char* cat, double pr, float rt) 
	{
        this->bookID = id;
        strcpy(this->bookName, name);
        strcpy(this->author, auth);
        strcpy(this->category, cat);
        this->price = pr;
        this->rating = rt;
    }

    // Getters
    //for StudentId in table
    int getStudentID() const 
	{ 
    	return this->studentID; 
	}

    int getBookID() const 
	{ 
		return this->bookID; 
	}
	
    const char* getBookName() const 
	{ 
		return this->bookName; 
	}
	
    const char* getAuthor() const 
	{ 
		return this->author; 
	}
    
	const char* getCategory() const 
	{ 
		return this->category; 
	}
    
	double getPrice() const 
	{ 
		return this->price; 
	}
    
	float getRating() const 
	{ 
		return this->rating; 
	}

    bool isIssued() const 
	{ 
		return this->studentID != 0; 
	}

	//Issue book
    bool issueBook(int studentID) 
	{
        if (!isIssued()) 
		{
            this->studentID = studentID;
            return true;
        }
        return false;
    }

	//Return book method
    void returnBook() 
	{ 
		studentID = 0; 
	}

	//Display Book
    void display() const 
	{
        cout << "\nBook ID: " << bookID << "\nBook Name: " << bookName;
        cout << "\nAuthor: " << author << "\nCategory: " << category; 
        cout << "\nPrice: " << price << "\nRating: " << rating;
        
        if (isIssued()) 
		{
            cout << "\nIssued to Student ID: " << studentID << "\n";
        } else {
            cout << "\nNot issued." << "\n";
        }
    }
};

// Student class
class Student 
{
    int studentID;
    char studentName[30];
    int bookIssuedID;

public:
	
	//DC
    Student()
	{ 
		this->studentID= 0;
		this->bookIssuedID=0; 
		strcpy(this->studentName, "Unknown"); 
	}
	
	//PC
    Student(int id, const char* name, int bookIssuedID)
    {
		this->studentID= studentID;
		strcpy(this->studentName, name);
		this->bookIssuedID= bookIssuedID;
	}
	
	//Setter
    void setStudentDetails(int id, const char* name) 
	{
        this->studentID = id;
        strcpy(this->studentName, name);
    }

	//Getters
    int getStudentID() const 
	{ 
		return this->studentID; 
	}
    
	const char* getStudentName() const 
	{ 	
		return this->studentName; 
	}
    
	int getBookIssuedID() const 
	{ 
		return this->bookIssuedID; 
	}

	//Issue book method
    bool issueBook(int bookID) 
	{
        if (bookIssuedID == 0) 
		{
            this->bookIssuedID = bookID;
            return true;
        }
        return false;
    }

	//Return book method
    void returnBook() 
	{ 
		bookIssuedID = 0; 
	}

    void display() const 
	{
        cout << "Student ID: " << studentID << "\nStudent Name: " << studentName;
        if (bookIssuedID != 0) 
		{
            cout << "\nBook Issued ID: " << bookIssuedID;
        } else {
            cout << "\nNo book issued.";
        }
        cout << endl;
    }
};

// Library class
class Library 
{
    Book books[100];
    Student students[100];
    int bookCount;
    int studentCount;
    
    void toLowerCase(string& str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

public:
	
	//DC
    Library()
	{
		this->bookCount=0;
		this->studentCount=0;
        bookCount = hardCoded(books, bookCount);  // Initialize hardcoded books
    }

	//Hardcoded
	int hardCoded(Book* book, int ctr) 
	{
        book[ctr++] = {101, "Shrimanyogi", "Ranjit Desai", "Historical", 450.00, 4.8};
        book[ctr++] = {102, "Yugandhar", "Shivaji Sawant", "Mythological", 550.00, 4.7};
        book[ctr++] = {103, "Mrutyunjay", "Shivaji Sawant", "Mythological", 500.00, 4.9};
        book[ctr++] = {104, "Purnachandra", "Sane Guruji", "Biography", 300.00, 4.6};
        book[ctr++] = {105, "Batatyachi Chaal", "P L Deshpande", "Humor", 200.00, 4.8};
        return ctr;
    }
    
    // Helper method to search book by ID
	int searchByID(int id) {
	    for (int i = 0; i < bookCount; i++) {
	        if (books[i].getBookID() == id) {
	            return i;
	        }
	    }
	    return -1;
	}
	
	//Add book
    void addBook() 
	{
        if (bookCount < 100) 
		{
            int id;
            char name[30], auth[30], cat[30];
            double pr;
            float rt;
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Name: ";
            cin.ignore();	//to clr buffer
            cin.getline(name, 30); 	//ip after whitespace also accept
            cout << "Enter Author: ";
            cin.getline(auth, 30);
            cout << "Enter Category: ";
            cin.getline(cat, 30);
            cout << "Enter Price: ";
            cin >> pr;
            cout << "Enter Rating: ";
            cin >> rt;
            books[bookCount++].setBookDetails(id, name, auth, cat, pr, rt);
            cout << "Book added successfully!\n";
        } 
		else 
		{
            cout << "Library is full, can't add more books.\n";
        }
    }

    void addStudent() 
	{
        if (studentCount < 100) 
		{
            int id;
            char name[30];
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore(); 	//to clr buffer
            cin.getline(name, 30);  	//ip including whitespace(function)
            students[studentCount++].setStudentDetails(id, name);
            cout << "Student added successfully!\n";
        } else {
            cout << "No space to add more students.\n";
        }
    }

    void issueBookToStudent() 
	{
        int studentID, bookID;
        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Book ID to be issued: ";
        cin >> bookID;

        for (int i = 0; i < studentCount; ++i) 
		{
            if (students[i].getStudentID() == studentID) 
			{
                for (int j = 0; j < bookCount; ++j) 
				{
                    if (books[j].getBookID() == bookID) 
					{
                        if (books[j].issueBook(studentID)) 
						{
                            if (students[i].issueBook(bookID)) 
							{
                                cout << "Book issued successfully!\n";
                            } 
							else 
							{
                                cout << "Student already has an issued book.\n";
                                books[j].returnBook();
                            }
                            return;
                        } 
						else 
						{
                            cout << "Book is already issued.\n";
                            return;
                        }
                    }
                }
                cout << "Book not found.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

	//Return book methood
    void returnBookFromStudent() 
	{
        int studentID;
        cout << "Enter Student ID: ";
        cin >> studentID;

        for (int i = 0; i < studentCount; ++i) 
		{
            if (students[i].getStudentID() == studentID) 
			{
                int bookID = students[i].getBookIssuedID();
                if (bookID != 0) 
				{
                    for (int j = 0; j < bookCount; ++j) 
					{ //preIncrement avoids creating temporary copies
                        if (books[j].getBookID() == bookID) 
						{
                            books[j].returnBook();
                            students[i].returnBook();
                            cout << "Book returned successfully!\n";
                            return;
                        }
                    }
                } 
				else 
				{
                    cout << "No book issued to this student.\n";
                }
                return;
            }
        }
        cout << "Student not found.\n";
    }

	//Search book method
    void searchBookByID(int id) 
	{
        for (int i = 0; i < bookCount; ++i) 
		{
            if (books[i].getBookID() == id) 
			{
                books[i].display();
                return;
            }
        }
        cout << "Book not found.\n";
    }
    
     // Search book by Author
      void searchBookByAuthor() {
        char searchAuthor[30];
        cout << "Enter Author to search: ";
        cin.ignore();
        cin.getline(searchAuthor, 30);
        
        bool found = false;
        string authorLower = searchAuthor;
        // Convert search term to lowercase
        transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
        
        cout << "\nSearch Results for Author: " << searchAuthor << "\n";
        cout << "----------------------------------------\n";
        
        for (int i = 0; i < bookCount; ++i) {
            string bookAuthorLower = books[i].getAuthor();
            // Convert book author to lowercase
            transform(bookAuthorLower.begin(), bookAuthorLower.end(), bookAuthorLower.begin(), ::tolower);
            
            // Check if the search term appears in the author name
            if (bookAuthorLower.find(authorLower) != string::npos) {
                books[i].display();
                found = true;
                cout << "----------------------------------------\n";
            }
        }
        
        if (!found) {
            cout << "No books found by author '" << searchAuthor << "'.\n";
        }
    }
    
    
    // Display all students
	void displayAllStudents() const 
	{
	    if (studentCount == 0) 
		{
	        cout << "No students to display.\n";
	    } 
		else 
		{
	        cout << "\n +-------------+--------------+\n";
	        cout << " | Student ID  | Student Name |\n";
	        cout << " +-------------+--------------+\n";
	        
	        for (int i = 0; i < studentCount; ++i) 
	        {
	            cout << " | "<< setw(11) << students[i].getStudentID()  
	                 << " | " << setw(12)<<students[i].getStudentName() << " |\n";
	        }
	        cout << " +-------------+--------------+\n";
	    }
	}

    
	//Display allBooks
	void displayAllBooks() 
	{
	    cout << "\n" 
	         << "+-----------+--------------------------+-------------------+--------------+----------+--------+---------------+\n"
	         << "| Book ID   | Book Name                | Author            | Category     | Price    | Rating | Issued To     |\n"
	         << "+-----------+--------------------------+-------------------+--------------+----------+--------+---------------+\n";
	    
	    for (int i = 0; i < bookCount; ++i) 
	    {
	        cout << "| " << setw(9) << books[i].getBookID() << " | " 
	             << setw(24) << books[i].getBookName() << " | "
	             << setw(17) << books[i].getAuthor() << " | "
	             << setw(12) << books[i].getCategory() << " | "
	             << setw(8) << books[i].getPrice() << " | "
	             << setw(6) << books[i].getRating() << " | ";
	        
	        // Check if book is issued and display student ID
	        if (books[i].isIssued()) {
	            cout << setw(13) << books[i].getStudentID() << " |";
	        } else {
	            cout << setw(13) << "Not Issued" << " |";
	        }
	        cout << "\n";
	    }
	    
	    cout << "+-----------+--------------------------+-------------------+--------------+----------+--------+---------------+\n";
	}
		
		// Delete book method
	void deleteBook(int id) 
	{
	    int index = searchByID(id);
	    if (index != -1) 
	    {
	        // Shift the elements after the found index
	        for (int i = index; i < bookCount - 1; i++) 
	        {
	            books[i] = books[i + 1];
	        }
	        bookCount--;  // Reduce the book count
	        cout << "Book with ID " << id << " deleted successfully.\n";
	    } 
	    else 
	    {
	        cout << "Book not found.\n";
	    }
	}

	
	void updatePriceAndRating(int id) {
	        int index = searchByID(id);
	        if (index != -1) {
	            double newPrice, newRating;
	            cout << "Enter new Price: ";
	            cin >> newPrice;
	            cout << "Enter new Rating: ";
	            cin >> newRating;
	            
	            books[index].setPrice(newPrice);
	            books[index].setRating(newRating);
	            
	            cout << "\nPrice and Rating updated successfully!\n";
	        } else {
	            cout << "\nBook not found!\n";
	        }
	    }
	
	
	void sortBooks() {
	        for (int i = 0; i < bookCount - 1; i++) {
	            for (int j = 0; j < bookCount - i - 1; j++) {
	                if (books[j].getBookID() > books[j + 1].getBookID()) {
	                    swap(books[j], books[j + 1]);
	                }
	            }
	        }
	    }
	
	 void searchByCategory(string category) {
        // Convert search category to lowercase
        cout << "----------------------------------------\n";
        transform(category.begin(), category.end(), category.begin(), ::tolower);
        bool found = false;

        for (int i = 0; i < bookCount; i++) {
            // Convert book category to lowercase for comparison
            string bookCategory = toLowerString(books[i].getCategory());
            if (bookCategory.find(category) != string::npos) {
                books[i].displayOneBook();
                found = true;
                cout << "----------------------------------------\n";
            }
        }

        if (!found) {
            cout << "\nNo books found in this category!\n";
        }
    }


};

// Main function
int main() 
{
    Library library;
    int choice;
    cout<<" Hardcoded Books are: ";
    library.displayAllBooks();

    do {
        cout << "\nLibrary Management System\n";
        cout << "01. Add Book\n";
        cout << "02. Add Student\n";
        cout << "03. Issue Book to Student\n";
        cout << "04. Return Book from Student\n";
        cout << "05. Search Book by ID\n";
        cout << "06. Search by Author \n";
        cout << "07. Search by Category \n";
        cout << "08. Delete Book \n";
        cout << "09. Update price and rating \n";
        cout << "10. Sort Books By ID \n";
        cout << "11. Display All Books\n";
        cout << "12. Display all Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                library.addBook();
                break;
                
            case 2:
                library.addStudent();
                break;
                
            case 3:
                library.issueBookToStudent();
                break;
                
            case 4:
                library.returnBookFromStudent();
                break;
                
            case 5: 
				{
	                int id;
	                cout << "Enter Book ID to search: ";
	                cin >> id;
	                library.searchBookByID(id);
	                break;
	            }
	            
	        case 6: 
					library.searchBookByAuthor(); break;
	                break;
	                
	        case 7: {
                string category;
                cout << "\nEnter Category: ";
                cin.ignore();
                getline(cin, category);
                library.searchByCategory(category);
                break;
            }
            
            case 8: {
                int id;
                cout << "\nEnter Book ID you want to delete: ";
                cin >> id;
                library.deleteBook(id);
                break;
            }
            
            case 9: {
                int id;
                cout << "\nEnter Book ID to update Price and Rating: ";
                cin >> id;
                library.updatePriceAndRating(id);
                break;
            }
            
            case 10: 
			    library.sortBooks();
			    cout << "\nBooks sorted successfully by ID!\n";
			    break;

            case 11:
                library.displayAllBooks();
                break;
                
            case 12:
            	library.displayAllStudents();
            	break;
            	
            case 0:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice! Please enter valid choice.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}