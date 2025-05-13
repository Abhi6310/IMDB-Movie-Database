#ifndef __MOVIE_NODE_HPP__
#define __MOVIE_NODE_HPP__

#include <iostream>
#include <string>
using namespace std;

struct MovieNode {
    int rank;
    string title;
    string genre;
    string description;
    string director;
    string actors;
    int year;
    int runtime;
    float rating;
    int votes;
    float revenue;
    int metascore;

    MovieNode* next;

    MovieNode() : 
        rank(0), title(""), genre(""), description(""), director(""), actors(""),
        year(0), runtime(0), rating(0.0f), votes(0), revenue(0.0f), metascore(0),
        next(nullptr) {}

    MovieNode(int _rank, string _title, string _genre, string _desc, 
              string _dir, string _actors, int _year, int _runtime, float _rating, 
              int _votes, float _revenue, int _metascore) {
        rank = _rank;
        title = _title;
        genre = _genre;
        description = _desc;
        director = _dir;
        actors = _actors;
        year = _year;
        runtime = _runtime;
        rating = _rating;
        votes = _votes;
        revenue = _revenue;
        metascore = _metascore;
        next = nullptr;
    }

    void displaySummary() const {
        cout << "Title: " << title << " (" << year << ")" << endl;
        cout << "Director: " << director << endl;
        cout << "Rating: " << rating << "/10 (Votes: " << votes << ")" << endl;
    }

    void displayDetails() const {
        displaySummary();
        cout << "Genre: " << genre << endl;
        cout << "Runtime: " << runtime << " minutes" << endl;
        cout << "Actors: " << actors << endl;
        cout << "Revenue: $" << revenue << "M" << endl;
        cout << "Metascore: " << metascore << "/100" << endl;
        cout << "Description: " << description << endl;
    }

    bool operator<(const MovieNode& other) const {
        return rating < other.rating;
    }

    bool compareByTitle(const MovieNode& other) const {
        return title < other.title;
    }

    bool compareByYear(const MovieNode& other) const {
        return year < other.year;
    }
};

inline std::ostream& operator<<(std::ostream& os, const MovieNode& movie) {
    os << movie.title << " (" << movie.year << "), Dir: " << movie.director 
       << ", Rating: " << movie.rating;
    return os;
}

#endif