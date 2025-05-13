#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include "MovieHashTable.hpp"
#include "DirectorSkipList.hpp"

using namespace std;

MovieNode* parseMovieLine(string line);
void readMovieCSV(string filename, MovieHashTable &movieTable, DirectorSkipList &directorList);
void display_menu();
string getFullLineInput();

int main(int argc, char* argv[]) {
    if(argc != 4){
        cout << "Invalid number of arguments.\nUsage: ./<program name> <csv file> <hashTable size> <skipList size>" << endl;
        return 0;
    }
    
    string filename = argv[1];
    int hashSize = stoi(argv[2]);
    int listSize = stoi(argv[3]);
    
    DirectorSkipList skipList(listSize, DEFAULT_LEVELS);
    MovieHashTable hashTable(hashSize);
    
    readMovieCSV(filename, hashTable, skipList);
    
    bool running = true;
    int choice;
    while(running){
        cout << "Number of collisions: " << hashTable.getCollisions() << endl;
        display_menu();
       
        if(!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string name;
        string directorName;
        MovieNode* movie;
        DirectorSLNode* director;
        
        switch(choice){
            case 1: {
                cout << "Enter movie name: ";
                name = getFullLineInput();
                
                movie = hashTable.search(name);
                if(movie){
                    cout << "The director of \"" << movie->title << "\" is \"" << movie->director << "\"" << endl;
                } else {
                    cout << "Movie not found" << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter director name: ";
                directorName = getFullLineInput();
                
                director = skipList.search(directorName);
                if(director){
                    cout << "\"" << director->director << "\" directed " << director->movies.size() << " movies." << endl;
                } else {
                    cout << "Director not found" << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter movie name: ";
                name = getFullLineInput();
                
                movie = hashTable.search(name);
                if(movie){
                    cout << "\"" << movie->title << "\"'s Description: " << movie->description << endl;
                } else {
                    cout << "Movie not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter the director's name: ";
                directorName = getFullLineInput();
                
                director = skipList.search(directorName);
                if(director){
                    cout << "\"" << director->director << "\" directed the following movies:" << endl;
                    for(size_t i = 0; i < director->movies.size(); ++i){
                        cout << i+1 << ": " << director->movies[i]->title << endl;
                    }
                } else {
                    cout << "Director not found" << endl;
                }
                break;
            }
            case 5: {
                cout << "Goodbye!" << endl;
                running = false;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}

string getFullLineInput() {
    string input;
    getline(cin, input);
    return input;
}

MovieNode* parseMovieLine(string line) {
    vector<string> fields;
    stringstream ss(line);
    string field;
    bool inQuotes = false;
    string tempField = "";
    for (size_t i = 0; i < line.length(); i++) {
        char c = line[i];
        
        if (c == '\"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {

            fields.push_back(tempField);
            tempField = "";
        } else {
            tempField += c;
        }
    }
    fields.push_back(tempField);
    
    if (fields.size() < 12) {
        cout << "Warning: Incomplete movie data, skipping line" << endl;
        return nullptr;
    }
    
    try {
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
        
        float revenue = 0.0f;
        if (!fields[10].empty()) {
            revenue = stof(fields[10]);
        }
        
        int metascore = 0;
        if (!fields[11].empty()) {
            metascore = stoi(fields[11]);
        }
 
        MovieNode* movie = new MovieNode(rank, title, genre, description, director, actors, year, runtime, rating, votes, revenue, metascore);
        return movie;
    } 
    catch (const exception& e) {
        cout << "Error parsing movie data: " << e.what() << endl;
        return nullptr;
    }
}

void readMovieCSV(string filename, MovieHashTable &movieTable, DirectorSkipList &directorList) {
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Error: Could not open file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while(getline(file, line)){
        MovieNode* movie = parseMovieLine(line);
        if(movie){
            movieTable.insert(movie->title, movie);
            directorList.insert(movie->director, movie);
        }
    }
    file.close();
}

void display_menu() {
    cout << "\nPlease select an option:" << endl;
    cout << "1. Find the director of a movie" << endl;
    cout << "2. Find the number of movies by a director" << endl;
    cout << "3. Find the description of a movie" << endl;
    cout << "4. List the movies by a director" << endl;
    cout << "5. Quit" << endl;
    cout << "\nEnter an Option: ";
}