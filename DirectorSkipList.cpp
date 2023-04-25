#include<iostream>
#include <vector>
#include "DirectorSkipList.hpp"
using namespace std;

// Constructor for DirectorSkipList with default capacity and levels
DirectorSkipList::DirectorSkipList() {
    // TODO
}

// Constructor for DirectorSkipList with given capacity and levels
DirectorSkipList::DirectorSkipList(int _cap, int _levels) {
    // TODO
}

// Destructor for DirectorSkipList that deletes all nodes in the skip list (but not the MovieNodes, which are shared with other data structures)
DirectorSkipList::~DirectorSkipList() {
    // TODO
}

// Inserts a movie node into the skip list with the specified director
void DirectorSkipList::insert(string director, MovieNode* _movie) {
    // TODO
}

// Searches for a node in the skip list with the specified director
DirectorSLNode *DirectorSkipList::search(string director) {
    // TODO
    return nullptr;
}

// Pretty-prints the skip list
void DirectorSkipList::prettyPrint() {
    // TODO
}
