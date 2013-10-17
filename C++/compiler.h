#ifndef compiler_h
#define compiler_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include "token.h"

#define YES true
#define NO false
#define nil NULL
#define tabl "\t"

using namespace std;

enum NodeType {
	terminal, nterminal
};

class Compiler {
private:
	
public:
	Compiler();
	~Compiler();
	void open();
	void push(int);
	void prepare();
	void init(bool);
	void pushStore();
	void pushRecall();
	void operate(TokenType);
	void write();
	void close(TokenType);
	
};

extern Compiler * comp;

#endif