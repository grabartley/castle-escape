/*This will be the Room class*/

//preprocessor
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"
using namespace std;

class Room {
    //member data
    int xcoord, ycoord;
    string name;
    string desc;
    vector<Item> loot;
    
public:
    //constructors
    Room();
    Room(int xcoord0, int ycoord0);
    Room(int xcoord0, int ycoord0, string name0);
    Room(int xcoord0, int ycoord0, string name0, string desc0);
    Room(int xcoord0, int ycoord0, string name0, string desc0, Item item);
    ~Room() {}
    
    //member functions
    //returns the x coord of the room
    int get_xcoord();
    
    //returns the y coord of the room
    int get_ycoord();
    
    //returns the name of the room
    string get_name();
    
    //returns the description of the room
    string get_desc();
    
    //sets the x coord for the room
    void set_xcoord(int xcoord0);
    
    //sets the y coord for the room
    void set_ycoord(int ycoord0);
    
    //sets the name for the room
    void set_name(string name0);
    
    //sets the description for the room
    void set_desc(string desc0);
    
    //lists items in the room
    void list_loot();
    
    //returns a pointer to the loot vector
    vector<Item>* get_loot();
    
    //returns the amount of items in the room
    int get_loot_size();
    
    //adds an item to the loot of the room
    void add_item(Item item0);
    
    //removes an item of loot from the room
    void remove_item(Item item0);
};

#endif