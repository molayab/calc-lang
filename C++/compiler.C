#include "compiler.h"

Compiler::Compiler() {
	buffer << "main:";
	buffer << tabl << "sp := 6" << endl;
	buffer << tabl << "one := 1" << endl;
	buffer << tabl << "three := 3" << endl;
}

Compiler::~Compiler() {
	
}

void Compiler::init(TokenType type) {
	if (isBinaryOperate(type)) {
		buffer << tabl << "sp := sp + three" << endl;
	} else {
		buffer << tabl << "sp := sp + one" << endl;
	}
}

void Compiler::push(int num) {
	buffer << tabl << "tmp := " << num << endl;
	buffer << tabl << "M[sp+0] := tmp" << endl;
}

void Compiler::operate(TokenType type, string keyword) {
	switch (type) {
		case add:
			break;
		case sub:
			break;
		case times:
			break;
		case divide:
			break;
		default:
			if (keyword == "S" || keyword == "s") {
				buffer << tabl << "sp := sp - one" << endl;
				buffer << tabl << "tmp := M[sp+1]" << endl;
				buffer << tabl << "M[sp+0] := tem" << endl;
				buffer << tabl << "men := tmp" << endl;
				
			}
			break;
	}
}

void Compiler::write() {
	cout << buffer.str() << endl;
}

bool Compiler::isBinaryOperate(TokenType type) {
	return (type == add || type == sub || type == times || type == divide);
}