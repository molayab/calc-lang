#include "ast.h"

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
	comp->prepare();
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
{ }

AddNode::~AddNode() { }

int AddNode::evaluate() {
	comp->init(YES);
	int ret = getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
	comp->operate(add);
	comp->close(add);
	
	return ret;
}

MultNode::MultNode(AST* left, AST* right):
   BinaryNode(left,right)
{ }

MultNode::~MultNode() { }

int MultNode::evaluate() {
	comp->init(YES);
	int ret = getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
	comp->operate(times);
	comp->close(times);
	
	return ret;
}

DivNode::DivNode(AST* left, AST* right):
   BinaryNode(left,right)
{ }

DivNode::~DivNode() { }

int DivNode::evaluate() {
	comp->init(YES);
	int ret = getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
	comp->operate(divide);
	comp->close(divide);
	
	return ret;
}



SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{ }

SubNode::~SubNode() { }

int SubNode::evaluate() {
	comp->init(YES);
	int ret = getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
	comp->operate(sub);
	comp->close(sub);
   
	return ret;
}

NumNode::NumNode(int n) :
   AST(),
   val(n)
{ }

NumNode::~NumNode () { }

int NumNode::evaluate() {
	comp->push(val);
   return val;
}

StoreNode::StoreNode(AST * sub) : UnaryNode(sub)
{ }

StoreNode::~StoreNode() { }

int StoreNode::evaluate() {
	comp->init(NO);
  int tmp;
  tmp = getSubTree()->evaluate();

  calc->store(tmp);
	comp->pushStore();
  return tmp;
}

RecallNode::RecallNode() : AST()
{ }

RecallNode::~RecallNode () { }

int RecallNode::evaluate() {
	int ret = calc->recall();
	comp->pushRecall();
	
	return ret;
}
