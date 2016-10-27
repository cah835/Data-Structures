//
//  graph.h
//  Hw 6
//
//  Created by Corey Henry on 7/30/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#ifndef Hw_6_graph_h
#define Hw_6_graph_h


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;



class graph
{
public:
    void name_list(vector<string> names);
    void add_edge(int id2, int id3);
    void prims_tree();
    string highest_weight();
    

private:
    vector<string> names_in_order;
    int **array;
    int **min_tree;
    
    
    
    
    
    
};




#endif
