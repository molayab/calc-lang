#ifndef compiler_h
#define compiler_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "token.h"

#define YES true
#define NO false
#define nil NULL
#define tabl "    "

using namespace std;

class Compiler {
private:
	queue<string> * opt;
	int need;
	TokenType typ;
	void write(string, bool=NO);
	void compile();

public:
	Compiler();
	~Compiler();
	void init();
	void assign(string);
	void operate(TokenType);
	void close();
};

extern Compiler * comp;

#endif