#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Contact{
private:
string Name;
string Phoneno;
string Email;
public:
Contact() {}
Contact(string name,string phoneno,string email){
    Name=name;
    Phoneno=phoneno;
    Email=email;
}
string getname(){
    return Name;
}
string getphoneno(){
    return Phoneno;
}
string getemail(){
    return Email;
}
void display(){
    cout<<"Name: "<<Name<<endl;
    cout<<"Number: "<<Phoneno<<endl;
    cout<<"Email: "<<Email<<endl;
}
void loadFromFile(ifstream &ifs) {
        getline(ifs, Name);
        getline(ifs, Phoneno);
        getline(ifs, Email);}
};
vector <Contact> contacts;

void addContact(){
string name,phoneno,email;
cout<<"Enter Name: "<<endl;
cin.ignore();
getline(cin,name);
cout<<"Enter number: "<<endl;
getline(cin,phoneno);
cout<<"Enter Email: "<<endl;
getline(cin,email);
contacts.push_back(Contact(name,phoneno,email));
cout << "Contact added successfully!\n";
}
void deleteContact(){
     string query;
    cout << "Enter name or phone to delete: ";
    cin.ignore();
    getline(cin, query);

    int index = -1;
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getname() == query || contacts[i].getphoneno() == query) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        contacts.erase(contacts.begin() + index);
        cout << "Contact deleted.\n";
    } else {
        cout << "Contact not found.\n";
    }
};
void searchContact(){
  string query;
    cout << "Enter name or phone to search: ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getname() == query || contacts[i].getphoneno() == query) {
            contacts[i].display();
            found = true;
        }
    }
    if (!found) cout << "Contact not found.\n";
    
    
}
void savecontacttofile(){
      ofstream ofs("contacts.txt");
    int i = 0;
    while (i < contacts.size()) {
        ofs << contacts[i].getname() << endl;
        ofs << contacts[i].getphoneno() << endl;
        ofs << contacts[i].getemail() << endl;
        i++;
    }
    ofs.close();
    cout << "Contacts saved to file.\n";

}
void loadcontactfromfile(){
 ifstream ifs("contacts.txt");
    if (!ifs) return;

    while (ifs.peek() != EOF) {
        Contact c;
        c.loadFromFile(ifs);
        if (!c.getname().empty())
            contacts.push_back(c);
    }
    ifs.close();
}

int main() {
    int choice;
    loadcontactfromfile();

    do {
        cout << "\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Save Contacts\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                savecontacttofile();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}