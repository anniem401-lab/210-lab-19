// COMSC-210 | Lab 19 | Annie Morales
// IDE used: Visual Studio Code

// This program collects data to be implemented into a linked list where
// each node contains a movie title, review, and rating. New nodes are
// added to the front of the list. The program displays the movie data
// from the linked list. Each movie has three reviews and random ratings
// between 1.0 and 5.0.

#include <fstream> // For file handling
#include <iostream> // For input/output
#include <iomanip> // For formatted output
#include <string> // For string handling
#include <vector> // For using vectors
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

// Function prototypes
void print(Movie); // Function to print movie details
void outputList(Node *); // Function to output the linked list
void addNode(Node *&, string, string, double); // Function to add a node to the list
void deleteList(Node *&); // Function to delete the linked list

int main() 
{
    srand(time(0)); // Seed for random number generation
    vector<Movie> movieReviews; // Vector to hold Movie objects

    // Read movie reviews from a file
    ifstream fin;
    fin.open("moviereviews.txt");

    // Checks if file opened successfully
    if (!fin.good()) throw "I/O error";

    // Reads movie reviews from the file and stores them in the vector
    string reviews;
    while (getline(fin, reviews))
    {
        Movie m;
        m.setReview(reviews);
        m.setRating((rand() % 50 + 10) / 10.0); // Random rating between 1.0 and 5.0
        movieReviews.push_back(m);
    }
    fin.close(); // Close the file

    // Reopen the file to read movie review line by line
    fin.open("moviereviews.txt");
    if (!fin.good()) throw "I/O error";

    while (!fin.eof()) 
    {
        Movie m;
        string reviews;
        getline(fin, reviews);

        if (!getline(fin, reviews)) break; // Break if no more lines

        // Read movie reviews and assign 3 reviews to each Movie object
        for (size_t i = 0; i < movieReviews.size(); i++) 
        {
            if (movieReviews[i].getReview().empty()) 
            {
                movieReviews[i].setReview(reviews);
                break; // Assign review to the first Movie object without a review
            }
        }

        if (movieReviews.size() >= 3) break; // Limit to 3 reviews
    }
    fin.close(); // Close the file

    // Movie objects (4 total) with three reviews each and a random rating
    cout << endl << "----------------------------";
    cout << endl << " Movie 1 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m1;
    m1.setTitle("Paranorman");
    // Assign reviews and ratings from the vector
    for (size_t i = 0; i < 3 && i < movieReviews.size(); i++) 
    {
        m1.setReview(movieReviews[i].getReview());
        m1.setRating(movieReviews[i].getRating());
        print(m1); // Print movie details
        cout << endl;
    }

    cout << endl << "----------------------------" << endl;
    cout << " Movie 2 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m2;
    m2.setTitle("The Incredibles");
    // Assign reviews and ratings from the vector
    for (size_t i = 3; i < 6 && i < movieReviews.size(); i++) 
    {
        m2.setReview(movieReviews[i].getReview());
        m2.setRating(movieReviews[i].getRating());
        print(m2); // Print movie details
        cout << endl;
    }

    cout << endl << "----------------------------" << endl;
    cout << " Movie 3 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m3;
    m3.setTitle("Coraline");
    // Assign reviews and ratings from the vector
    for (size_t i = 6; i < 9 && i < movieReviews.size(); i++) 
    {
        m3.setReview(movieReviews[i].getReview());
        m3.setRating(movieReviews[i].getRating());
        print(m3); // Print movie details
        cout << endl;
    }

    cout << endl << "----------------------------" << endl;
    cout << " Movie 4 Details ";
    cout << endl << "----------------------------" << endl;
    Movie m4;
    m4.setTitle("Takeout");
    // Assign reviews and ratings from the vector
    for (size_t i = 9; i < 12 && i < movieReviews.size(); i++) 
    {
        m4.setReview(movieReviews[i].getReview());
        m4.setRating(movieReviews[i].getRating());
        print(m4); // Print movie details
        cout << endl;
    }
    // Calls outputlist function to display the linked list
    Node *head = nullptr; // Initialize head of the linked list
    // Add nodes to the linked list for each movie review
    outputList(head); // Output the linked list
    cout << endl;
    return 0;
}

void print(Movie m) 
{
    cout << setw(W15) << "Title: " << m.getTitle() << endl;
    cout << setw(W15) << "Review: " << m.getReview() << endl;
    cout << setw(W15) << "Rating: " << m.getRating() << endl;
}

void outputList(Node *head) 
{
    Node *current = head; // Pointer to traverse the list
    cout << endl << "Movie List:" << endl;
    cout << "----------------------------" << endl;

    // Traverse the list and print all reviews and ratings
    while (current != nullptr)  
    {
        cout << "Review: " << current->review << endl;
        cout << "Rating: " << current->rating << endl;
        cout << "----------------------------" << endl;
        current = current->next; // Move to the next node
    }
}

void addNode(Node *&head, string review, string title, double rating) 
{
    Node *newNode = new Node; // Create a new node
    newNode->review = review; // Set the review
    newNode->rating = rating; // Set the rating
    newNode->next = head; // Point new node to the current head
    head = newNode; // Update head to the new node
}

void deleteList(Node *&head) 
{
    Node *current = head; // Pointer to traverse the list
    Node *nextNode; // Pointer to hold the next node

    // Traverse the list and delete each node
    while (current != nullptr) 
    {
        nextNode = current->next; // Store the next node
        delete current; // Delete the current node
        current = nextNode; // Move to the next node
    }
    head = nullptr; // Set head to nullptr after deletion
    cout << "Linked list deleted." << endl;
}