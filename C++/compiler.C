#include "compiler.h"

Compiler::Compiler() {
	
}

Compiler::~Compiler() {
	
}

void Compiler::open() {
	cout << "main:" << tabl << "sp := 6" << endl;
	cout << tabl << "one  := 1" << endl;
	cout << tabl << "three  := 3" << endl;
	cout << tabl << "sp := sp + one" << endl;
}

void Compiler::push(int i) {
	stringstream s;
	
	s << tabl << "tmp := " << i << endl;
	s << tabl << "M[sp + 0] := tmp" << endl;
	
	cout << s.str();
}

void Compiler::prepare() {
	cout << tabl << "sp := sp - three" << endl;
	cout << tabl << "tmp := M[sp + 3]" << endl;
	cout << tabl << "M[sp + 1] := tmp" << endl;
	cout << tabl << "sp := sp + three" << endl;
}

void Compiler::init(bool isBinary) {
	if (isBinary) {
		cout << tabl << "sp := sp + three" << endl;
	} else {
		cout << tabl << "sp := sp + one" << endl;
	}
}

void Compiler::operate(TokenType type) {
	cout << tabl << "sp := sp - three" << endl;
	cout << tabl << "tmp := M[sp + 3]" << endl;
	cout << tabl << "M[sp + 2] := tmp" << endl;
	cout << tabl << "tmp := M[sp + 1]" << endl;
	cout << tabl << "tmp2 := M[sp + 2]" << endl;
	
	switch (type) {
		case add:
			cout << tabl << "tmp := tmp + tmp2" << endl;
			break;
		case sub:
			cout << tabl << "tmp := tmp - tmp2" << endl;
			break;
		case times:
			cout << tabl << "tmp := tmp * tmp2" << endl;
			break;
		case divide:
			cout << tabl << "tmp := tmp / tmp2" << endl;
			break;
		default:
			break;
	}
	
	cout << tabl << "M[sp + 0] := tmp" << endl;
}

void Compiler::pushStore() {
	cout << tabl << "sp := sp - one" << endl;
	cout << tabl << "tmp := M[sp + 1]" << endl;
	cout << tabl << "M[sp + 0] := tmp" << endl;
	cout << tabl << "mem := tmp" << endl;
}

void Compiler::pushRecall() {
	cout << tabl << "M[sp + 0]:= mem" << endl;
}

void Compiler::write() {
	cout << tabl << "sp := sp - one" << endl;
	cout << tabl << "tmp := M[sp + 1]" << endl;
	cout << tabl << "writeInt(tmp)" << endl;
	cout << tabl << "halt" << endl;
	cout << "equ tmp   M[0]" << endl;
	cout << "equ tmp2  M[1]" << endl;
	cout << "equ uno   M[2]" << endl;
	cout << "equ tres  M[3]" << endl;
	cout << "equ mem   M[4]" << endl;
	cout << "equ sp    M[5]" << endl;
	cout << "equ stack M[6]" << endl;
}

void Compiler::close(TokenType type) {
	
}