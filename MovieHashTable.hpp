#ifndef __MOVIE_HASH_TABLE_HPP__
#define __MOVIE_HASH_TABLE_HPP__

#include <iostream>
#include <string>
#include "MovieNode.hpp"
using namespace std;

#define DEFAULT_HTABLE_CAPACITY 2000

class MovieHashTable {
    private:
        int table_size;
        MovieNode** table;
        int n_collisions;

    public:
        MovieHashTable();
        MovieHashTable(int s);
        ~MovieHashTable();
        MovieHashTable(const MovieHashTable&) = delete;
        MovieHashTable& operator=(const MovieHashTable&) = delete;

        void insert(const string& title, MovieNode* movie);
        MovieNode* search(const string& title) const;
        int getCollisions() const;
        void incrementCollisions();
        int getTableSize() const { return table_size; }

    private:
        int hash(const string& title) const;
};

#endif