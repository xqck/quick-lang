#pragma once

// headers that are not mine
#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <vector>

// defines
#define wl(x) std::cout << x << std::endl;
#define wn(x) std::cout << x;

// vectors (lists / arrays) that contain important stuff
std::vector<std::string> dataTypes;
std::vector<std::string> keywords;

std::vector<std::vector<std::string, std::string>> globalVariables;

// headers that I created.
#include "commonfunctions.h"
