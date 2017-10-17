#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <map>

using namespace std;

/* --------------------------------------
 * Test Cases.
 * -------------------------------------- */
vector<string> expr0 = {
	"1", "+", "2", "+", "3", "+", "4", "+",
	"5", "+", "6", "+", "7", "+", "8", "+",
	"9", "+", "10"
}; // 55

vector<string> expr1 = {
	"1", "*", "2", "*", "3", "*", "4", "*",
	"5", "*", "6", "*", "7", "*", "8", "*",
	"9", "*", "10"
}; // 3628800

vector<string> expr2 = {
	"1", "+", "2", "*", "3", "+", "4"
}; // 11

vector<string> expr3 = {
	"1", "/", "2"
}; // 0.5

vector<string> expr4 = {
	"-1", "+", "2", "-", "3"
}; // -2

/* --------------------------------------
 * Supported Operations.
 * -------------------------------------- */
float add(float op0, float op1) { return op0 + op1; }
float sub(float op0, float op1) { return op0 - op1; }
float mul(float op0, float op1) { return op0 * op1; }
float div(float op0, float op1) { return op0 / op1; }

/**
 * Apply all input operations from left to right.
 * Operations are performed in the order in which they appear.
 * This function performs an in place modification of the input 'expr'.
 */
void apply(vector<string> &expr, map<string, float (*)(float,float)> operations) {
	for (auto it=expr.begin(); it != expr.end(); it++) {
		string val = *it;
		if (operations.count(val)) {
			auto operation = operations[val];

			// remove the first operand
			string str_op0 = *(--it);
			it = expr.erase(it); // it now points to the operator
			it = expr.erase(it); // it now points to the second operand

			string str_op1 = *(it);
			it = expr.erase(it);

			// convert to floating point values, perform our operation
			// then insert the result in the place of the 
			// operators and the operand
			auto op0 = (float)atof(str_op0.c_str());
			auto op1 = (float)atof(str_op1.c_str());
			string res = to_string(operation(op0, op1));
			expr.insert(it, res);
		}
	}
}

/**
 * Evalautes the input expression by performing
 * addition/subtraction and multiplication/division,
 * following the standard order of operations.
 * 'expr' is assumed to be valid.
 */
float evaluate(vector<string> expr) {
	map<string, float (*)(float,float)> pr0;
	pr0["*"] = mul;
	pr0["/"] = div;

	map<string, float (*)(float,float)> pr1;
	pr1["+"] = add;
	pr1["-"] = sub;

	apply(expr, pr0);
	apply(expr, pr1);
	return atof(expr.front().c_str());
}

int main(int argc, char ** argv) {
	cout << evaluate(expr0) << endl;
	cout << evaluate(expr1) << endl;
	cout << evaluate(expr2) << endl;
	cout << evaluate(expr3) << endl;
	cout << evaluate(expr4) << endl;
	return  0;
}
