#ifndef __DIRECTOR_SKIP_LIST_HPP__ 
#define __DIRECTOR_SKIP_LIST_HPP__
#include <iostream>
#include <vector>
#include "MovieNode.hpp"
using namespace std;
#define DEFAULT_LEVELS 10
#define DEFAULT_CAPACITY 2000

struct DirectorSLNode {
  string director;
  vector<MovieNode*> movies;
  vector<DirectorSLNode*> next;
  DirectorSLNode() {director = "noname";}

  DirectorSLNode(string _director, int levels) {
    director = _director;
    next = vector<DirectorSLNode*>(levels, nullptr);
  }

  bool addMovie(MovieNode* _movie) {
    for (auto movie: movies) {
        if (movie->title == _movie->title) {
            return false;
        }
    }
    movies.push_back(_movie);
    return true;
  }
};

class DirectorSkipList {
    private:
        int capacity;
        int levels;
        DirectorSLNode* head;
        int size;

    public:
        DirectorSkipList();
        DirectorSkipList(int _cap,int _levels);

        ~DirectorSkipList();
        DirectorSkipList(const DirectorSkipList&) = delete;
        DirectorSkipList& operator=(const DirectorSkipList&) = delete;

        int generateRandomLevel();
        void insert(string director, MovieNode* _movie);
        DirectorSLNode* search(string director);
        void prettyPrint();
        void setSize(int input);
        int getSize() const {return size;}
        int getCapacity() const {return capacity;}
};
#endif
