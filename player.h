/*This will be the Player class*/

//preprocessor
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "item.h"

class Player {
    //member data
    string name;
    vector<Item> inventory;
    int xcoord, ycoord;
    
public:
    //constructors
    Player();
    Player(string name0);
    ~Player() {}
    
    //member functions
    //returns the player name
    string get_name();
    
    //returns the player xcoord
    int get_xcoord();
    
    //returns the player ycoord
    int get_ycoord();
    
    //returns a pointer to the player's inventory vector
    vector<Item>* get_inventory();
    
    //returns the amount of items in the player's inventory
    int get_inventory_size();
    
    //list the player's inventory
    void list_inventory();
    
    //set the player name
    void set_name(string name0);
    
    //set the player position
    void set_pos(int xcoord0, int ycoord0);
    
    //add an Item to player inventory
    void add_item(Item item0);
    
    //remove an Item from player inventory
    void remove_item(Item item0);
    
    //resets the player data to default constructor data
    void reset();
    
    //moves the player north
    bool move_north(vector<int>* flags);
    
    //moves the player south
    bool move_south(vector<int>* flags);
    
    //moves the player east
    bool move_east(vector<int>* flags);
    
    //moves the player west
    bool move_west(vector<int>* flags);
};

#endif