//
//  graph.cpp
//  Hw 6
//
//  Created by Corey Henry on 7/30/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "graph.h"
using namespace std;



void graph::name_list(vector<string> names)
{
    for(string name : names)
    {
        names_in_order.push_back(name);
    }
    
    unsigned int max = names_in_order.size();
    
    for(int i = 0; i < max; i++)/// creates the array.
    {
        array[i] = new int[max];
        
    }
    
    // sets the values all to zero before adding
    for(int i = 0; i < max ; i++)
    {
        for( int j=0; j< max; j++)// nested loop
        {
            array[i][j] = 0;
            
        }
    }// end creation

    
}// end function


void graph::add_edge(int id2, int id3)
{
   
    array[id2][id3] += 1;
    array[id3][id2] += 1;
}

string graph::highest_weight()
{
    unsigned int count = names_in_order.size();
    int max = 0;
    int pos = 0;
    int pos2 = 0;
    for(int i = 0; i < count ; i++)
    {
        for( int j=0; j< count; j++)// nested loop
        {
            if( array[i][j] > max)
            {
            max = array[i][j];
                pos = i;
                pos2 = j;
            }
            
        }
    }// end creation
    return( names_in_order[pos] + " and " + names_in_order[pos2]);
    
    
}
/*
void graph::prims_tree(array[V][V])
{
    {
        int parent[V]; // Array to store constructed MST
        int key[V];   // Key values used to pick minimum weight edge in cut
        bool mstSet[V];  // To represent set of vertices not yet included in MST
        
        // Initialize all keys as INFINITE
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;
        
        // Always include first 1st vertex in MST.
        key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
        parent[0] = -1; // First node is always root of MST
        
        // The MST will have V vertices
        for (int count = 0; count < V-1; count++)
        {
            // Pick thd minimum key vertex from the set of vertices
            // not yet included in MST
            int u = minKey(key, mstSet);
            
            // Add the picked vertex to the MST Set
            mstSet[u] = true;
            
            // Update key value and parent index of the adjacent vertices of
            // the picked vertex. Consider only those vertices which are not yet
            // included in MST
            for (int v = 0; v < V; v++)
                
                // graph[u][v] is non zero only for adjacent vertices of m
                // mstSet[v] is false for vertices not yet included in MST
                // Update the key only if graph[u][v] is smaller than key[v]
                if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                    parent[v]  = u, key[v] = graph[u][v];
        }
        
   
    
    
    
    
}




int weight = array[0][0];
string name = names_in_order[0];
string parent = name;

for(int i = 0; i < 2; i++)/// creates the min spanning tree.
{
    min_tree[i] = new int[names_in_order.size()];
    
}

for(int i = 0; i < names_in_order.size(); i++)// sets the 1st collumn to show the
{
    min_tree[i][0] = i;
}

*/