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
			buffer << tabl << "sp := sp - 3" << endl;
			buffer << tabl << "tmp := M[sp+3]" << endl;
			buffer << tabl << "M[sp+2] := tmp" << endl;
			buffer << tabl << "tmp := M[sp+1]" << endl;
			buffer << tabl << "tmp2 := M[sp+2]" << endl;
			buffer << tabl << "tmp := tmp + tmp2" << endl;
			buffer << tabl << "M[sp+0] := tmp" << endl;
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
	buffer << tabl << "sp := sp - one" << endl;
	buffer << tabl << "tmp := M[sp+1]" << endl;
	buffer << tabl << "writeInt(tmp)" << endl;
	buffer << tabl << "halt" << endl;
	buffer << "equ tmp   M[0]" << endl;
	buffer << "equ tmp2  M[1]" << endl;
	buffer << "equ uno   M[2]" << endl;
	buffer << "equ tres  M[3]" << endl;
	buffer << "equ mem   M[4]" << endl;
	buffer << "equ sp    M[5]" << endl;
	buffer << "equ stack M[6]" << endl;
	cout << buffer.str() << endl;
}

bool Compiler::isBinaryOperate(TokenType type) {
	return (type == add || type == sub || type == times || type == divide);
}