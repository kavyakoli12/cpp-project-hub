#include <iostream>
#include <string>
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
    book b1[100];
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
            if (id > n)
            {
                cout << "The library is full " << endl;
                break;
            }
            cout << "Adding book...." << endl;
            b1[id - 1].Addbook(id);
            id++;

            break;
        case 2:
            cout << "Books...." << endl;
            for (int i = 0; i < n; i++)
            {
                b1[i].Display();
            }
            break;
        case 3:
            int del;
            cout << "Enter the number of book to delete: ";
            cin >> del;
            if (del >= 1 && del <= n)
            {
                b1[del - 1].deletebook();
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