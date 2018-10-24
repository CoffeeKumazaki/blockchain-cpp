#pragma once

#include <sstream>
#include <string>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

#define INVALID_HASH ("0000000000000000000000000000000000000000000000000000000000000000")

string sha256(const string str);