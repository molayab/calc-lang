#include "parser.h"
#include "calcex.h"
#include "compiler.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in, bool prmpt) {
   scan = new Scanner(in);
	usePrompt = prmpt;
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return Prog();
}

AST* Parser::Prog() {
   AST* result = Expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
	   if (usePrompt) cout << "* ";
      cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
      throw ParseError;
   }

   return result;
}

AST* Parser::Expr() {
   return RestExpr(Term());
}

AST* Parser::RestExpr(AST* e) {
   Token* t = scan->getToken();
	
   if (t->getType() == add) {
	   //comp->operate(add);
	   return RestExpr(new AddNode(e,Term()));
   }

	if (t->getType() == sub) {
		return RestExpr(new SubNode(e,Term()));
	}
   scan->putBackToken();

   return e;
}

AST* Parser::Term() {
  return RestTerm(Storable());
}

AST* Parser::RestTerm(AST* e) {
  Token* t = scan->getToken();

	if (t->getType() == times) {
		return RestTerm(new MultNode(e, Storable()));
	}
	if (t->getType() == divide) {
		return RestTerm(new DivNode(e, Storable()));
	}

  scan->putBackToken();

  return e;
}

AST* Parser::Storable() {
  //cout << "Storable not implemented" << endl;
  AST * ret = Factor();
  Token  *t = scan->getToken();

  if (t->getType() == keyword) {
    if (t->getLex() == "S") {
      return new StoreNode(ret);
    } else {
		if (usePrompt) cout << "* ";
      cout << "Expected S" << endl;
      throw ParseError;
    }
  }

  scan->putBackToken();
  return ret;
  // throw ParseError; 
}

AST* Parser::Factor() {
  //cout << "Factor not implemented" << endl;
   
   Token *t = scan->getToken();
   
   if (t->getType() == number) {
     istringstream in(t->getLex());
     int val;
     in >> val;
	
	//comp->assign(t->getLex());
	   
     return new NumNode(val);
   } else if (t->getType() == keyword) {
     if (t->getLex() == "R") {
       return new RecallNode();
     } else {
		 if (usePrompt) cout << "* ";
       cout << "Expected R" << endl;
       throw ParseError;
     }
   } else if (t->getType() == lparen) {
     AST * ret = Expr();
     t = scan->getToken();
     
     if (t->getType() != rparen) {
		 if (usePrompt) cout << "* ";
       cout << "Expected )" << endl;
       throw ParseError;
     }
     return ret;
   }
	if (usePrompt) cout << "* ";
   cout << "Expeted number, R or (" << endl;
   throw ParseError; 
}
   
