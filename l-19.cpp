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
};

void print(Movie);

int main() 
{
    // Movie objects (4 total)
    cout << endl << "----------------------------";
    cout << endl << " Movie 1 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m1;
    m1.setTitle("Paranorman");

    cout << endl << "----------------------------" << endl;
    cout << " Movie 2 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m2;
    m2.setTitle("The Incredibles");

    cout << endl << "----------------------------" << endl;
    cout << " Movie 3 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m3;
    m3.setTitle("Coraline");

    cout << endl << "----------------------------" << endl;
    cout << " Movie 4 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m4;
    m4.setTitle("Takeout");

    cout << endl;
    return 0;
}

void print(Movie m) 
{
    cout << setw(W15) << "Title: " << m.getTitle() << endl;
    cout << setw(W15) << "Review: " << m.getReview() << endl;
    cout << setw(W15) << "Rating: " << m.getRating() << endl;
}