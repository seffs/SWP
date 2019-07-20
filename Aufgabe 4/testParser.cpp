#include <iostream>
#include <string>

using namespace std;


#include "parser.h"
#include "ast.h"



void display(Optional<EXP> e) {
	if (e.isNothing()) {
		cout << "nothing \n";
	}
	else {
		cout << (e.fromJust())->pretty() << "\n";
	}
	return;
}

void displayClever(Optional<EXP> e) {
	if (e.isNothing()) {
		cout << "nothing \n";
	}
	else {
		cout << (e.fromJust())->cleverPretty() << "\n";
	}
	return;
}

void evalIt(Optional<EXP> e) {
	if (e.isNothing()) {
		cout << "nothing \n";
	}
	else {
		cout << (e.fromJust())->eval() << "\n";
	}
	return;
}

void testParserGood() {

	/*
	display(Parser("1").parse());

	display(Parser("1 + 0 ").parse());

	display(Parser("1 + (0) ").parse());

	display(Parser("1 + 2 * 0 ").parse());

	display(Parser("1 * 2 + 0 ").parse());
	*/

	display(Parser("(1 + 2) * 0 ").parse());
	display(Parser("(1 + 2) * 0 + 2").parse());
}

void testParser() {

	testParserGood();
}

void testCleverPrint(string exp) {
	cout << "Testing " << exp << "\n";
	
	if ((Parser(exp).parse()).isNothing()) {
		cout << "This is not a valid expression to test!" << "\n";
		cout << "\n";
		return;
	}
	
	cout << "With pretty: ";
	string pretStr = ((Parser(exp).parse()).fromJust())->pretty();
	cout << pretStr << "\n";
	int pretInt = ((Parser(pretStr).parse()).fromJust())->eval();

	cout << "With cleverPretty: ";
	string clevStr = ((Parser(exp).parse()).fromJust())->cleverPretty();
	cout << clevStr << "\n";
	int clevInt = ((Parser(clevStr).parse()).fromJust())->eval();

	if (pretInt == clevInt) {
		cout << "Test successful!" << "\n";
	}
	else {
		cout << "Test failed! pretty equals " << pretInt << " but cleverPretty equals " << clevInt << "\n";
	}
	cout << "\n";
	return;
}

void runCleverTests(string tests[], int amount) {
	for (int i = 0; i < amount; i++) {
		testCleverPrint(tests[i]);
	}
	return;
}
/*
int main() {

	//testParser();
	string testCases[] = {	
							"(1 + 2) * 0",
							"1 + 2 * (0 + 2)",
							"1 + (2 + 3)",
							"1",
							"(1 + 2) * (3 + 4)",
							"(2 + 2) * (1 * 1)",
							"(1 + 2) * (2 + (1 + 1))",
							"(1 + 2) * (2 * (1 + 1))",
							"(1 + 2)",
							"(1 * 2)"
	};
	runCleverTests(testCases, 10);
	return 1;
}*/