# IMDB Movie Database

> **A C++ in-memory movie database**  
> Built with a hash table for title lookups and a skip list for director queries

---

## Table of Contents

- [Overview](#overview)  
- [Features](#features)  
- [Data Structures](#data-structures)  
- [Prerequisites](#prerequisites)  
- [Build & Run](#build--run)  
- [Usage](#usage)  
- [Directory Structure](#directory-structure)  
- [Author](#author)  
- [License](#license)  

---

## Overview

This project parses an IMDB-style CSV of movie records into two data structures:

1. A **hash table** mapping movie titles → `MovieNode`  
2. A **skip list** mapping director names → lists of `MovieNode`

It supports interactive queries by title or director.

---

## Features

- **Load** movies from any CSV file (`IMDB-Movie-Data.csv`, `IMDB-small.csv`, etc.)  
- **Lookup** the director of a given movie title  
- **Count** how many movies a director has in the database  
- **Fetch** a movie’s description by title  
- **List** all movies by a specific director  
- **Track** hash-table collision statistics  

---

## Data Structures

- **Hash Table** (`MovieHashTable`)  
  - Custom string hash function  
  - Open addressing with collision counting  
- **Skip List** (`DirectorSkipList`)  
  - Multiple levels (configurable)  
  - Fast ordered insert & search by director name  

---

## Prerequisites

- A C++ compiler with C++11 support (e.g. `g++`)  
- A movie CSV file with columns: `Rank,Title,Genre,Description,Director,Actors,Year,Runtime,Rating,Votes,Revenue,Metascore`

---

## Build & Run

1. **Clone** or unzip this repo  
2. **Compile**:
   ```bash
   g++ -std=c++11 driver.cpp \
       MovieHashTable.cpp DirectorSkipList.cpp \
       -o movie-db
