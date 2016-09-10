/*This will define the member funtions and constructors of the Item class*/

//preprocessor
#include "item.h"

//constructor definitions
Item::Item() {
    name = "item";
    desc = "\tThis is an item with no description.\n";
}

Item::Item(string name0) {
    name = name0;
    desc = "\tThis is an item with no description.\n";
}

Item::Item(string name0, string desc0) {
    name = name0;
    desc = desc0;
}

//operator overloading definitions
bool Item::operator==(const Item& other_item) {
    return (this->name == other_item.name) && (this->desc == other_item.desc);
}

//member function definitions
string Item::get_name() {
    return name;
}

string Item::get_desc() {
    return desc;
}

void Item::set_name(string name0) {
    name = name0;
}

void Item::set_desc(string desc0) {
    desc = desc0;
}