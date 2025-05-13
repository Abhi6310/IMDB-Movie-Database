#include<iostream>
#include <vector>
#include "MovieHashTable.hpp"
using namespace std;

MovieHashTable::MovieHashTable() {
    table_size = DEFAULT_HTABLE_CAPACITY;
    table = new MovieNode*[table_size]();
    n_collisions = 0;
}

MovieHashTable::MovieHashTable(int s) {
    table_size = s;
    table = new MovieNode*[table_size]();
    n_collisions = 0;
}

MovieHashTable::~MovieHashTable() {
    for(int i = 0; i < table_size; i++){
        MovieNode* current = table[i];
        while(current){
            MovieNode* next = current->next;
            delete current;
            current = next;
        }
    }
    delete [] table;
}

int MovieHashTable::hash(const string& title) const {
    //identikey is abch4744
    int value = 4744;
    for(int i = 0; i < title.size(); i++){
        value = (value * 23 + title[i]) % table_size;
    }
    value = (value * ('a' * 'b' * 'c' * 'd')) % table_size;
    return value;
}

void MovieHashTable::insert(const string& title, MovieNode* movie) {
    int index = hash(title);

    if(!table[index]){
        table[index] = movie;
    } else {
        incrementCollisions();
        MovieNode* current = table[index];
        while(current->next){
            current = current->next;
        }
        current->next = movie;
    }
}

MovieNode* MovieHashTable::search(const string& title) const {
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

int MovieHashTable::getCollisions() const {
    return n_collisions;
}

void MovieHashTable::incrementCollisions() {
    n_collisions++;
}