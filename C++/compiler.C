#include "compiler.h"

Compiler::Compiler() : need(0) {
	opt = new queue<string>;
}

Compiler::~Compiler() {
	delete opt;
}

void Compiler::init() {
	write("main:", YES);
	write("sp := 6");
	write("one := 1");
	write("three := 3");
	write("sp := sp + one");
}

void Compiler::close() {
	write("sp := sp - one");
	write("tmp := M[sp + 1]");
	write("writeInt(tmp)");
	write("halt");
	write("equ tmp M[0] ", YES);
	write("equ tmp2 M[1] ", YES);
	write("equ one M[2] ", YES);
	write("equ three M[3] ", YES);
	write("equ mem M[4] ", YES);
	write("equ sp M[5] ", YES);
	write("equ stack M[6] ", YES);
	write("");
}

void Compiler::assign(string str) {
	opt->push(str);
	
	if (need > 0) {
		compile();
	}
}

void Compiler::operate(TokenType type) {
	typ = type;
	
	switch (type) {
		case add:
			need = 2;
			break;
			
		default:
			break;
	}
}

void Compiler::compile() {
	stringstream s;
	
	int j = opt->size();
	
	for (int i = 0; i < j; ++i) {
		if (typ == add) {
			s << "tmp";
			if (i > 0) s << "2";
			
			s << " := " << opt->front() << endl;
			opt->pop();
		}
		
	}
	
	opt->empty();
	
	write(s.str());
}

void Compiler::write(string str, bool isFirstLine) {
	if (!isFirstLine) std::cout << tabl << str << endl;
	else std::cout << str;
}