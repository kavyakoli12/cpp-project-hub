#include <iostream>
#include <string>
#include <vector>
using namespace std;
class book
{
private:
    int isbn;
    string author;
    string title;
    bool isAvailable;

public:
    book()
    {
        isbn = 0;
        isAvailable = true;
        title = " ";
        author = " ";
    }
    void Display()
    {
        if (isbn == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        cout << "Name  :" << title << endl;
        cout << "Author :" << author << endl;
        cout << "Book number :" << isbn << endl;
        cout << "Availability :" << isAvailable << endl;
    }
    void Addbook(int bookid)
    {
        cout << "Enter the name of book :" << endl;

        cin.ignore();
        getline(cin, title);
        cout << "Enter the name of author :" << endl;
        getline(cin, author);
        cout << "Enter the availability? (1/0):" << endl;
        cin >> isAvailable;
        isbn = bookid;
    }
    void deletebook()
    {
        title = "";
        author = "";
        isbn = 0;
        isAvailable = true;
    }
};
int main()
{
    int n;
    cout << "Enter the number of book";
    cin >> n;
    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of books. Please enter a number between 1 and 100." << endl;
        return 1;
    }
    int choice;
    vector<book> books;
    int id = 1;
    do
    {
        cout << "\n=============================" << endl;
        cout << "    Library Management System" << endl;
        cout << "=============================" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Show books" << endl;
        cout << "3. Delete book" << endl;
        cout << "4. Exit" << endl;
        cout << "=============================" << endl;
        cout << "Enter choice (1-4): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (books.size() >= n)
            {
                cout << "The library is full " << endl;
                break;
            }
            cout << "\n Adding book" << books.size() + 1 << "===" << endl;
            {
                book newbook;
                newbook.Addbook(books.size() + 1);
                books.push_back(newbook);
            }
            break;
        case 2:
            cout << "Books...." << endl;
            if (books.empty())
            {

                cout << "No books in the library" << endl;
                break;
            }
            for (size_t i = 0; i < books.size(); i++)
            {

                books[i].Display();
            }
            break;
        case 3:
            if (books.empty())
            {

                cout << "No books to delete" << endl;
                break;
            }
            int del;
            cout << "Enter the number of book to delete: ";
            cin >> del;
            if (del >= 1 && del <= static_cast<int>(books.size()))
            {
                books.erase(books.begin() + del - 1);
                cout << "Book deleted successfully!" << endl;
            }
            else
            {
                cout << "Invalid book number!" << endl;
            }
            break;
        case 4:
            cout << "Thank you for using Library Management System!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}