/*This file contains helper function headers to be used throughout the application*/

//preprocessor
#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace std;

//function headers
//prints a varying amount of new lines, default is 1
void new_line(int num = 1);

//prints a varying amount of tab chars, default is 1
void tab(int num = 1);

//sleep for a varying amount of seconds, default is 1
void sleep(int time = 1);

#endif