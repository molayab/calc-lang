#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "calcex.h"
#include "calculator.h"
#include "compiler.h"

// Macro, uso de booleanos y nulos como Objective-C
#define NO false
#define YES true
#define nil NULL

using namespace std;

Calculator* calc;
Compiler* comp;

string prompt;
bool isNormalMode;

void execute(char *argv);

int main(int argc, char* argv[]) {
   if (argc > 1) {
       // leer los argumentos pasados.
       if (argv[1][0] == '-') {
           for (int i = 0; i < strlen(argv[1]); ++i) {
               execute(&argv[1][i]);
           }
       } else {
           cout << "[WARNING] Expected a \"-\" before the argument" << endl;
       }
   } else {
       execute(argv[0]);
   }


	string line;
   
	calc = new Calculator();
	comp = new Compiler();
	
	do {
		try {
			cout << prompt;
			getline(cin, line);

			if (line == "<eof>" || line == "<EOF>") break;
			
			comp->init();
			int result = calc->eval(line, !isNormalMode);
			comp->close();
			
			if (isNormalMode) {
				cout << "The result is " << result << endl;
			} else {
				cout << "= " << result << endl;
			}
		} catch(Exception ex) {
			if (isNormalMode) {
				cout << "Program Aborted due to exception!" << endl;
			}
		}
	} while (!isNormalMode);
		
	delete calc;
	delete comp;
}

void execute(char *argv) {
    switch (*argv) {
        case 'i': 
            cout << "--> Recursion Actived..." << endl;
            prompt = "> ";
            isNormalMode = NO;
            break;
        case 'c':
            cout << "-> EWEMode actived" << endl;
            break;
        default:
            prompt = "Please enter a calculator expression: ";
            isNormalMode = YES;
            break;
    }
}
