#include "ast.h"
#include <iostream>
#include "calculator.h"
#include "compiler.h"

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{
	comp->init(add);
}

int AddNode::evaluate() {
	
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

MultNode::MultNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int MultNode::evaluate() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivNode::DivNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int DivNode::evaluate() {
   return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}



SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
	comp->push(val);
   return val;
}

StoreNode::StoreNode(AST * sub) : UnaryNode(sub) { }

int StoreNode::evaluate() {
  int tmp;
  tmp = getSubTree()->evaluate();
	comp->operate(keyword, "S");

  calc->store(tmp);

  return tmp;
}

RecallNode::RecallNode() : AST() { }

int RecallNode::evaluate() {
  return calc->recall();
}
