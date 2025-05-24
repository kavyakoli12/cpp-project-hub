#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class student{
private:
    string Name;
    string Id;
    int Attendance;
 public:
 student(string id ,string name ,int attendance=0){
    Id=id;
    Name=name;
    Attendance=attendance;
 }
string getname(){
    return Name;
}
string getid(){
    return Id;
}
int getattendance(){
    return Attendance;
}
 void markPresent() {
     Attendance++;
 }
void display()  {
  cout << "Roll No: " << Id << ", Name: " << Name << ", Attendance: " << Attendance << endl;
}

};
vector <student> students;
void addstudent(){
string name,id;

cout<<"Enter the id of student: "<<endl;
cin.ignore();
getline(cin,id);

cout<<"Enter the name of student: "<<endl;
getline(cin,name);

students.push_back(student(id,name));
cout << "Student added successfully!\n";

}   
void markPresent(){
     if (students.empty()) {
        cout << "No students available to mark attendance.\n";
        return;
    }

    cout << "List of Students:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". " << students[i].getid() << " - " << students[i].getname() << endl;
    }

    int choice;
    cout << "Enter the number of the student to mark present: ";
    cin >> choice;

    if (choice >= 1 && choice <= students.size()) {
        students[choice - 1].markPresent();
        cout << "Attendance marked for " << students[choice - 1].getname() << ".\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

void viewReport() {
    if (students.empty()) {
        cout << "No students to show.\n";
        return;
    }
    cout << "\nAttendance Report:\n";
    for (int i=0;i<students.size();i++) {
       students[i].display();
    }
    cout << endl;
}
int main(){
int choice;
    do {
        cout << "\n1. Add Student\n2. Mark Attendance\n3. View Report\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addstudent();
                break;
            case 2:
                markPresent();
                break;
            case 3:
                viewReport();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}