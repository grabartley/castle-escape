/*This file contains helper functions to be used throughout the application*/

//preprocessor
#include "helper.h"

void new_line(int num) {
    for (int i = 0; i < num; i++) {
        cout << endl;
    }
}

void tab(int num) {
    for (int i = 0; i < num; i++) {
        cout << "\t";
    }
}

void sleep(int time) {
    this_thread::sleep_for(chrono::seconds(time));
}