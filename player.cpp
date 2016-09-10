/*This will define the member funtions and constructors of the Player class*/

//preprocessor
#include "player.h"

//constructor definitions
Player::Player() {
    name = "Bob";
    //spawn at pos 2,1
    xcoord = 2;
    ycoord = 1;
    //starter items
    //inventory.push_back(Item("Journal", "\tA battered, leather-bound journal with the letters G B on it's front.\n"));
    //inventory.push_back(Item("Quill & Inkpot", "\tA feather quill and a small container filled with black ink.\n"));
}

Player::Player(string name0) {
    name = name0;
    //spawn at pos 2,1
    xcoord = 2;
    ycoord = 1;
    //starter items
    //inventory.push_back(Item("Journal", "\tA battered, leather-bound journal with the letters G B on it's front.\n"));
    //inventory.push_back(Item("Quill & Inkpot", "\tA feather quill and a small container filled with black ink.\n"));
}

//member function definitions
string Player::get_name() {
    return name;
}

int Player::get_xcoord() {
    return xcoord;
}

int Player::get_ycoord() {
    return ycoord;
}

vector<Item>* Player::get_inventory() {
    return &inventory;
}

int Player::get_inventory_size() {
    return (int)inventory.size();
}

void Player::list_inventory() {
    cout << "\t\t" << "< Inventory >" << "\n";
    for (int i = 0; (unsigned)i < inventory.size(); i++) {
        cout << "\t\t" << "<" << i + 1 << ">\t" << inventory[i].get_name() << "\n";
    }
}

void Player::set_name(string name0) {
    name = name0;
}

void Player::set_pos(int xcoord0, int ycoord0) {
    xcoord = xcoord0;
    ycoord = ycoord0;
}

void Player::add_item(Item item0) {
    inventory.push_back(item0);
}

void Player::remove_item(Item item0) {
    for (int i = 0; (unsigned)i < inventory.size(); i++) {
        if (inventory[i] == item0) {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}

void Player::reset() {
    Player default_player;
    this->name = default_player.name;
    this->xcoord = default_player.xcoord;
    this->ycoord = default_player.ycoord;
    this->inventory = default_player.inventory;
}

bool Player::move_north(vector<int>* flags) {
    //if not going outside the map
    if (ycoord != 4) {
        if (xcoord == 1 && ycoord == 3) {
            return false;
        } else if ((xcoord == 2 && ycoord == 3) && flags->at(1) == 0) {
            return false;
        } else if (xcoord == 0 && ycoord == 2) {
            return false;
        } else if (xcoord == 1 && ycoord == 1) {
            return false;
        } else if ((xcoord == 3 && ycoord == 1) && flags->at(4) == 0) {
            return false;
        } else if (xcoord == 0 && ycoord == 0) {
            return false;
        } else {
            return ++ycoord;
        }
    } else {
        return false;
    }
}

bool Player::move_south(vector<int>* flags) {
    //if not going outside the map
    if (ycoord != 0) {
        if (xcoord == 1 && ycoord == 4) {
            return false;
        } else if ((xcoord == 2 && ycoord == 4) && flags->at(1) == 0) {
            return false;
        } else if (xcoord == 0 && ycoord == 3) {
            return false;
        } else if (xcoord == 1 && ycoord == 2) {
            return false;
        } else if ((xcoord == 3 && ycoord == 2) && flags->at(4) == 0) {
            return false;
        } else if (xcoord == 0 && ycoord == 1) {
            return false;
        } else {
            ycoord--;
            return true;  
        }
    } else {
        return false;
    }
}

bool Player::move_east(vector<int>* flags) {
    //if not going outside the map
    if (xcoord != 3) {
        if ((xcoord == 0 && ycoord == 4) && flags->at(3) == 0) {
            return false;
        } else if ((xcoord == 1 && ycoord == 4) && flags->at(2) == 0) {
            return false;
        } else if (xcoord == 2 && ycoord == 4) {
            return false;
        } else if (xcoord == 0 && ycoord == 3) {
            return false;
        } else if (xcoord == 1 && ycoord == 2) {
            return false;
        } else if (xcoord == 1 && ycoord == 1) {
            return false;
        } else if (xcoord == 2 && ycoord == 1) {
            return false;
        } else if ((xcoord == 0 && ycoord == 0) && flags->at(0) == 0) {
            return false;
        } else if (xcoord == 1 && ycoord == 0) {
            return false;
        } else if (xcoord == 2 && ycoord == 0) {
            return false;
        } else {
            return ++xcoord;
        }
    } else {
        return false;
    }
}

bool Player::move_west(vector<int>* flags) {
    //if not going outside the map
    if (xcoord != 0) {
        if ((xcoord == 1 && ycoord == 4) && flags->at(3) == 0) {
            return false;
        } else if ((xcoord == 2 && ycoord == 4) && flags->at(2) == 0) {
            return false;
        } else if (xcoord == 3 && ycoord == 4) {
            return false;
        } else if (xcoord == 1 && ycoord == 3) {
            return false;
        } else if (xcoord == 2 && ycoord == 2) {
            return false;
        } else if (xcoord == 2 && ycoord == 1) {
            return false;
        } else if (xcoord == 3 && ycoord == 1) {
            return false;
        } else if ((xcoord == 1 && ycoord == 0) && flags->at(0) == 0) {
            return false;
        } else if (xcoord == 2 && ycoord == 0) {
            return false;
        } else if (xcoord == 3 && ycoord == 0) {
            return false;
        } else {
            xcoord--;
            return true;
        }
    } else {
        return false;
    }
}