<img src="https://www.colorado.edu/cs/profiles/express/themes/ucb/images/cu-boulder-logo-text-black.svg" alt="CU Boulder Logo" width="500">

# CSCI 2270: Data Structures <br/> IMDB Movies Database Project

This project is a simple implementation of a movie database using C++ and two data structures: a hash table and a skip list. Please go through *CSCI2270_Spring23_Project.pdf* for the detailed instructions.

## Requirements

1. C++ compiler 
2. A CSV file containing movie data (e.g. IMDB-Movie-Data.csv)

## Installation

1. Clone the repository
2. Compile the code : `g++ -std=c++11 driver.cpp MovieHashTable.cpp DirectorSkipList.cpp -o movie-db`
3. Run the program: `./movie-db IMDB-Movie-Data.csv 2000 2000`
4. Follow the on-screen menu to perform different operations on the movie database.

## Data Structures

This project uses two data structures to store and retrieve movie data: a hash table and a skip list.

### Hash Table
The hash table is used to map movie titles to `MovieNode` objects. 
The hash function used is a custom function that takes the sum of the ASCII codes of all characters in the title string and calculates the modulo of the sum by the hash table size. Students must use their identikey to come up with a creative hash function that minimizes collisions
for the given IMDB-Movie database to ensure efficient insertion and retrieval of movie nodes.

### Skip List
The skip list is used to map director names to `DirectorSLNode` objects, which contain a vector of `MovieNode` pointers. The skip list is a probabilistic data structure that allows for efficient search, insertion, and deletion of elements. It is implemented using a linked list with multiple levels, where each level has fewer nodes than the level below it. The skip list used in this project has a fixed number of levels (10) and a fixed capacity (2000).

