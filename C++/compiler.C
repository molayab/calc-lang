#include "compiler.h"

Compiler::Compiler() : ready(NO) { }

Compiler::~Compiler() { }

void Compiler::open(const char * name) {
	buffer << "main:" << tabl << "sp := 6" << endl;
	buffer << tabl << "one  := 1" << endl;
	buffer << tabl << "three  := 3" << endl;
	buffer << tabl << "sp := sp + one" << endl;
	
	file.open(name);
	
	if (file) {
		ready = YES;
	}
}

void Compiler::push(int i) {
	stringstream s;
	
	s << tabl << "tmp := " << i << endl;
	s << tabl << "M[sp + 0] := tmp" << endl;
	
	buffer << s.str();
}

void Compiler::prepare() {
	buffer << tabl << "sp := sp - three" << endl;
	buffer << tabl << "tmp := M[sp + 3]" << endl;
	buffer << tabl << "M[sp + 1] := tmp" << endl;
	buffer << tabl << "sp := sp + three" << endl;
}

void Compiler::init(bool isBinary) {
	if (isBinary) {
		buffer << tabl << "sp := sp + three" << endl;
	} else {
		buffer << tabl << "sp := sp + one" << endl;
	}
}

void Compiler::operate(TokenType type) {
	buffer << tabl << "sp := sp - three" << endl;
	buffer << tabl << "tmp := M[sp + 3]" << endl;
	buffer << tabl << "M[sp + 2] := tmp" << endl;
	buffer << tabl << "tmp := M[sp + 1]" << endl;
	buffer << tabl << "tmp2 := M[sp + 2]" << endl;
	
	switch (type) {
		case add:
			buffer << tabl << "tmp := tmp + tmp2" << endl;
			break;
		case sub:
			buffer << tabl << "tmp := tmp - tmp2" << endl;
			break;
		case times:
			buffer << tabl << "tmp := tmp * tmp2" << endl;
			break;
		case divide:
			buffer << tabl << "tmp := tmp / tmp2" << endl;
			break;
		default:
			break;
	}
	
	buffer << tabl << "M[sp + 0] := tmp" << endl;
}

void Compiler::pushStore() {
	buffer << tabl << "sp := sp - one" << endl;
	buffer << tabl << "tmp := M[sp + 1]" << endl;
	buffer << tabl << "M[sp + 0] := tmp" << endl;
	buffer << tabl << "mem := tmp" << endl;
}

void Compiler::pushRecall() {
	buffer << tabl << "M[sp + 0]:= mem" << endl;
}

void Compiler::write() {
	close();
	
	file << buffer.str();
	
	file.close();
	
	buffer.str("");
	buffer.str().clear();
	ready = NO;
}

bool Compiler::isReady() {
	return this->ready;
}

void Compiler::close() {
	buffer << tabl << "sp := sp - one" << endl;
	buffer << tabl << "tmp := M[sp + 1]" << endl;
	buffer << tabl << "writeInt(tmp)" << endl;
	buffer << tabl << "halt" << endl;
	buffer << "equ tmp   M[0]" << endl;
	buffer << "equ tmp2  M[1]" << endl;
	buffer << "equ uno   M[2]" << endl;
	buffer << "equ tres  M[3]" << endl;
	buffer << "equ mem   M[4]" << endl;
	buffer << "equ sp    M[5]" << endl;
	buffer << "equ stack M[6]" << endl;
}