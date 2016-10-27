//
//  main.cpp
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
#include "graph.h"

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
    vector<int> ids;
    vector<string> names;
    
    
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
        ids.push_back(id);
        names.push_back(name);
    }
    namesFiles.close();
    
    ///finds out what the highest value in the id/name is.
    int max = 0;
    for(int i =0; i < ids.size(); i++)// finds out the highest value id wise and sets it as max.
    {
        if(ids.at(i) > max)
            max = ids.at(i);
    }// end of loop
    max += 1;
    
    
    vector<int> id_vector (max);// array for id #'s
    vector<string> name_vector(max);// array for names in order
    
    //loop to put everything in order.
    for(int i = 0;i < max ; i++)
    {
        name_vector[ids[i]] = names[i];
    }
    
    
    graph fought;// creates graph for fought
    graph team;// creates graph for teams
    
    fought.name_list(name_vector);
    team.name_list(name_vector);
    
    
    ///open 2nd file
    
    //open a file
    ifstream NewnamesFiles("teams.txt");
    if(!NewnamesFiles.good())
    {
        cerr << "couldnt open file." << endl;
        NewnamesFiles.close();
        return -1;
    }
    vector<int> ids2;
    vector<string> actions;
    vector<int> ids3;
    
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
            cout << "ids2" << id2 << " actions " << action << " ids3 " << id3 << endl;
        ids2.push_back(id2);
        actions.push_back(action);
        ids3.push_back(id3);
        
        
    }
    NewnamesFiles.close();
    
   
    
    for(int i = 0; i < actions.size(); i++)// loops through and adds plus one to the adjancey matrix per fight.
    {
        if(actions[i] == "fought")
        {
            fought.add_edge(ids2[i],ids3[i]);
            fought.add_edge(ids3[i],ids2[i]);
        }
        
        if(actions[i] == "teamedUp")
        {
            team.add_edge(ids2[i],ids3[i]);
            team.add_edge(ids3[i],ids2[i]);
            
        }
    }// end for for loop
    
    cout<< " the two who fought the most were " << fought.highest_weight() << endl;
    cout<< ""<< endl;
    cout << " the two who teamed up the most were " << team.highest_weight() << endl;
    cout<< "" << endl;
    
    for(int i= 0; i < name_vector.size(); i++)// prints out the names in order for checks.
    {
        cout<< name_vector[i] <<" "<< i << endl;
    }
    
    
    
    
    
    
    return 0;
}


