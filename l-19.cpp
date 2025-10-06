// COMSC-210 | Lab 19 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>

using namespace std;

struct Node // Node structure for linked list
{
    double rating; // Rating (1.0-5.0)
    string review; // User review
    Node *next; // Pointer to the next node
};

class Movie
{
    private:
        string title; // Movie title
        string review; // Movie review
        double rating; // Movie rating

    public:
        Movie(string t, string rev, double rat) 
        {
            title = t;
            review = rev;
            rating = rat;
        }

        void displayInfo() 
        {
            cout << "Title: " << title << endl;
            cout << "Review: " << review << endl;
            cout << "Rating: " << rating << endl;
        }
};

int main() 
{
    cout << endl;
    return 0;
}