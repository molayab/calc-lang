#ifndef ast_h
#define ast_h

#include <iostream>
#include "calculator.h"
#include "compiler.h"
#include "token.h"

//using namespace std; <<-- OJO CON ESTA LINEA

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
};

class BinaryNode : public AST {
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};

class AddNode : public BinaryNode {
 public:
   AddNode(AST* left, AST* right);
	~AddNode();
   
   int evaluate();
};

class MultNode : public BinaryNode {
 public:
   MultNode(AST* left, AST* right);
	~MultNode();
   
   int evaluate();
};

class DivNode : public BinaryNode {
 public:
   DivNode(AST* left, AST* right);
	~DivNode();
   
   int evaluate();
};

class SubNode : public BinaryNode {
 public:
   SubNode(AST* left, AST* right);
	~SubNode();

   int evaluate();
};

class NumNode : public AST {
 public:
   NumNode(int n);
	~NumNode();

   int evaluate();

 private:
   int val;
};

class StoreNode : public UnaryNode {
 public:
  StoreNode(AST * sub);
	~StoreNode();
	
  int evaluate();
};

class RecallNode : public AST {
 public:
  RecallNode();
	~RecallNode();
	
  int evaluate();

};

#endif

