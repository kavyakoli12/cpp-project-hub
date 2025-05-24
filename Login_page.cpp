#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void Register(string &username, string &password);
int login(const string &username,const string &password);
void forget();
int main()
{
    string username;
    string password;
    int choice;

    do
    {
        cout << "====================" << endl;
        cout << "Welcome to the page" << endl;
        cout << "====================" << endl;

        cout << "1. Register " << endl;
        cout << "2. login " << endl;
        cout << "3. forget " << endl;
        cout << "4. exit " << endl;
        cout << "Enter number(1-4) " << endl;
        cin >> choice;
        if (choice > 0 && choice <= 4)
        {

            switch (choice)
            {
            case 1:
                Register(username, password);
                break;
            case 2:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
                if (login(username, password))
                {
                    cout << "Login successfull!" << endl;
                }
                else
                {
                    cout << "Login failed!" << endl;
                }

                break;
            case 3:
                forget();
                break;
            case 4:
                cout << "Thank you for ussing our service!" << endl;
                break;
            default:
                cout << "Invalid choice! try again" << endl;
            }
        }
    } while (choice != 4);
    return 0;
}
void Register(string &username, string &password)
{
    cout << "Enter username (Case sensitive) " << endl;
    cin >> username;
    cout << "Enter password (Case sensitive) " << endl;
    cin >> password;
    ofstream file("login.txt", ios::app);
    if (file.is_open())
    {
        file << username << " " << password<<endl;
        file.close();
        cout << "registration complete" << endl;
    }
    else
    {
        cout << "error: unable to create file" << endl;
    }
}
int login(const string &username, const string &password)
{
    string fileuser, filepass;
    ifstream file("login.txt");


    if(file.is_open()){
      while (file >> fileuser >> filepass) {
    if (username == fileuser && password == filepass) {
        file.close();
        return 1;
    }
}
 file.close();   
}
        return 0;
}
void forget()
{
     string username, fileuser, filepass;
    bool found = false;
    cout << "Enter the username to recover the password: ";
    cin >> username;

    ifstream file("login.txt");
    if (file.is_open()) {
        while (file >> fileuser >> filepass) {
            if (username == fileuser) {
                cout << "Your password is: " << filepass << endl;
                found = true;
                break;
            }
        }
        file.close();

        if (!found) {
            cout << "Username not found.\n";
        }
    } else {
        cout << "Error: Unable to open file.\n";
    }
}
