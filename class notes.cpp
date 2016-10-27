//
//  class notes.cpp
//  Hw 6
//
//  Created by Corey Henry on 7/27/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
int main()
{
    //open a file
    ifstream namesFiles("names.txt");
    if(!namesFiles.good())
    {
        cerr << "couldnt open file." << endl;
        namesFiles.close();
        return -1;
    }
    vector<int> id;
    vector<string> name;
    
    
    // formated input: read into an int and a string
    while(!namesFiles.eof())
    {
        int id;
        string name;
        namesFiles >> id >> name;
        if(!namesFiles.good() && !namesFiles.eof())
        {
            cerr << "Error reading." << endl;
            namesFiles.close();
            return -1;
        }
        if(!namesFiles.eof())
        cout << "id" << id << " name " << name << endl;
        id.push_back(id);
        name.push_back(name);
    }
    namesFiles.close();
    
    ///finds out what the highest value in the id/name is.
    int max = 0;
    for(int i =0; id.size(); i++)// finds out the highest value id wise and sets it as max.
    {
        if(id.at(i) > max)
            max = id.at(i);
    }// end of loop
    max += 1;
    
    
    vector<int> id_vector (sizeof(max));// array for id #'s
    vector<string> name_vector(sizeof(max));// array for names in order
    
    //loop to put everything in order.
    int count = 1;
    for(int i = 0;i < max ; i++)
    {
        name_vector.insert(name.at(id.at(1)));
    }
    
    
    int fought_array[max][max];
    int team_array[max][max];
    
    // sets the values all to zero before adding
    for(int i = 0; i < max ; i++)
    {
        fought_array[i][i] = 0;
        team_array[i][i] = 0;
    }
    
    
    
    ///open 2nd file
    
    //open a file
    ifstream NewnamesFiles("teams.txt");
    if(!namesFiles.good())
    {
        cerr << "couldnt open file." << endl;
        namesFiles.close();
        return -1;
    }
    vector<int> id2;
    vector<string> action;
    vector<int> id3;
    
    // formated input: read into an int and a string
    while(!NewnamesFiles.eof())
    {
        int id2;
        string action;
        int id3;
        NewnamesFiles >> id2 >> action >> id3;
        if(!NewnamesFiles.good() && !NewnamesFiles.eof())
        {
            cerr << "Error reading." << endl;
            NewnamesFiles.close();
            return -1;
        }
        if(!NewnamesFiles.eof())
            cout << "id2" << id2 << " action " << action << "id3" << id3 << endl;
        id.push_back(id2);
        action.push_back(action);
        id3.push_back(id3)
        
        
    }
    NewnamesFiles.close();
    
    for(int i = 0; i < max; i++)// loops through and adds plus one to the adjancey matrix per fight.
    {
        if(action[i] == "fought against")
        {
            fought_array[id2[i]][id2][i]] += 1;
            fought_array[id3[i]][id3][i]] += 1;
        }
    
        if(action[i] == "teamed up")
        {
            team_array[id2[i]][id2][i]] += 1;
            team_array[id3[i]][id3][i]] += 1;
            
        }
    }// end for for loop

    
    
    
    return 0;
}


