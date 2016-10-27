//
//  vault.cpp
//  hw2
//
//  Created by Corey Henry on 7/1/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <locale>
#include <string>
#include "vault.h"

using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::string;
using std::locale;
using std::tolower;

string Dweller::getCharName() const
{
    return charName;
};

int Dweller::getStrength() const
{
   
    return strength;
}

int Dweller::getPerception() const
{
   
    return perception;
}

int Dweller::getAgility() const
{
    return agility;
}

string Room::getName() const
{
    return name;
}

string Room::getAttribute() const
{
    
    return attribute;
}

void Room::add(const Dweller& d)
{
    room_list.insert(d);
    
    
}

void Room::print() const // prints the room with dweller and attribute
{
    int value = 0;
    
    for(int i=0; i < room_list.get_size(); i++)
    {
        Dweller d = room_list.get_element(i);
        if(getAttribute() == "Agility")
           value += d.getAgility();
        if(getAttribute() == "Strength")
           value += d.getStrength();
        if(getAttribute() == "Perception")
           value += d.getPerception();
           
    if(getAttribute() == "Agility")//prints the dweller name and agility if in agility room
        cout<< d.getCharName() << " Agility " << d.getAgility() << endl;
    
    if(getAttribute() == "Strength")// print the dweller name and strength if in strength room
        cout<< d.getCharName() << " Strength " << d.getStrength() << endl;
    
    if(getAttribute() == "Perception")// print the dweller name and perception if in strength room
        cout<< d.getCharName() << " Perception "<< d.getPerception() << endl;
    
    }// end of for loop
    cout<< "total " << getAttribute()<< " pool: "<< value << endl;
           
}

void LinkedList::insert(const Dweller& d)
    {
        Node* n= new Node(d, nullptr);
        if(_head == nullptr)
            _head = n;
        else
        {
        n->_next = _head;
        _head = n;
        }
        
      
    }
int LinkedList::get_size() const// determines the size of the list and returns the size.
           {
               int size = 0;
               Node* current = _head;
               while(current != nullptr)
               {
                   size += 1;
                   current = current->_next;
               }
               return size;
           }
ItemType LinkedList::get_element(int position) const// gets the element at the position requested
           {
               Node* current = _head;
               for(int i=0; position; i++)
               current = current-> _next;
               return current-> _data;
               
           }
LinkedList::~LinkedList()//deconstrucour help from book
{
    Node *temp;
    
    for (temp = _head; _head; temp = _head)
    {
        _head = _head->_next;
        delete temp;
    }
}


Node::Node(const ItemType& data, Node* next)
:_data(data)
{
    this->_data = data;
    this->_next = next;
}

Dweller::Dweller(const string charName, int strength, int perception, int agility)
{
    this->charName = charName;
    this->strength = strength;
    this->perception = perception;
    this->agility = agility;
}

Room::Room(const string name, const string attribute)
{
    this->name = name;
    this->attribute = attribute;
}

LinkedList::LinkedList()
{
    _head = nullptr;
    _size = 0;
}

           