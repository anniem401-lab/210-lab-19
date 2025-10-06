// COMSC-210 | Lab 19 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int W15 = 15;

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
// Getters and Setters
string getTitle()               { return title; }
void setTitle(string t)     { title = t; }

string getReview()              { return review; }
void setReview(string r)    { review = r; }

double getRating()              { return rating; }
void setRating(double r)    { rating = r; }

// Print method to display movie information 
void print() 
{
    cout << setw(W15) << "Title: " << title << endl;
    cout << setw(W15) << "Review: " << review << endl;
    cout << setw(W15) << "Rating: " << rating << endl;
}
};

void print(Movie);

int main() 
{
    cout << endl;
    return 0;
}