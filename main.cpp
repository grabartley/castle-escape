/*This will be the first code segment executed*/

//preprocessor
#include <iostream>
#include <string>

#include "item.h"
#include "player.h"
#include "room.h"
#include "init.h"
#include "helper.h"
using namespace std;

//global variables
static const int PLAY = 1;
static const int STOP = 0;
static const int MENU = 2;
static const int END_GAME = 3;
static int STATE = MENU;
static Room rooms[4][5];
static Player player;
static vector<Item>* inventory = player.get_inventory();
static vector<int> flags = {0, 0, 0, 0, 0, 0};
/*
flags[0] = status of door from 10 to 00 (0 for locked, 1 for unlocked)
flags[1] = status of door from 23 to 24 (0 for locked, 1 for unlocked)
flags[2] = status of wall from 24 to 14 (0 for intact, 1 for destroyed)
flags[3] = status of door from 14 to 04 (0 for locked, 1 for unlocked)
flags[4] = status of wall from 32 to 31 (0 for sealed, 1 for open)
flags[5] = status of drain in 12 (0 for key in drain, 1 for no key in drain)
*/

//prints the Castle Escape logo
void print_logo() {
    new_line(2);
    tab();
    cout << "    ||||||     ||      ||||||||  ||||||||||  ||        |||||||||" << endl;
    tab();
    cout << "  ||          ||||    ||             ||      ||        ||" << endl;
    tab();
    cout << "||           ||  ||   ||             ||      ||        ||" << endl;
    tab();
    cout << "||          ||    ||   |||||||       ||      ||        |||||||" << endl;
    tab();
    cout << "||          ||||||||         ||      ||      ||        ||" << endl;
    tab();
    cout << "  ||        ||    ||         ||      ||      ||        ||" << endl;
    tab();
    cout << "    ||||||  ||    ||  ||||||||       ||      ||||||||  |||||||||" << endl;
    new_line(2);
    tab();
    cout << "|||||||||   ||||||||      ||||||     ||      |||||||   |||||||||" << endl;
    tab();
    cout << "||         ||           ||          ||||    ||     ||  ||" << endl;
    tab();
    cout << "||         ||         ||           ||  ||   ||     ||  ||" << endl;
    tab();
    cout << "|||||||     |||||||   ||          ||    ||  ||||||||   |||||||" << endl;
    tab();
    cout << "||                ||  ||          ||||||||  ||         ||" << endl;
    tab();
    cout << "||                ||    ||        ||    ||  ||         ||" << endl;
    tab();
    cout << "|||||||||  ||||||||       ||||||  ||    ||  ||         |||||||||" << endl;
    new_line();
    sleep(3);
    tab(4);
    cout << "An adventure-puzzle game by Graham Bartley." << endl;
    new_line();
    sleep(4);
}

//prints the main menu
void main_menu() {
    new_line();
    tab(2);
    cout << " ________________________ " << endl;    
    tab(2);
    cout << "|-|--------------------|-|" << endl;
    tab(2);
    cout << "|-|   < Main Menu >    |-|" << endl;
    tab(2);
    cout << "|-|                    |-|" << endl;
    tab(2);
    cout << "|-|   <1>  New Game    |-|" << endl;
    tab(2);
    cout << "|-|   <2>  Help        |-|" << endl;
    tab(2);
    cout << "|-|   <3>  Exit        |-|" << endl;
    tab(2);
    cout << "|-|                    |-|" << endl;
    tab(2);
    cout << "|-|--------------------|-|" << endl;    
    tab(2);
    new_line();

    int choice = -1;
    tab();
    cout << "Choose an option from the menu" << endl;
    tab();
    cout << "> ";
    cin >> choice;
    
    if (choice == 1) {
        STATE = PLAY;
    } else if (choice == 2) {
        new_line();
        tab();
        cout << "Castle Escape is a text-based adventure-puzzle game." << endl;
        sleep(2);
        new_line();
        tab();
        cout << "The objective of the game is to escape the castle you find yourself in." << endl;
        sleep(2);
        tab();
        cout << "There are various different rooms to the castle which you can travel through on your adventure." << endl;
        sleep(2);
        tab();
        cout << "You may find items as you go along which you can collect. These will aid you in your escape!" << endl;
        sleep(2);
        tab();
        cout << "Items can only be used under specific circumstances, so think about when each item may be needed." << endl;
        sleep(2);
        tab();
        cout << "It can be very useful to draw a map as you journey through the castle as it's easy to get lost." << endl;
        sleep(2);
        tab();
        cout << "Pay close attention to room and item descriptions as they may provide hints on what to do!" << endl;
        sleep(2);
        tab();
        cout << "Also be careful to only provide input when asked for it, otherwise glitches may occur which cause you to lose progress!" << endl;
        sleep(2);
        tab();
        cout << "Other than that, it's up to you! Good luck escaping the castle!" << endl;
        sleep(3);
        main_menu();
    } else if (choice == 3) {
        STATE = STOP;
    } else {
        new_line();
        tab();
        cout << "Invalid input." << endl;
        sleep();
        main_menu();
    }
}

//prints the current game status
void print_status() {
    tab();
    cout << player.get_name() << endl;
    tab();
    cout << "Location: " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << endl;
    sleep(2);
    new_line();
    tab();
    cout << rooms[player.get_xcoord()][player.get_ycoord()].get_desc() << endl;
    new_line();
    sleep(3);
}

//lists options and gets choice of the player based on position & items
int get_player_choice() {
    int choice;
    
    tab(2);
    cout << "< Your Options >" << endl;
    tab(2);
    cout << "<1>\t Use an item." << endl;
    tab(2);
    cout << "<2>\t Look for items in the room." << endl;
    tab(2);
    cout << "<3>\t Walk north." << endl;
    tab(2);
    cout << "<4>\t Walk south." << endl;
    tab(2);
    cout << "<5>\t Walk east." << endl;
    tab(2);
    cout << "<6>\t Walk west." << endl;
    tab(2);
    cout << "<7>\t Open inventory." << endl;
    tab(2);
    cout << "<8>\t Return to the Main Menu. (Progress will be lost!)" << endl;
    
    new_line();
    tab();
    cout << "What would you like to do?" << endl;
    tab();
    cout << "> ";
    cin >> choice;
    new_line();
    sleep();
    return choice;
}

//use item function
void use_item() {
    int item_choice = -1;
    //if the player's inventory is not empty
    if (player.get_inventory_size() > 0) {
        player.list_inventory();
        new_line();
        tab();
        cout << "Enter an item number to use that item or enter 0 to return to options." << endl;
        tab();
        cout << "> ";
        cin >> item_choice;
        new_line();
        sleep();
        //to use an item if needed.
        if (item_choice > 0 && item_choice <= player.get_inventory_size()) {
            if(inventory->at(item_choice - 1).get_name() == "Rusted key" && player.get_xcoord() == 1 && player.get_ycoord() == 0 && flags[0] == 0) {
                flags[0] = 1;
                rooms[player.get_xcoord()][player.get_ycoord()].set_desc("This burial chamber is highly decorative, but lacking in treasures...\n\tThere are markings in the dust of where items of value once were.\n\tA stone coffin with signs of attempted burglary lays sealed in the centre of the tomb.\n\tA rusted iron door stands open in the western wall.");
                cout << "\tYou place the Rusted key in the equally-rusted keyhole of the door and turn it.\n\tThe keyhole crumbles to dust and you open the door with ease." << endl;                                                
            } else if (inventory->at(item_choice - 1).get_name() == "Steel key" && player.get_xcoord() == 2 && player.get_ycoord() == 3 && flags[1] == 0) {
                flags[1] = 1;
                rooms[player.get_xcoord()][player.get_ycoord()].set_desc("A large dining table spans the centre of the room with benches either side of it.\n\tAn old family crest can be seen on the table.\n\tThere's an open door to the north leading to the Kitchen.");                        
                cout << "\tYou place the Steel key in the keyhole of the wooden door and turn it slowly.\n\tThe locking mechanism grinds open and you push the door forward revealing the kitchen." << endl;
            } else if (inventory->at(item_choice - 1).get_name() == "Bucket" && player.get_xcoord() == 0 && player.get_ycoord() == 0) {
                player.remove_item(Item("Bucket", "\tUsed for carrying liquids and such.\n"));
                player.add_item(Item("Bucket of water", "\tA wooden bucket full of clear water.\n"));
                cout << "\tYou fill your bucket with water from the basin." << endl;
            } else if (inventory->at(item_choice - 1).get_name() == "Bucket of water" && player.get_xcoord() == 1 && player.get_ycoord() == 2 && flags[5] == 0) {
                flags[5] = 1;
                player.remove_item(Item("Bucket of water", "\tA wooden bucket full of clear water.\n"));
                player.add_item(Item("Bucket", "\tUsed for carrying liquids and such.\n"));
                rooms[2][2].add_item(Item("Golden key", "An expertly-made golden key with gems down it's side."));
                rooms[player.get_xcoord()][player.get_ycoord()].set_desc("This den appears to have been home to a burglar.\n\tThere are rags hanging from corner-to-corner of the roof and a tent against the south wall.\n\tThe rest of the room is packed with useless junk.\n\tThere is an old water drain in the ground against the east wall.");
                rooms[2][2].set_desc("There is an antique bathtub against the wall and small steps leading to a broken sink.\n\tAn old pipe is exposed which was once underground and none of the plumbing works.\n\tA golden glow can be seen coming from the exposed pipe...\n\tA passage to the south leads to the Old Sewers.");                        
                cout << "\tYou pour the water from your bucket down the drain and hear the clinking of metal in underground pipes..." << endl;
            } else if (inventory->at(item_choice - 1).get_name() == "Pickaxe" && player.get_xcoord() == 2 && player.get_ycoord() == 4 && flags[2] == 0) {
                flags[2] = 1;
                rooms[2][4].set_desc("An old kitchen with antique counter-tops and pots and pans lining the walls.\n\tThe western wall of the room has been knocked down and rubble clutters the floor...");
                cout << "\tYou hack away at the damaged western wall of the Kitchen...\n\tIt's not long before you break through and the wall falls to pieces.\n\tA room exists beyond the wall!" << endl;
            } else if (inventory->at(item_choice - 1).get_name() == "Unlit torch" && player.get_xcoord() == 3 && player.get_ycoord() == 2 && flags[4] == 0) {
                flags[4] = 1;
                player.remove_item(Item("Unlit torch", "\tA worn-looking wooden torch, although it's not lit now there are signs that it once was.\n"));
                rooms[3][2].set_desc("The walls are decorated with torn banners showing an old family crest.\n\tThe room is aglow with intense, never-fading torchlight.\n\tThere is a passage in the southern wall which was previously blocked by a throne.");
                cout << "\tYou place the Unlit torch in the empty sconce on the wall.\n\tSuddenly, it lights as if struck by an invisible match and the flames of all of the torches intesify...\n\tYou hear the grinding of gears and the throne begins to lower slowly into the flooring\n\tA hidden passage is revealed where it stood." << endl;
            } else if (inventory->at(item_choice - 1).get_name() == "Golden key" && player.get_xcoord() == 1 && player.get_ycoord() == 4 && flags[3] == 0) {
                flags[3] = 1;
                rooms[1][4].set_desc("This kitchen was decommissioned long before the other.\n\tIt was sealed off by the wall that stood to the east, which is now a pile of rubble.\n\tThere is hardly anything left of what this kitchen once was.\n\tThere are broken jars in the doorway to the west.");
                cout << "\tYou unlock the door using the Golden key.\n\tOld broken jars fall through the door as you open it." << endl;
            } else {
                cout << "\tNothing interesting happens..." << endl;
            }
            sleep(4);
            new_line();
        }                
    } else {
        tab(2);
        cout << "< Inventory >" << endl;
        tab(2);
        cout << "Your inventory is empty." << endl;
        new_line();
    }
}

//function to search for items in a room and (maybe) pick them up
void search_for_items() {
    Room* current_room = &rooms[player.get_xcoord()][player.get_ycoord()];
    int item_choice = 1;
    while (item_choice > 0) {
        //if room is not empty, it can be listed
        if (current_room->get_loot_size() > 0) {
            current_room->list_loot();
            new_line();
            tab();
            cout << "Enter an item number to pick up that item or enter 0 to not pick up anything." << endl;
            tab();
            cout << "> ";
            cin >> item_choice;
            new_line();
            sleep();
            //to put items in player inventory and remove them from room loot if needed
            if (item_choice > 0 && item_choice <= current_room->get_loot_size()) {
                vector<Item>* loot = current_room->get_loot();
                //If the Steel key is being picked up, the desc for the Water Chamber must change
                if (loot->at(item_choice - 1).get_name() == "Steel key" && rooms[0][0].get_desc() != "A small, square room with a pedastal in the centre.\n\tA basin of water sits upon it.") {
                    rooms[0][0].set_desc("A small, square room with a pedastal in the centre.\n\tA basin of water sits upon it.");
                }
                //If the Golden key is being picked up, the desc for the Wash Room must change
                if (loot->at(item_choice - 1).get_name() == "Golden key" && rooms[2][2].get_desc() != "There is an antique bathtub against the wall and small steps leading to a broken sink.\n\tAn old pipe is exposed which was once underground and none of the plumbing works.\n\tA passage to the south leads to the Old Sewers.") {
                    rooms[2][2].set_desc("There is an antique bathtub against the wall and small steps leading to a broken sink.\n\tAn old pipe is exposed which was once underground and none of the plumbing works.\n\tA passage to the south leads to the Old Sewers.");
                }
                //If the Pickaxe is being picked up, the desc for the Unfinished Excavation must change
                if (loot->at(item_choice - 1).get_name() == "Pickaxe" && rooms[3][4].get_desc() != "This excavation was abandoned mid-creation and it's creator lies against the wall to the west.\n\tThe ceiling is supported by rotting wooden shafts and looks as though it could collapse at any moment.\n\tWhat did he discover that led him to such a fate?") {
                    rooms[3][4].set_desc("This excavation was abandoned mid-creation and it's creator lies against the wall to the west.\n\tThe ceiling is supported by rotting wooden shafts and looks as though it could collapse at any moment.\n\tWhat did he discover that led him to such a fate?");
                }
                //If the Bucket is being picked up, the desc for the Tomb Entrance must change
                if (loot->at(item_choice - 1).get_name() == "Bucket" && rooms[1][1].get_desc() != "Two large, ornate doors stand wide-open to the south... the air grows colder as you approach them.\n\tIn the north-eastern corner of the room there are some skeletons.") {
                    rooms[1][1].set_desc("Two large, ornate doors stand wide-open to the south... the air grows colder as you approach them.\n\tIn the north-eastern corner of the room there are some skeletons.");
                }
                //If the Unlit torch is being picked up, the desc for the Scullery must change
                if (loot->at(item_choice - 1).get_name() == "Unlit torch" && rooms[0][3].get_desc() != "Broken plates and goblets lay piled up on the counters and in cabinets on the walls.\n\tThere is a rather large dried-blood stain on the ground next to the eastern wall.\n\tThis appears to be a dead end.") {
                    rooms[0][3].set_desc("Broken plates and goblets lay piled up on the counters and in cabinets on the walls.\n\tThere is a rather large dried-blood stain on the ground next to the eastern wall.\n\tThis appears to be a dead end.");
                }
                if (loot->at(item_choice - 1).get_name() == "Treasures") {
                    tab();
                    cout << "Maybe you should investigate the staircase to the south first." << endl;
                    new_line();
                    sleep(2);                             
                } else {
                    player.add_item(loot->at(item_choice - 1));
                    tab();
                    cout << "You pick up the " << loot->at(item_choice - 1).get_name() << "." << endl;
                    new_line();
                    current_room->remove_item(loot->at(item_choice - 1));
                    sleep(2);                            
                }
            }
        //otherwise room is empty, so print this and return                
        } else {
            tab(2);
            cout << "< Items in this room >" << endl;
            tab(2);
            cout << "There are no items in this room." << endl;
            new_line();
            item_choice = 0;
        }
    }
}

//move north function
void move_player_north() {
    tab();
    if (player.move_north(&flags)) {
        if (player.get_xcoord() == 2 && player.get_ycoord() == 4) {
            cout << "You walk north through the door and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                                        
        } else {
            cout << "You walk north through a passage and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        }
    } else {
        if (player.get_xcoord() == 2 && player.get_ycoord() == 3) {
            cout << "You try to open the door to the north but it's locked tight." << endl;
        } else {
            cout << "A wall blocks your way. You cannot walk north from here." << endl;
        }
    }
    sleep(3);
    new_line();
}

//move south function
void move_player_south() {
    tab();
    if (player.move_south(&flags)) {
        if (player.get_xcoord() == 2 && player.get_ycoord() == 3) {
            cout << "You walk south through the door and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                                        
        } else {
            cout << "You walk south through a passage and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        }
    } else {
        if (player.get_xcoord() == 2 && player.get_ycoord() == 4) {
            cout << "You try to open the door to the south but it's locked tight." << endl;
        } else {
            cout << "A wall blocks your way. You cannot walk south from here." << endl;
        }
    }
    sleep(3);
    new_line();
}

//move east function
void move_player_east() {
    tab();
    if (player.move_east(&flags)) {
        if (player.get_xcoord() == 1 && player.get_ycoord() == 4) {
            cout << "You walk east through the door and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } else if (player.get_xcoord() == 1 && player.get_ycoord() == 0) {
            cout << "You walk east through the door and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } else if (player.get_xcoord() == 2 && player.get_ycoord() == 4) {
            cout << "You walk east through the broken wall and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } else {
            cout << "You walk east through a passage and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } 
    } else {
        if (player.get_xcoord() == 0 && player.get_ycoord() == 4) {
            cout << "You try to open the door to the east but it's locked tight." << endl;
        } else if (player.get_xcoord() == 0 && player.get_ycoord() == 0) {
            cout << "You try to open the door to the east but it's locked tight." << endl;
        } else {
            cout << "A wall blocks your way. You cannot walk east from here." << endl;
        }              
    }
    sleep(3);
    new_line();
}

//move west function
void move_player_west() {
    tab();
    if (player.move_west(&flags)) {
        if (player.get_xcoord() == 0 && player.get_ycoord() == 4) {
            cout << "You walk west through the door and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } else if (player.get_xcoord() == 0 && player.get_ycoord() == 0) {
            cout << "You walk west through the door and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } else if (player.get_xcoord() == 1 && player.get_ycoord() == 4) {
            cout << "You walk west through the broken wall and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        } else {
            cout << "You walk west through a passage and reach the " << rooms[player.get_xcoord()][player.get_ycoord()].get_name() << "." << endl;                    
        }                
    } else {
        if (player.get_xcoord() == 1 && player.get_ycoord() == 4) {
            cout << "You try to open the door to the west but it's locked tight." << endl;
        } else if (player.get_xcoord() == 1 && player.get_ycoord() == 0) {
            cout << "You try to open the door to the west but it's locked tight." << endl;
        } else {
            cout << "A wall blocks your way. You cannot walk west from here." << endl;
        }
    }
    sleep(3);
    new_line();
}

//inventory function (list, get item descriptions, drop items)
void access_inventory() {
    int function_choice = 1;
    while (function_choice > 0) {
        //if inventory is not empty, it can be listed
        if (player.get_inventory_size() > 0) {
            player.list_inventory();
            new_line();
            tab();
            cout << "Enter 1 for item descriptions, enter 2 to drop an item, or enter 0 to exit inventory." << endl;
            tab();
            cout << "> ";
            cin >> function_choice;
            new_line();
            sleep();                    
            //enter item description mode
            if (function_choice == 1) {
                int item_choice = 1;
                //while items are being chosen for description
                while (item_choice > 0) {
                    player.list_inventory();
                    new_line();
                    tab();
                    cout << "Enter an item number for a description of that item or enter 0 to exit to inventory." << endl;
                    tab();
                    cout << "> ";
                    cin >> item_choice;
                    new_line();
                    sleep();
                    //to print item descriptions if needed.
                    if (item_choice > 0 && item_choice <= player.get_inventory_size()) {
                        cout << inventory->at(item_choice - 1).get_desc() << endl;
                        sleep(2);
                    }
                }
            }                    
            //enter item removal mode
            if (function_choice == 2) {
                int item_choice = 1;
                while (item_choice > 0) {
                    //if inventory is not empty, it can be listed (check since inventory can be changed in this mode)
                    if (player.get_inventory_size() > 0) {
                        player.list_inventory();
                        new_line();
                        tab();
                        cout << "Enter an item number to drop that item or enter 0 to exit to inventory." << endl;
                        tab();
                        cout << "> ";
                        cin >> item_choice;
                        new_line();
                        sleep();
                        //to drop an item if needed.
                        if (item_choice > 0 && item_choice <= player.get_inventory_size()) {
                            //add the item to the current room
                            Room* current_room = &rooms[player.get_xcoord()][player.get_ycoord()];
                            current_room->add_item(inventory->at(item_choice - 1));
                            //print message
                            tab();
                            cout << "You lay the " << inventory->at(item_choice - 1).get_name() << " down on the floor." << endl;
                            new_line();
                            //remove the item from the player's inventory
                            player.remove_item(inventory->at(item_choice - 1));
                            sleep(2);
                        }
                    } else {
                        tab(2);
                        cout << "< Inventory >" << endl;
                        tab(2);
                        cout << "Your inventory is empty." << endl;
                        new_line();
                        item_choice = 0;
                        function_choice = 0;
                    }
                }
            }
        //otherwise inventory is empty, so print this and return
        } else {
            tab(2);
            cout << "< Inventory >" << endl;
            tab(2);
            cout << "Your inventory is empty." << endl;
            new_line();
            function_choice = 0;
        }        
    }
}

//plays the game
void play_game() {   
    //initialize objects
    init_player(&player);
    init_map((Room*)rooms);
    int choice = -1;
    
    while (STATE == PLAY) {
        print_status();
        choice = get_player_choice();
        
        //Use an item function
        if (choice == 1) {
            use_item();
        //Look for items in the room function
        } else if (choice == 2) {        
            search_for_items();
        //Move north function
        } else if (choice == 3) {
            move_player_north();
        //Move south function
        } else if (choice == 4) {
            move_player_south();
        //Move east function
        } else if (choice == 5) {
            move_player_east();
        //Move west function
        } else if (choice == 6) {
            move_player_west();
        //Open inventory function
        } else if (choice == 7) {
            access_inventory();
        //Return to Main Menu function
        } else if (choice == 8) {
            STATE = MENU;
        }
        
        //if the Castle Grounds are reached, the game is over
        if (player.get_xcoord() == 3 && player.get_ycoord() == 0) {
            STATE = END_GAME;
        }
    }

    while (STATE == END_GAME) {
        tab();
        cout << "The stairs lead you outside to the Castle Grounds where you will make your escape...\n\tBut not before taking some of the treasure with you!" << endl;        
        sleep(4);
        new_line();
        tab();
        cout << "Congratulations, " << player.get_name() << ", you beat the game!" << endl;
        sleep(4);
        STATE = MENU;
    }
    
    //return to the menu
    STATE = MENU;
    sleep();
}

//main function
int main() {
    //print the Castle Escape logo
    print_logo();
    //loop
    while (STATE != STOP) {
        //menu
        if (STATE == MENU) {
            main_menu();
        } else if (STATE == PLAY) {
            play_game();
        } else if (STATE == END_GAME) {
            tab();
            cout << "Error: Wrong state (END_GAME)" << endl;
            sleep();
            STATE = MENU;
        }
    }
    
    //close game application
    new_line();
    tab();
    cout << "Thank you for playing Castle Escape! <3" << endl;
    sleep(2);
    return 0;
}