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
	if (comp->isReady()) comp->prepare();
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
	if (comp->isReady()) comp->init(YES);
	int ret = getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
	if (comp->isReady()) comp->operate(add);
	
	return ret;
}

MultNode::MultNode(AST* left, AST* right):
BinaryNode(left,right)
{ }

MultNode::~MultNode() { }

int MultNode::evaluate() {
	if (comp->isReady()) comp->init(YES);
	int ret = getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
	if (comp->isReady()) comp->operate(times);
	
	return ret;
}

DivNode::DivNode(AST* left, AST* right):
BinaryNode(left,right)
{ }

DivNode::~DivNode() { }

int DivNode::evaluate() {
	if (comp->isReady()) comp->init(YES);
	int ret = getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
	if (comp->isReady()) comp->operate(divide);
	
	return ret;
}



SubNode::SubNode(AST* left, AST* right):
BinaryNode(left,right)
{ }

SubNode::~SubNode() { }

int SubNode::evaluate() {
	if (comp->isReady()) comp->init(YES);
	int ret = getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
	if (comp->isReady()) comp->operate(sub);
	
	return ret;
}

NumNode::NumNode(int n) :
AST(),
val(n)
{ }

NumNode::~NumNode () { }

int NumNode::evaluate() {
	if (comp->isReady()) comp->push(val);
	return val;
}

StoreNode::StoreNode(AST * sub) : UnaryNode(sub)
{ }

StoreNode::~StoreNode() { }

int StoreNode::evaluate() {
	if (comp->isReady()) comp->init(NO);
	int tmp = getSubTree()->evaluate();
	
	calc->store(tmp);
	if (comp->isReady()) comp->pushStore();
	return tmp;
}

RecallNode::RecallNode() : AST()
{ }

RecallNode::~RecallNode () { }

int RecallNode::evaluate() {
	int ret = calc->recall();
	if (comp->isReady()) comp->pushRecall();
	
	return ret;
}
