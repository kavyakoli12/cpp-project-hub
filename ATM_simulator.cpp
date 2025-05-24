#include <iostream>
#include <string>
#include <fstream>  

using namespace std;
void checkBalance();
void depositMoney();
void withdrawMoney();

int main()
{

    int choice;
    do
    {
        cout << "\n====== ATM Simulator ======\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            cout << "Thank you for using the ATM.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
void checkBalance()
{
    int balance;
    ifstream file("ATM.txt");
    file >> balance;
    file.close();
    cout << "Your current balance is: " << balance << endl;
}
void depositMoney()
{
    int balance;
    int deposite;
    ifstream file("ATM.txt");
    file >> balance;
    file.close();
    cout << "Eneter the amount to deposite: " << endl;
    cin >> deposite;
