#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::showpos;
using std::setfill;
using std::internal;
using std::noshowpos;
using std::setw;

typedef enum operation_code
{
	READ = 10, WRITE = 11,
	LOAD = 20, STORE = 21,
	ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33,
	BRANCH = 40, BRANCHNEG = 41, BRNACHNEG = 42, HALT = 43
}OperationCode;