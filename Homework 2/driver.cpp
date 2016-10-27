//
//  driver.cpp
//  hw2
//
//  Created by Corey Henry on 6/30/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#include <stdio.h>
// driver.cpp
// Testing driver for Assignment 2

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

int main()
{
    std::locale loc;
    
    // We create three rooms: Power Generator (Strength), Water Processing (Perception),
    // and Diner (Agility)
    Room power("Power Generator", "Strength");
    Room water("Water Processing", "Perception");
    Room diner("Diner", "Agility");
    
    string prompt;
    do
    {
        string charName;
        cout << "What is the Dweller's name? ";
        getline(cin, charName);
        int str = 0, per = 0, agl = 0;
        char room;
        do
        {
            cout << "What is the character's Strength [1-10]? ";
            cin >> str;
        }
        while(str <= 0 || str > 10);
        do
        {
            cout << "What is the character's Perception [1-10]? ";
            cin >> per;
        }
        while(per <= 0 || per > 10);
        do
        {
            cout << "What is the character's Agility [1-10]? ";
            cin >> agl;
        }
        while(agl <= 0 || agl > 10);
        
        do
        {
            cout << "Which room [(P)ower, (W)ater, (D)iner]? ";
            cin >> room;
            room = tolower(room, loc);
        }
        while(room != 'p' && room != 'w' && room != 'd');
        if(room == 'p')
        power.add(Dweller(charName, str, per, agl));
        else if(room == 'w')
        water.add(Dweller(charName, str, per, agl));
        else
        diner.add(Dweller(charName, str, per, agl));
        
        cout << "Are there more Dwellers [Y/N]? " << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush newlines
        getline(cin, prompt);
    }
    while(tolower(prompt[0], loc) == 'y');
    
    power.print();
    water.print();
    diner.print();
}