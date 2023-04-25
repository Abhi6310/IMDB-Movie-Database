#ifndef __MOVIE_HASH_TABLE_HPP__  // include guard to prevent multiple inclusions of this file
#define __MOVIE_HASH_TABLE_HPP__

#include <iostream>
#include "MovieNode.hpp"
using namespace std;

#define DEFAULT_HTABLE_CAPACITY 2000

// A hash table for storing movie nodes
class MovieHashTable {
    private:
        int table_size;      // the number of slots in the hash table
        MovieNode** table;   // an array of pointers to movie nodes
        int n_collisions;    // the number of collisions that have occurred

    public:
        // Default constructor that sets the table size to a default value
        MovieHashTable();

        // Constructor that allows the table size to be specified
        MovieHashTable(int s);

        // Destructor that deletes all movie nodes in the table
        ~MovieHashTable();

        // Inserts a movie node into the hash table
        void insert(string title, MovieNode* movie);

        // Searches for a movie node in the hash table with the specified title
        MovieNode* search(string title);

        // Returns the number of collisions that have occurred
        int getCollisions();

        // Increments the number of collisions that have occurred
        void setCollisions();

    private:
        // Hash function for MovieHashTable that returns an index in the hash table for a given movie title.
        // Students must use their identikey to come up with a creative hash function that minimizes collisions
        // for the given IMDB-Movie database to ensure efficient insertion and retrieval of movie nodes.
        int hash(string title);
};

#endif //__MOVIE_HASH_TABLE_HPP__