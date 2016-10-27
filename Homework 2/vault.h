//
//  vault.h
//  hw2
//
//  Created by Corey Henry on 6/30/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//



// Non templated version
#pragma once
#ifndef hw2_vault_h
#define hw2_vault_h


// Uses the linked list and nodes provided in class
// Get access to size_t definitions
#include <cstddef>
using std::size_t;
using std::string;


class Dweller
{
    friend class Room;
public:
    Dweller(string charname, int strength,int perception, int agility);
    Dweller(const Dweller&)= default;
    string getCharName() const;
    int getStrength() const;
    int getPerception() const;
    int getAgility() const;
    
    void printDweller() const;
    
private:
    string charName;
    int strength;
    int perception;
    int agility;
    
    
};

// A type alias for the stored type. Changing this changes what is stored
typedef Dweller ItemType;

// Nodes for a linked list in C++
class Node
{
    // A friend declaration allows LinkedList class to access the Node's private data
    friend class LinkedList;
    
public:
    Node(const ItemType& data, Node* next = nullptr);
    
private:
    ItemType _data;
    Node* _next;
};

// An linked list for C++
class LinkedList
{
   
public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    
    LinkedList& operator=(const LinkedList&);
    
    void insert(const ItemType &data);  // Replace these w/ iterators
    int get_size() const;
    ItemType get_element(int positon) const;
   
    
private:
    // Helper methods
    void copy(const LinkedList &src);
    void dealloc();
    Node* find(size_t index) const;
    
    // data
    size_t _size;// how many items in list
    Node *_head;// points to the head
};




class Room
{
public:
    Room();
    Room(string name, string attribute);
    string getName() const;
    string getAttribute() const;
    void add(const Dweller&);
    void print() const;
    
private:
    string name;
    string attribute;
    LinkedList room_list;
    
    
    
};

#endif