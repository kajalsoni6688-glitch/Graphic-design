#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;
    cout << "===== Guess the Number Game =====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;
        if (guess > secretNumber) {
            cout << "Too High! Try Again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too Low! Try Again." << endl;
        }
        else {
            cout << "\nCongratulations! You guessed the correct number." << endl;
            cout << "The number was: " << secretNumber << endl;
            cout << "Total Attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    return 0;
}