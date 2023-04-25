#ifndef __MOVIE_NODE_HPP__ // include guard to prevent multiple inclusions of this 
#define __MOVIE_NODE_HPP__

#include<iostream>
using namespace std;

// A struct representing a node for storing movie information
struct MovieNode {
    int rank;           // the movie's rank in the database
    string title;       // the movie's title
    string genre;       // the movie's genre
    string description; // a brief description of the movie
    string director;    // the name of the movie's director
    string actors;      // the names of the movie's actors
    int year;           // the year the movie was released
    int runtime;        // the movie's runtime in minutes
    float rating;       // the movie's average rating (out of 10)
    int votes;          // the number of votes the movie has received
    float revenue;      // the movie's total revenue in Millions
    int metascore;      // the movie's metascore (out of 100)

    MovieNode* next;    // a pointer to the next node in the linked list

    // Default constructor (does nothing)
    MovieNode() {}

    // Constructor that initializes all fields of the node
    MovieNode(int _rank, string _title, string _genre, string _desc, 
    string _dir, string _actors, int _year, int _runtime, float _rating, 
    int _votes, float _revenue, int _metascore) {
        rank = _rank;
        title = _title;
        genre = _genre;
        description =  _desc;
        director = _dir;
        actors = _actors;
        year = _year;
        runtime = _runtime;
        rating = _rating;
        votes = _votes;
        revenue = _revenue;
        metascore = _metascore;

        next = nullptr; // initialize the next pointer to nullptr
    }

};

#endif // __MOVIE_NODE_HPP__