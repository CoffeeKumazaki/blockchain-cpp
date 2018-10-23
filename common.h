/**
 * @file common.h
 * @author Kohei Kumazaki 
 * @brief include libraries
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#pragma once

#include <iostream>

#include <ctime>
#include <string>

#include <vector>
#include <list>
#include <map>

#include <openssl/sha.h>

using namespace std;

#define IS_VALID(val, min, max) ( min <= val && val < max )