#include<iostream>
#include<iomanip>

using namespace std;

int main(){
int n;
cout<<"Enter number of items:"<<endl;
cin>>n;
string itemname[100];
double price[100];
int quantity[100];
double total=0.0;
double itemtotal[100];
float tax=0.18;
for(int i=0;i<n;i++){
cout<<"Enter the name of item: "<<endl;
cin>>itemname[i];
cout<<"Enter the quantity of item: "<<endl;
cin>>quantity[i];
cout<<"Enter the price of item: "<<endl;
cin>>price[i];
itemtotal[i]=quantity[i] * price[i];
total=total+itemtotal[i];
}
float taxtotal=total*tax;
float grandtotal=total+taxtotal;
cout << fixed << setprecision(2);
    cout << "\n===== BILL =====\n";
    cout << left << setw(15) << "Item" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total" << endl;
for(int i=0;i<n;i++){
cout<<left<<setw(15)<<itemname[i]
<<setw(10)<<quantity[i]
<<setw(10)<<price[i]
<<setw(10)<<itemtotal[i]<<endl;
}
cout << "-----------------------------\n";
    cout << "Subtotal: Rs. " << total << endl;
    cout << "Tax (18%): Rs. " << taxtotal << endl;
    cout << "Grand Total: Rs. " << grandtotal << endl;

    return 0;

}