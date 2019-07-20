#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

#include "ast.h"

//IntExp
int IntExp::eval() { return val; }

string IntExp::pretty() {
	return to_string(val);
}

string IntExp::cleverPretty() {
	return to_string(val);
}

std::shared_ptr<Exp> IntExp::getE1() {
	return 0;
};
std::shared_ptr<Exp> IntExp::getE2() {
	return 0;
};

//PlusExp
int PlusExp::eval() { return e1->eval() + e2->eval(); }

string PlusExp::pretty() {
	string s("(");
	s.append(e1->pretty());
	s.append("+");
	s.append(e2->pretty());
	s.append(")");
	return s;
}

string PlusExp::cleverPretty() {
	string s("");
	s.append(e1->cleverPretty());
	s.append("+");
	s.append(e2->cleverPretty());
	return s;
}

std::shared_ptr<Exp> PlusExp::getE1() {
	return e1;
};
std::shared_ptr<Exp> PlusExp::getE2() {
	return e2;
};

//MultExp
int MultExp::eval() { return e1->eval() * e2->eval(); }

string MultExp::pretty() {
	string s("(");
	s.append(e1->pretty());
	s.append("*");
	s.append(e2->pretty());
	s.append(")");
	return s;
}

string MultExp::cleverPretty() {
	string s("");
	if (typeid(*e1) == typeid(PlusExp)) {
		s.append("(");
		s.append(e1->cleverPretty());
		s.append(")");
	}
	else {
		s.append(e1->cleverPretty());
	}
	s.append("*");
	if (typeid(*e2) == typeid(PlusExp)) {
		s.append("(");
		s.append(e2->cleverPretty());
		s.append(")");
	}
	else {
		s.append(e2->cleverPretty());
	}
	return s;
}

std::shared_ptr<Exp> MultExp::getE1() {
	return e1;
};
std::shared_ptr<Exp> MultExp::getE2() {
	return e2;
};


EXP newInt(int i) {
	return std::make_shared<IntExp>(i);
}

EXP newPlus(EXP l, EXP r) {
	return std::make_shared<PlusExp>(l, r);
}

EXP newMult(EXP l, EXP r) {
	return std::make_shared<MultExp>(l, r);
}