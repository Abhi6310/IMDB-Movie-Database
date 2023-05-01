#include<iostream>
#include <vector>
#include "MovieHashTable.hpp"
using namespace std;

// Constructor for MovieHashTable with default size
MovieHashTable::MovieHashTable() {
    // TODO
    table_size = DEFAULT_HTABLE_CAPACITY;
    table = new MovieNode*[table_size]();
    n_collisions = 0;
}

// Constructor for MovieHashTable with given size
MovieHashTable::MovieHashTable(int s) {
    // TODO
    table_size = s;
    table = new MovieNode*[table_size]();
    n_collisions = 0;
}

// Destructor for MovieHashTable that deletes all nodes in the hash table
MovieHashTable::~MovieHashTable() {
    // TODO
    for(int i = 1; i < table_size; i++){
        MovieNode* current = table[i];
        while(current){
            MovieNode* next = current->next;
            delete current;
            current = next;
        }
    }
    delete [] table;
}

// Hash function for MovieHashTable that returns an index in the hash table for a given movie title.
// Students must use their identikey to come up with a creative hash function that minimizes collisions
// for the given IMDB-Movie database to ensure efficient insertion and retrieval of movie nodes.
int MovieHashTable::hash(string title) {
    // TODO identikey is abch4744, so I opted to separate the numbers and characters
    int value = 4744;
    for(int i = 0; i< title.size();i++){
        value = (value * 23 + title[i])% table_size;
    }
    value = (value * ('a' * 'b' * 'c' * 'd')) % table_size;
    return value;
}

// Inserts a movie node into the hash table with the specified title
void MovieHashTable::insert(string title, MovieNode* movie) {
    // TODO
    int index = hash(title);

    if(!table[index]){
        table[index] = movie;
    } else {
        //Collision Occured (chaining)
        n_collisions++;
        MovieNode* current = table[index];
        while(current->next){
            current = current->next;
        }
        current->next = movie;
    }
}

// Searches for a node in the hash table with the specified title
MovieNode* MovieHashTable::search(string title) {
    // TODO
    int index = hash(title);
    MovieNode* current = table[index];
    while (current) {
        if (current->title == title) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Returns the number of collisions that have occurred during insertion into the hash table
int MovieHashTable::getCollisions() {
    // TODO
    return n_collisions;
}

// Increments the number of collisions that have occurred during insertion into the hash table
void MovieHashTable::setCollisions() {
    // TODO
    n_collisions++;
}
