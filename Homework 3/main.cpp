//
//  main.cpp
//  hw3
//
//  Created by Corey Henry on 7/7/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//


// Heap algorithm test
// Counts numbers of collisions of a words using a hash algorithm.
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;
using std::to_string;
using std::getline;
using std::list;



unsigned Hash(string const& key, unsigned tableSize)// from daniweb.com
{
    unsigned hashVal = 0;
    for (int x = 0; x < key.length(); ++x)
    {
        hashVal ^= (hashVal << 5) +
        (hashVal >> 2) +
        key[x];
    }
    return hashVal % tableSize;
}


// Bog standard hash: Adds ASCII value of characters, returns modules tableSize
unsigned int simpleHash(const string& word, unsigned int tableSize)
{
    if(tableSize == 0)
    throw "Invalid size.";
    unsigned int result = 0;
    for(char character : word)
    result += static_cast<unsigned int>(character);
    return result % tableSize;
}

// Read in the words file, returning the list of words
list<string> readWords()
{
    list<string> words;
    ifstream wordfile("words.txt");  // ifstream is like iostream, but for input files
    if(!wordfile) // Check for opening error
    {
        // Write error to cerr (console error)
        cerr << "Could not open words.txt file." << endl;
        throw;
    }
    while(wordfile.good())  // While no errors
    {
        string word;
        getline(wordfile, word);
        if(wordfile.eof())
        break;
        words.push_back(word);
        if(!wordfile.eof() && !wordfile) // Check for reading error
        {
            cerr << "Error reading word file" << endl;
            throw;
        }
    }
    wordfile.close();
    return words;
}

// Write collision frequency table
void writeCollisions(const unsigned int* counts, const int hashSize)
{
    ofstream countfile("collisions_" + to_string(hashSize) + ".csv");
    if(!countfile) // Check for opening error
    {
        // Write error to cerr (console error)
        cerr << "Could not open counts.csv file." << endl;
        throw;
    }
    for(int i = 0; i < hashSize; ++i)
    {
        countfile << i << "," << counts[i] << endl;
        if(!countfile) // Check for write error
        {
            cerr << "Error writing count file" << endl;
            throw;
        }
    }
    countfile.close();
}


// Driver function
int main()
{
    cout << "Reading words.txt... ";
    list<string> words(readWords());
    cout << "done." << endl;
    cout << "There are " << words.size() << " in the words list." << endl;
    
    unsigned int hashSize;
    cout << "Size of hash table? ";
    cin >> hashSize;
    unsigned int *counts = new unsigned int[hashSize]; // frequency table
    for(int i = 0; i < hashSize; ++i)
    counts[i] = 0; // zero out
    
    cout << endl;
    cout << "Calculating hash collisions... ";
    for(string word : words)
    {
        unsigned int hash = Hash(word, hashSize);
        counts[hash] += 1;
    }
    cout << "done. " << endl;
    cout << "Writing collision frequency table...";
    writeCollisions(counts, hashSize);
    cout << "done." << endl;
    
    return 0;
}

