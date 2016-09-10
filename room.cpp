/*This will define the member funtions and constructors of the Room class*/

//preprocessor
#include "room.h"

//constructor definitions
Room::Room() {
    xcoord = 0;
    ycoord = 0;
    name = "";
    desc = "This is a room with no description.";
}

Room::Room(int xcoord0, int ycoord0) {
    xcoord = xcoord0;
    ycoord = ycoord0;
    name = "";
    desc = "This is a room with no description.";
}

Room::Room(int xcoord0, int ycoord0, string name0) {
    xcoord = xcoord0;
    ycoord = ycoord0;
    name = name0;
    desc = "This is a room with no description.";
}

Room::Room(int xcoord0, int ycoord0, string name0, string desc0) {
    xcoord = xcoord0;
    ycoord = ycoord0;
    name = name0;
    desc = desc0;
}

Room::Room(int xcoord0, int ycoord0, string name0, string desc0, Item item) {
    xcoord = xcoord0;
    ycoord = ycoord0;
    name = name0;
    desc = desc0;
    loot.push_back(item);
}

//member function definitions
int Room::get_xcoord() {
    return xcoord;
}

int Room::get_ycoord() {
    return ycoord;
}

string Room::get_name() {
    return name;
}

string Room::get_desc() {
    return desc;
}

void Room::set_xcoord(int xcoord0) {
    xcoord = xcoord0;
}

void Room::set_ycoord(int ycoord0) {
    ycoord = ycoord0;
}

void Room::set_name(string name0) {
    name = name0;
}

void Room::set_desc(string desc0) {
    desc = desc0;
}

void Room::list_loot() {
    cout << "\t\t" << "< Items in this room >" << "\n";
    for (int i = 0; (unsigned)i < loot.size(); i++) {
        cout << "\t\t" << "<" << i + 1 << ">\t" << loot[i].get_name() << "\n";
    }
    cout << "\n";    
}

vector<Item>* Room::get_loot() {
    return &loot;
}

int Room::get_loot_size() {
    return (int)loot.size();
}

void Room::add_item(Item item0) {
    loot.push_back(item0);
}

void Room::remove_item(Item item0) {
    for (int i = 0; (unsigned)i < loot.size(); i++) {
        if (loot[i] == item0) {
            loot.erase(loot.begin() + i);
            break;
        }
    }    
}