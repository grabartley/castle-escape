/*This file contains function headers used to initialize the gamestate*/

//preprocessor
#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <string>

#include "room.h"
#include "player.h"
#include "helper.h"
using namespace std;

//function headers
//initializes the 2d map array for the game
void init_map(Room* rooms);

//initializes the player object for the game
void init_player(Player* player);

#endif