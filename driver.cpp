#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MovieHashTable.hpp"
#include "DirectorSkipList.hpp"

using namespace std;

// Function prototypes
MovieNode* parseMovieLine(string line);
void readMovieCSV(string filename,  MovieHashTable &movieTable, DirectorSkipList &directorList);
void display_menu();


// Main function
int main(int argc, char* argv[]) {
    // TODO
    //Command Line arguments conditional
    if(argc!= 4){
        cout << "Invalid number of arguments.\nUsage: ./<program name> <csv file> <hashTable size> <skipList size>" << endl;
        return 0;
    }
    //Create HashTables and Skiplists
    string filename = argv[1];
    int listSize = stoi(argv[2]);
    int hashSize = stoi(argv[3]);
    DirectorSkipList skipList(listSize, DEFAULT_LEVELS);
    // skipList.setSize(listSize);
    MovieHashTable hashTable(hashSize);
    
    
    

    //read csv
    //I have commented this function because during compilation as the csv file is being read and parsed, the program runs into a seg fault and fails. Without this, the menu runs as expected, however it sometimes infinite loops.
    // readMovieCSV(filename,hashTable,skipList);
    //Menu
    bool running = true;
    int choice;
    while(running){
        cout << "Number of collisions: " << hashTable.getCollisions()<< endl;
        display_menu();
        cin >> choice;
        MovieNode* movie;
        string name;
        string directorName;
        DirectorSLNode* director;
        switch(choice){
            case 1:{//Find director of Movie
                
                cout << "Enter movie name: ";
                cin >> name;
                
                movie = hashTable.search(name);
                if(movie){
                    cout << "The director of " << movie->title << " is " << movie->director << endl; 
                } else {
                    cout << "Director not found" << endl;
                }
            }
            break;
            case 2:{ //Find number of movies by a director
                cout << "Enter director name: ";
                cin >> directorName;
                
                director = skipList.search(directorName);
                if(director){
                    cout << director->director << " directed " << director->movies.size() << " movies." << endl;
                } else {
                    cout << "Director not found" << endl;
                }
            }
            break;
            case 3:{ //Find description of Movie
                cout << "Enter movie name";
                cin >> name;
                
                movie = hashTable.search(name);
                if(movie){
                    cout << movie->title << " 's Description: " << movie->description << endl;
                } else {
                    cout << "Movie not found." << endl;
                }
            }
            break;
            case 4:{ // List movies by director
                cout << "Enter the director's name: ";
                cin >> directorName;
                
                director = skipList.search(directorName);
                if(director){
                    cout << director->director << " directed the following movies:" << endl;
                    for(size_t i = 0; i < director->movies.size(); ++i){
                        cout << i << ": " << director->movies[i]->title << endl;
                    } 
                }else {
                        cout << "Director not found" << endl;
                    }
            }
            break;
            case 5:{
                //Call destructors
                cout << "Quit" << endl;
                running = false;
            }
            break;
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    return 0;
}

// Function to parse a CSV line into a MovieNode object
MovieNode* parseMovieLine(string line) {
    stringstream ss(line);
    vector<string> fields;
    string field;

    // Loop through the characters in the line
    bool in_quotes = false;
    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];
        if (c == '\"') {
            in_quotes = !in_quotes;
        } else if (c == ',' && !in_quotes) {
            // add field to vector and reset for next field
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
            // handle double quotes inside a quoted field
            if (in_quotes && c == '\"' && i < line.length() - 1 && line[i+1] == '\"') {
                field += '\"'; // add the second double quote and skip it
                ++i;
            }
        }
    }
    fields.push_back(field);

    if (fields.size() != 12) {
        cerr << "Error: Invalid movie line format" << line << endl;
        return nullptr;
    }

    int rank = stoi(fields[0]);
    string title = fields[1];
    string genre = fields[2];
    string description = fields[3];
    string director = fields[4];
    string actors = fields[5];
    int year = stoi(fields[6]);
    int runtime = stoi(fields[7]);
    float rating = stof(fields[8]);
    int votes = stoi(fields[9]);
    float revenue = stof(fields[10]);
    int metascore = stoi(fields[11]);

    // Create a new MovieNode object with the parsed fields
    MovieNode* movie = new MovieNode(rank, title, genre, description, director, actors, year, runtime, rating, votes, revenue, metascore);
    return movie;
}

// Function to read a CSV file into a vector of MovieNode objects
void readMovieCSV(string filename,  MovieHashTable &movieTable, DirectorSkipList &directorList) {
    // TODO
    ifstream file(filename);
    if( !file.is_open()){
        cout << "Error: Could not open file." << filename << endl;
        return;
    }
    string line;
    getline(file,line);
    while(getline(file,line)){
        MovieNode* movie = parseMovieLine(line);
        if(movie){
            movieTable.insert(movie->title,movie);
            directorList.insert(movie->director,movie);
        }
    }
    file.close();
}

// Function to display the menu options
void display_menu() {
    // TODO
        cout << "Please select an option:" << endl;
        cout << "1. Find the director of a movie" << endl;
        cout << "2. Find the number of movies by a director" << endl;
        cout << "3. Find the description of a movie" << endl;
        cout << "4. List the movies by a director" << endl;
        cout << "5. Quit \n" << endl;
        cout << "Enter an Option:" << endl;
        
}
