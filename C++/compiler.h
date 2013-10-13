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
#define tabl "\t"

using namespace std;

class Compiler {
private:
	stringstream buffer;
	bool isBinaryOperate(TokenType);

public:
	Compiler(); // Costruir el objeto y el archivo
	~Compiler(); // destruir el objeto y cerrar el archivo
	void init(TokenType); // Inicia un nuevo nodo
	void push(int); // Crea un NumNode (EWE) con un int
	void operate(TokenType, string=""); // Crea la operacion en EWE
	void write(); // Guarda el buffer en el archivo
};

extern Compiler * comp;

#endif