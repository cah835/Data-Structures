//
//  heap.h
//  hw 5
//
//  Created by Corey Henry on 7/22/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#ifndef hw_5_heap_h
#define hw_5_heap_h
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
using std::cout;
using std::cin;
using std::endl;


//forward decleration
template <typename T> class mutable_heap;




// Node class
template <typename T>
class mutable_heap
{
private:
    vector<T> hash;
    unordered_map<T,int> indicies;
public:
    void reheap()// reheap
    {
        int loc2 = hash.size();// does the hash update
        loc2 -=1;
        
        
        while(hash[loc2] > hash[loc2/2])// switches places if the child is greater then parent while loop
        {
            int temp= 0;
            temp = indicies[hash[loc2]];
            indicies[hash[loc2]] = indicies[hash[loc2/2]];
            indicies[hash[loc2/2]] = temp;
            loc2 = loc2/2;// resets location to continue going if the new item is greater than more than one parent
        }
        
        
        int loc = hash.size();// does the heap update
        loc -= 1;
        
        while(hash[loc] > hash[loc/2])// switches places if the child is greater then parent while loop
        {
            int temp= 0;
            temp = hash[loc];
            hash[loc] = hash[loc/2];
            hash[loc/2] = temp;
            loc = loc/2;// resets location to continue going if the new item is greater than more than one parent
        }
    }
    
    T pop()// pops a value and makes it one size smaller.
    {
        T value;
        value = hash[1];
        hash[1] = hash[hash.size()];
        hash.pop_back();// got argument from cplusplus.com
        reheap();
        return value;
        
    }
    
    void push_back(const T &value)// inserts a new value
    {
        hash.push_back(value);
        reheap();

    }
    
    void update_heap(const T& old_value, const T& new_value)// replaces old value with a new value
    {
        for(int i=1; i < hash.size(); i++)// loops through the array.
        {
            if(hash[i] == old_value)// if the value exsists it will replace the value and the reheapify
            {
                hash[i] = new_value;
                reheap();
            }
        }

        
    }
    
    
};


#endif
