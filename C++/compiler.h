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

class Compiler {
private:
	ofstream file;
	stringstream buffer;
	bool ready;
	void close();
	
public:
	Compiler();
	~Compiler();
	void open(const char *);
	void push(int);
	void prepare();
	void init(bool);
	void pushStore();
	void pushRecall();
	void operate(TokenType);
	void write();
	bool isReady();
};

extern Compiler * comp;

#endif