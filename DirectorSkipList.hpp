#ifndef __DIRECTOR_SKIP_LIST_HPP__  // include guard to prevent multiple inclusions of this file
#define __DIRECTOR_SKIP_LIST_HPP__

#include<iostream>
#include <vector>
using namespace std;

#include "MovieNode.hpp"

#define DEFAULT_LEVELS 10
#define DEFAULT_CAPACITY 2000

// A node in a skip list for storing movie nodes sorted by director
struct DirectorSLNode {
  string director;             // the director's name
  vector<MovieNode*> movies;   // a vector of pointers to movie nodes with this director
  vector<DirectorSLNode*> next;// a vector of pointers to the next nodes at each level

  // Default constructor that sets the director name to "noname"
  DirectorSLNode() {director = "noname";}

  // Constructor that sets the director name and initializes the next vector with the specified number of levels
  DirectorSLNode(string _director, int levels) {
    director = _director;
    next = vector<DirectorSLNode*>(levels, nullptr);
  }

  // Adds a movie to the vector of movies, checking for duplicates
  void addMovie(MovieNode* _movie) {
    for (auto movie: movies) {
        if (movie->title == _movie->title) {
            cout << "Duplicate movie! Skipped" << endl;
            return;
        }
    }
    movies.push_back(_movie);
  }
};

// A skip list for storing movie nodes sorted by director
class DirectorSkipList {
    private:
        int capacity;           // the maximum capacity of the skip list
        int levels;             // the maximum number of levels in the skip list
        DirectorSLNode* head;   // a pointer to the head node of the skip list
        int size;               // the current size of the skip list

    public:
        // Default constructor that sets the capacity and levels to default values
        DirectorSkipList();

        // Constructor that allows the capacity and levels to be specified
        DirectorSkipList(int _cap, int _levels);

        // Destructor that deletes all nodes in the skip list (but not the MovieNodes, which are shared with other data structures)
        ~DirectorSkipList();

        // Inserts a movie node into the skip list with the specified director
        void insert(string director, MovieNode* _movie);

        // Searches for a node in the skip list with the specified director
        DirectorSLNode* search(string director);

        // Pretty-prints the skip list
        void prettyPrint();
};

#endif // __DIRECTOR_SKIP_LIST_HPP__
