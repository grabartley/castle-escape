/*This will be the Item class*/

//preprocessor
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
    //member data
    string name;
    string desc;
    
public:
    //constructors
    Item();
    Item(string name0);
    Item(string name0, string desc0);
    ~Item() {}
    
    //operator overloading (one arg since declared in class)
    bool operator==(const Item& other_item);
    
    //member functions
    //returns the name of the item
    string get_name();
    
    //returns a description of the item
    string get_desc();
    
    //sets the name of an item
    void set_name(string name0);
    
    //sets the description of an item
    void set_desc(string desc0);
};

#endif