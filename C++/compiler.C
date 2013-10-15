#include "compiler.h"

Compiler::Compiler() {
	
}

Compiler::~Compiler() {
	
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
	cout << tabl << "tmp := M[sp+3]" << endl;
	cout << tabl << "M[sp+2] := tmp" << endl;
	cout << tabl << "tmp := M[sp+1]" << endl;
	cout << tabl << "tmp2:= M[sp+2]" << endl;
	
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
	
	cout << tabl << "M[sp+0] := tmp" << endl;
}

void Compiler::pushStore() {
//	sp := sp - uno
//	tmp := M[sp+1]
//	M[sp+0] := tmp
//	mem := tmp
	
}

void Compiler::write() {
	
}

void Compiler::close(TokenType type) {
	
}