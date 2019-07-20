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

void display2(Optional<EXP> e) {
	if (e.isNothing()) {
		cout << "nothing \n";
	}
	else {
		cout << (e.fromJust())->smart() << "\n";
	}
	return;
}

void testParserGood() {

	cout << "Test1" << endl;
	cout << "Input: " << "1" << endl;
	cout << "Pretty & Smart Output: "; 
	display(Parser("1").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("1").parse());
	cout << endl;
	/*display(Parser("1").parse());  cout << "			1" << endl;*/

	cout << "Test2" << endl;
	cout << "Input: " << "1 + 0" << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("1 + 0").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("1 + 0").parse());
	cout << endl;
	/*display(Parser("1 + 0 ").parse());  	cout << "			1 + 0 " << endl;*/

	cout << "Test3" << endl;
	cout << "Input: " << "1 + (0) " << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("1 + (0) ").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("1 + (0)").parse());
	cout << endl;
	/*display(Parser("1 + (0) ").parse());     	cout << "			1 + (0) " << endl;*/

	cout << "Test4" << endl;
	cout << "Input: " << "1 + 2 * 0 " << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("1 + 2 * 0 ").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("1 + 2 * 0 ").parse());
	cout << endl;
	/*display(Parser("1 + 2 * 0 ").parse());  	cout << "			1 + 2 * 0 " << endl;*/

	cout << "Test5" << endl;
	cout << "Input: " << "1 * 2 + 0 " << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("1 * 2 + 0 ").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("1 * 2 + 0 ").parse());
	cout << endl;
	/*display(Parser("1 * 2 + 0 ").parse());	cout << "			1 * 2 + 0 " << endl;*/

	cout << "Test6" << endl;
	cout << "Input: " << "(1 + 2) * 0 " << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("(1 + 2) * 0 ").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("(1 + 2) * 0 ").parse());
	cout << endl;
	/*display(Parser("(1 + 2) * 0 ").parse());	cout << "			(1 + 2) * 0 " << endl;*/

	cout << "Test7" << endl;
	cout << "Input: " << "(1 + 9) * 0 + 2" << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("(1 + 9) * 0 + 2").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("(1 + 9) * 0 + 2").parse());
	cout << endl;
	/*display(Parser("(1 + 9) * 0 + 2").parse());	cout << "			(1 + 9) * 0 + 2" << endl;*/

	cout << "Test8" << endl;
	cout << "Input: " << "(1 + 0 + 2) * (0 * 2)" << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("(1 + 0 + 2) * (0 * 2)").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("(1 + 0 + 2) * (0 * 2)").parse());
	cout << endl;
	/*display(Parser("(1 + 0 + 2) * (0 * 2)").parse());	cout << "			(1 + 0 + 2) * (0 * 2)" << endl;*/

	cout << "Test9" << endl;
	cout << "Input: " << "(1 * (1 + 2))" << endl;
	cout << "Pretty & Smart Output: ";
	display(Parser("(1 * (1 + 2))").parse());
	cout << "Not That Smart Output: ";
	display2(Parser("(1 * (1 + 2))").parse());
	cout << endl;
	/*display(Parser("(1 * (1 + 2))").parse());	cout << "			(1 * (1 + 2))" << endl;*/
	



}

void testParser() {

	testParserGood();
}


int main() {

	testParser();

	return 1;
}