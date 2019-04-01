#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <windows.h>

/*	This class, through its various functions, will serve to make formatting, getting input, and producing output easier. */

static class IO {
public:
	void static clearScreen();
	void static newLineSpace();
	std::string static stringInitial(std::string strVarToWriteTo);
	int static formattedDate();
};