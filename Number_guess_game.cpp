#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    int guess;
    int Attempts=0;
    int Maxattempts=10;

 srand(static_cast<unsigned int>(time(0)));
 int Randomnumber=rand()%100+1;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Guess the number (between 1 and 100): \n";
do{
    cout << "Enter your guess: ";
    cin >> guess;
    Attempts++;
if(guess>Randomnumber){
    cout<<"The is too high! Try again!"<<endl;
}
else if(guess<Randomnumber)
{
cout<<"The number is too low  !  Try again!"<<endl;
}
else {
            cout << "Congratulations! You guessed the number in " << Attempts << " attempts.\n";
            break;
        }
if(Attempts==Maxattempts){
     cout << "You've reached the maximum number of attempts. The number was: " << Randomnumber << endl;

    break;
}
}while(guess !=Randomnumber);
cout<<"Game end!!"<<endl;
return 0;
}