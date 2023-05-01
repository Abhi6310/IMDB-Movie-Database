#include<iostream>
#include <vector>
#include "DirectorSkipList.hpp"
using namespace std;

// Constructor for DirectorSkipList with default capacity and levels
DirectorSkipList::DirectorSkipList() {
    // TODO
    capacity = DEFAULT_CAPACITY;
}

// Constructor for DirectorSkipList with given capacity and levels
DirectorSkipList::DirectorSkipList(int _cap, int _levels) {
    // TODO
    srand(time(0));
    capacity = _cap;
    levels = _levels;
}

// Destructor for DirectorSkipList that deletes all nodes in the skip list (but not the MovieNodes, which are shared with other data structures)
DirectorSkipList::~DirectorSkipList() {
    // TODO
    DirectorSLNode* current = head->next[0];
    while(current){
        DirectorSLNode* nextNode = current->next[0];
        current->next.clear();
        current = nextNode;
    }
    head->next.clear();
}
//This function generates a random integer that is less than the total amount of levels and returns it back to the function to use in adding to the skip list
int DirectorSkipList::generateRandomLevel(){
    int lvl = 1;
    while ((rand()%2) && (lvl < levels)){
        lvl++;
    }
    return lvl;
}
// Inserts a movie node into the skip list with the specified director
void DirectorSkipList::insert(string director, MovieNode* _movie) {
    // TODO
    //Determine Levels
    int n_levels = generateRandomLevel();
    //Create new node
    DirectorSLNode* newNode = new DirectorSLNode(director, n_levels);
    newNode->movies.push_back(_movie);

    //Keep track of previous pointers
    vector <DirectorSLNode*> prevNode(levels,nullptr);
    DirectorSLNode* current = head;
    for (int i = levels - 1; i >= 0; i--) {
        // Move forward in the current level until the next node's director is greater than the given director
        while (current->next[i] && current->next[i]->director < director) {
            current = current->next[i];
        }
        // Remember the previous pointer at the current level
        prevNode[i] = current;
    }
    // current = current->next[0];
    // if(current != nullptr && current->director == director){
    //     current->movies.push_back(_movie);
    // } else {
    //Insert new node
    for (int i = 0; i < n_levels; i++) {
        newNode->next[i] = prevNode[i]->next[i];
        prevNode[i]->next[i] = newNode;
    // }
    }
}

// Searches for a node in the skip list with the specified director
DirectorSLNode *DirectorSkipList::search(string director) {
    // TODO
    DirectorSLNode* current = head;
    for(int i = levels - 1; i >= 0;i--){
        while(current->next[i] && current->next[i]->director < director){
            current = current->next[i]; 
        }
    }
    current= current->next[0];
    if(current && current->director == director){
        return current;
    }
    return nullptr;
}

// Pretty-prints the skip list
void DirectorSkipList::prettyPrint() {
    // TODO
    for(int i = levels - 1; i >= 0;i--){
        DirectorSLNode* current = head->next[i];
        cout << "Level " << i << ": ";
        
        while(current){
            cout << current->director << " (" << current->movies.size() << " movies)";
            if(current->next[i]){
                cout << " -> ";
            }
            current = current->next[i]; 
        }
        cout << endl;
    }
}

void DirectorSkipList::setSize(int input){
    size = input;
}
