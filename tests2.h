#ifndef TESTS_2_H
#define TESTS_2_H

#include <iostream>
#include <vector>

using namespace std;

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

#endif
