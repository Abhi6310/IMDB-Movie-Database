#include<iostream>
#include <vector>
#include "MovieHashTable.hpp"
using namespace std;

// Constructor for MovieHashTable with default size
MovieHashTable::MovieHashTable() {
    // TODO
}

// Constructor for MovieHashTable with given size
MovieHashTable::MovieHashTable(int s) {
    // TODO
}

// Destructor for MovieHashTable that deletes all nodes in the hash table
MovieHashTable::~MovieHashTable() {
    // TODO
}

// Hash function for MovieHashTable that returns an index in the hash table for a given movie title.
// Students must use their identikey to come up with a creative hash function that minimizes collisions
// for the given IMDB-Movie database to ensure efficient insertion and retrieval of movie nodes.
int MovieHashTable::hash(string title) {
    // TODO
    return 0;
}

// Inserts a movie node into the hash table with the specified title
void MovieHashTable::insert(string title, MovieNode* movie) {
    // TODO
}

// Searches for a node in the hash table with the specified title
MovieNode* MovieHashTable::search(string title) {
    // TODO
    return nullptr;
}

// Returns the number of collisions that have occurred during insertion into the hash table
int MovieHashTable::getCollisions() {
    // TODO
    return 0;
}

// Increments the number of collisions that have occurred during insertion into the hash table
void MovieHashTable::setCollisions() {
    // TODO
}
