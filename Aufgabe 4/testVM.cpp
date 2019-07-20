#include <iostream>
#include <string>

using namespace std;

#include "vm.h"
#include "ast.h"
#include "parser.h"

void showVMRes(Optional<int> r) {
	if (r.isNothing())
		cout << "\nVM stack (top): empty";

	cout << "\nVM stack (top):" << r.fromJust();


}

vector<Code> makeCode(Optional<EXP> e) {
	if (e.isNothing()) {
		throw "Not a valid expression!";
	}
	vector<Code> instr;
	if (typeid(*(e.fromJust())) == typeid(IntExp)) {
		instr.push_back(newPush((e.fromJust())->eval()));
	}
	else {
		if (typeid(*((e.fromJust())->getE1())) != typeid(IntExp)) {
			vector<Code> newIntr = makeCode((e.fromJust())->getE1());
			for (int i = 0; i < newIntr.size(); i++) {
				instr.push_back(newIntr[i]);
			}
		}
		else {
			instr.push_back(newPush(((e.fromJust())->getE1())->eval()));
		}
		if (typeid(*((e.fromJust())->getE2())) != typeid(IntExp)) {
			vector<Code> newIntr = makeCode((e.fromJust())->getE2());
			for (int i = 0; i < newIntr.size(); i++) {
				instr.push_back(newIntr[i]);
			}
		}
		else {
			instr.push_back(newPush(((e.fromJust())->getE2())->eval()));
		}
		if (typeid(*(e.fromJust())) == typeid(PlusExp)) {
			instr.push_back(newPlus());
		}
		else if (typeid(*(e.fromJust())) == typeid(MultExp)) {
			instr.push_back(newMult());
		}
	}
	return instr;
}

void testVM() {

	{
		vector<Code> vc{
			newPush(1),
			newPush(2),
			newPush(3),
			newMult(),
			newPlus() };

		Optional<int> res = VM(vc).run();

		showVMRes(res);
	}

	{
		vector<Code> vc{
			newPush(2),
			newPush(3),
			newPush(5),
			newPlus(),
			newMult() };

		Optional<int> res = VM(vc).run();

		showVMRes(res);
	}
	
	{	
		Optional<EXP> ex = Parser("(1 + 2) * 2 ").parse();
		vector<Code> vc = makeCode(ex);

		Optional<int> res = VM(vc).run();

		showVMRes(res);
	}
}

void testIt(string testCase) {
	cout << "Testing expression: " << testCase << "\n";

	if ((Parser(testCase).parse()).isNothing()) {
		cout << "This is not a valid expression to test!" << "\n";
		cout << "\n";
		return;
	}

	int interpretSol = ((Parser(testCase).parse()).fromJust())->eval();
	cout << "Interpreter solution: " << interpretSol << "\n";

	vector<Code> vmCode = makeCode(Parser(testCase).parse());
	Optional<int> vmStack = VM(vmCode).run();
	int vmSol = vmStack.fromJust();
	cout << "VM solution: " << vmSol << "\n";

	if (interpretSol == vmSol) {
		cout << "Test successful!" << "\n";
	}
	else {
		cout << "Test NOT successful!" << "\n";
	}
	cout << "\n";
	return;
}

void runVMTests(string testCases[], int amount) {
	for (int i = 0; i < amount; i++) {
		testIt(testCases[i]);
	}
	return;
}

int main() {

	//testVM();
	
	string testCases[] = {
		"(1 + 2) * 2 ",
		"1 + 2 * (0 + 2)",
		"1",
		"1 + (2 + 3)",
		"2 * 1 * (2 + 2 + 1)",
		"(2 + 2)",
		"(1 * 2)",
		"(1 + 2) * (2 * (1 + 1))"

	};
	runVMTests(testCases, 8);

	return 1;
}