/*This file contains function definitions used to initialize the gamestate*/

//preprocessor
#include "init.h"

void init_map(Room* rooms) {
    //rooms[a][b] = rooms + a * bSize + b
    
    //0,0 will have a water pool in it
    *(rooms + 0 * 5 + 0) = Room(0, 0, "Water Chamber", "A small, square room with a pedastal in the centre.\n\tA basin of water sits upon it and you notice something shiny lies within." , Item("Steel key", "\tA shiny key with intricate designs on it's sides. it is made from firm steel.\n"));
    *(rooms + 0 * 5 + 1) = Room(0, 1, "Catacombs", "Small inlets line the walls where stone coffins once were... some still remain.\n\tThere is an opening to the east.");
    *(rooms + 0 * 5 + 2) = Room(0, 2, "Undercroft", "A dark room with wet soil walls and tree roots lining the ceiling.\n\tA tunnel can be seen in the southern wall, leading further down...");
    *(rooms + 0 * 5 + 3) = Room(0, 3, "Scullery", "Broken plates and goblets lay piled up on the counters and in cabinets on the walls.\n\tThere is a rather large dried-blood stain on the ground and in it, a small torch lies next to the eastern wall.\n\tThis appears to be a dead end." , Item("Unlit torch", "\tA worn-looking wooden torch, although it's not lit now there are signs that it once was.\n"));
    *(rooms + 0 * 5 + 4) = Room(0, 4, "Pantry", "Shelving surrounds this small, closet-like room.\n\tThere are cobwebs and smashed jars everywhere and a doorway to the south.\n\tThe door seems to be lying on the ground with it's hinges smashed...");
    
    *(rooms + 1 * 5 + 0) = Room(1, 0, "Tomb of a Queen", "This burial chamber is highly decorative, but lacking in treasures...\n\tThere are markings in the dust of where items of value once were.\n\tA stone coffin with signs of attempted burglary lays sealed in the centre of the tomb.\n\tA rusted iron door stands sealed in the western wall.");
    *(rooms + 1 * 5 + 1) = Room(1, 1, "Tomb Entrance", "Two large, ornate doors stand wide-open to the south... the air grows colder as you approach them.\n\tIn the north-eastern corner of the room amongst some skeletons lies a wooden bucket." , Item("Bucket", "\tUsed for carrying liquids and such.\n"));
    //1,2 will have the small golden key in a drain
    *(rooms + 1 * 5 + 2) = Room(1, 2, "Thief's Den", "This den appears to have been home to a burglar.\n\tThere are rags hanging from corner-to-corner of the roof and a tent against the south wall.\n\tThe rest of the room is packed with useless junk.\n\tYou notice an old water drain against the east wall, a golden shimmer can be seen beneath the metal grille...");
    *(rooms + 1 * 5 + 3) = Room(1, 3, "Hidden Tunnel", "A dark, damp and narrow tunnel possibly used to smuggle items out of the Dining Room.");
    *(rooms + 1 * 5 + 4) = Room(1, 4, "Old Kitchen", "This kitchen was decommissioned long before the other.\n\tIt was sealed off by the wall that stood to the east, which is now a pile of rubble.\n\tThere is hardly anything left of what this kitchen once was but a sturdy-looking dark wood door in the western wall.\n\tIt appears to have a golden keyhole...");

    *(rooms + 2 * 5 + 0) = Room(2, 0, "Blockage", "A wall of collapsed rocks blocks you from moving further south.\n\tThis appears to be a dead end.", Item("Rusted key", "\tA small iron key, coated in dark brown rust.\n"));
    *(rooms + 2 * 5 + 1) = Room(2, 1, "Old Sewers", "The walls are made of a dark stone brick and the room dips in the centre where sewer water once flowed.\n\tThere appear to be passages to the north and south of you.");
    //2,2 will have a pipe exposed for the small golden key to come out
    *(rooms + 2 * 5 + 2) = Room(2, 2, "Wash Room", "There is an antique bathtub against the wall and small steps leading to a broken sink.\n\tAn old pipe is exposed which was once underground and none of the plumbing works.\n\tA passage to the south leads to the Old Sewers.");
    *(rooms + 2 * 5 + 3) = Room(2, 3, "Dining Room", "A large dining table spans the centre of the room with benches either side of it.\n\tAn old family crest can be seen on the table.\n\tThere's a wooden door with a grille to the north, a kitchen can be seen through the grille.");
    *(rooms + 2 * 5 + 4) = Room(2, 4, "Kitchen", "An old kitchen with antique counter-tops and pots and pans lining the walls.\n\tThe western wall of the room appears to be chipped in several places and severely cracked...");

    *(rooms + 3 * 5 + 0) = Room(3, 0, "Castle Grounds", "You have escaped the castle!");
    *(rooms + 3 * 5 + 1) = Room(3, 1, "Treasure Trove", "The secret passage leads to a massive chamber full of priceless gems and metals!\n\tThe chamber is brilliantly illuminated by fire trails running along the walls and ground.\n\tYou see rays of golden sunlight shining in from a staircase to the south...", Item("Treasures", "\tPriceless gems and metals!\n"));
    *(rooms + 3 * 5 + 2) = Room(3, 2, "Throne Room", "A solitary throne stands at the south wall with brilliant red carpet leading up to it.\n\tThe walls are decorated with torn banners showing an old family crest.\n\tThe room is aglow with never-fading torchlight. You notice one sconce is empty...");
    *(rooms + 3 * 5 + 3) = Room(3, 3, "Dug-Out Cavern", "This cavern is crudely cut out of the dirt and rock which seem to have collapsed in on an old parlour.\n\tThere is a tunnel to the north held up by wooden shafts and remnants of what was once a grand entrance to the east.");
    *(rooms + 3 * 5 + 4) = Room(3, 4, "Unfinished Excavation", "This excavation was abandoned mid-creation and it's creator lies against the wall to the west.\n\tHe is still grasping his pickaxe.\n\tThe ceiling is supported by rotting wooden shafts and looks as though it could collapse at any moment.\n\tWhat did he discover that led him to such a fate?" , Item("Pickaxe", "\tThis pickaxe appears to have been well used, perhaps it's previous owner started something they couldn't finish?\n"));
}

void init_player(Player* player) {
    player->reset();
    string name;
    new_line();
    tab();
    cout << "Enter a name for your character" << endl;
    tab();
    cout << "> ";
    cin >> name;
    player->set_name(name);
    new_line();
    sleep();
}