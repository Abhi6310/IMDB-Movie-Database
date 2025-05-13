#include<iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "DirectorSkipList.hpp"
using namespace std;

DirectorSkipList::DirectorSkipList() {
    srand(time(0));
    capacity = DEFAULT_CAPACITY;
    levels = DEFAULT_LEVELS;
    size = 0;
    head = new DirectorSLNode("", levels);
}

DirectorSkipList::DirectorSkipList(int _cap, int _levels) {
    srand(time(0));
    capacity = _cap;
    levels = _levels;
    size = 0;
    head = new DirectorSLNode("", levels);
}

DirectorSkipList::~DirectorSkipList() {
    if (!head) {
        return;
    }
    DirectorSLNode* current = head;
    while(current) {
        DirectorSLNode* nextNode = current->next[0];
        delete current;
        current = nextNode;
    }
}

int DirectorSkipList::generateRandomLevel(){
    int lvl = 1;
    while ((rand() % 2) && (lvl < levels)){
        lvl++;
    }
    return lvl;
}

void DirectorSkipList::insert(string director, MovieNode* _movie) {
    vector<DirectorSLNode*> prevNode(levels, nullptr);
    DirectorSLNode* current = head;
    
    for (int i = levels - 1; i >= 0; i--) {
        while (current->next[i] && current->next[i]->director < director) {
            current = current->next[i];
        }
        prevNode[i] = current;
    }
    
    current = current->next[0];
    if(current != nullptr && current->director == director) {
        if (current->addMovie(_movie)) {
        }
    } else {
        int n_levels = generateRandomLevel();
        DirectorSLNode* newNode = new DirectorSLNode(director, n_levels);
        newNode->movies.push_back(_movie);
        for (int i = 0; i < n_levels; i++) {
            newNode->next[i] = prevNode[i]->next[i];
            prevNode[i]->next[i] = newNode;
        }
        size++;
    }
}

DirectorSLNode* DirectorSkipList::search(string director) {
    if (!head) return nullptr;
    
    DirectorSLNode* current = head;
    for(int i = levels - 1; i >= 0; i--) {
        while(current->next[i] && current->next[i]->director < director) {
            current = current->next[i]; 
        }
    }
    current = current->next[0];
    if(current && current->director == director) {
        return current;
    }
    return nullptr;
}

void DirectorSkipList::prettyPrint() {
    if (!head) {
        cout << "Skip list is empty or uninitialized" << endl;
        return;
    }
    for(int i = levels - 1; i >= 0; i--) {
        DirectorSLNode* current = head->next[i];
        cout << "Level " << i << ": ";
        while(current) {
            cout << current->director << " (" << current->movies.size() << " movies)";
            if(current->next[i]) {
                cout << " -> ";
            }
            current = current->next[i]; 
        }
        cout << endl;
    }
}

void DirectorSkipList::setSize(int input) {
    size = input;
}