#include<iostream>
#include<string>
using namespace std;

class Productinventory{
private:
int Id;
string Productname;
int Quantity;
double Price;

public:
 int getId() const {
        return Id;
    }
Productinventory(){
    Id=0;
    Productname="";
    Quantity= 0;
    Price= 0;
}

void Addproduct(){
    cout<<"Enter the product id: "<<endl;
    cin>>Id;
    cout<<"Enter the product name: "<<endl;
    cin>>Productname;
    cout<<"Enter the quantity of product: "<<endl;
    cin>>Quantity;
    cout<<"Enter the price of product: "<<endl;
    cin>>Price;
   }
void Display(){
    cout<<"Product id: "<<Id<<endl;
    cout<<"Product: "<<Productname<<endl;
    cout<<"Quantity: "<<Quantity<<endl;
    cout<<"Price: "<<Price<<endl;
}
void Updateproduct(int temp){
    int newquantity;
    if(Id==temp){
        cout<<"Enter the Quantity: "<<endl;
        cin>>newquantity;
        Quantity=newquantity;
    }
    else{
        cout<<"Enter a valid id!!"<<endl;
    }
}
void Searchproduct()
{
    int id;
    cout<<"Enter the id to search: "<<endl;
    cin>>id;
    if(id==Id){
        cout<<"Product found: "<<endl;
        cout<<"Product id: "<<Id<<endl;
        cout<<"Product: "<<Productname<<endl;
        cout<<"Quantity: "<<Quantity<<endl;
        cout<<"Price: "<<Price<<endl; 
             }
}
   void Deleteproduct() {
        cout << "\n=== Deleting Product ===" << endl;
        cout << "Product ID: " << Id << endl;
        cout << "Product Name: " << Productname << endl;
        
     
        
            Id = 0;
            Productname = "";
            Quantity = 0;
            Price = 0;
            cout << "Product deleted successfully!" << endl;
        
    }
};
int main(){
    int id=0;
    int choice=0;
    int n;
    
    // cout<<"Enter the number of product"<<endl;
    // cin>>n;
    Productinventory a1[10];
    do{
         cout << "\n=== Inventory Management System ===" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Search Product" << endl;
        cout << "5. Delete Product" << endl;
        cout << "6. Exit" << endl;
        cout << "=================================" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
    switch(choice){
        case 1:
        cout<<"Add product: "<<endl;
        a1[id].Addproduct();
        id++;        
        break;
        case 2:
         if (id == 0) {
                    cout << "No products in inventory!" << endl;
                    break;
                }
                cout << "\n=== Product List ===" << endl;
                for (int i = 0; i < id; i++) {
                    cout << "\nProduct #" << (i + 1) << endl;
                    cout << "---------------" << endl;
                    a1[i].Display();
                }
                break;

        case 3:
          if (id == 0) {
                    cout << "No products to update!" << endl;
                    break;
                }
                int temp;
                cout << "Enter product ID to update: ";
                cin >> temp;
                for (int i = 0; i < id; i++) {
                    a1[i].Updateproduct(temp);
                }
        break;
        case 4:
          if (id == 0) {
                    cout << "No products to search!" << endl;
                    break;
                }
                for (int i = 0; i < id; i++) {
                    a1[i].Searchproduct();
                }
                break;
        case 5:
            
            int deleteId;
            cout << "Enter product ID to delete: ";
            cin >> deleteId;
            
            for(int i = 0; i < id; i++) {
                if(a1[i].getId() == deleteId) {
                    a1[i].Deleteproduct();
                    // Shift remaining products
                    for(int j = i; j < id - 1; j++) {
                        a1[j] = a1[j + 1];
                    }
                    id--;
                    break;
                }
            }
            break;
        case 6:
         cout << "Thank you for using the system!" << endl;
                return 0;
        break;
 default:
                cout << "Invalid choice! Please try again." << endl;
        

    }
}while(choice !=6);
return 0;
}