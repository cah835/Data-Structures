//
//  main.cpp
//  hw 5
//
//  Created by Corey Henry on 7/20/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "heap.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int option;
    mutable_heap<int> heap_hash;
    heap_hash.push_back(0);// puts a zero in index zero to make first value go to index 1.
    while(true)
    {
    cout<< "Please choose one of the following options"<< endl;
    cout<< "Option 1: pushes and updates" << endl;
    cout<< "Option 2: update a old value with a new value" << endl;
    cout << "Option 3: Pop the max value in the heap" << endl;
    cout<< "Option 4: Exit" << endl;
    cin >> option;
    
    
    
    if(option == 1)// inserts new item
    {
        int number;
        cout << "what number would you like to add to the heap?" << endl;
        cin >> number;
        heap_hash.push_back(number);
        
        
    }
    
    if(option == 2)// update value
    {
        int old_value;
        int new_value;
        cout << "what is the value you wish to replace?" << endl;
        cin >> old_value;
        cout << "what is the value you would like to replace it with?" << endl;
        cin >> new_value;
        heap_hash.update_heap(old_value, new_value);
        
        
    }
        
        
    if(option ==3)// will pop the max value and decrease size of array by 1.
    {
        cout<< "The number popped was " << heap_hash.pop() << " " << endl;
    }
        
        
    
    if(option == 4)// will return false to end the loop
        return false;
        
        
    }//end of while loop
}