#ifndef TESTS_4_H
#define TESTS_4_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

/* --------------------------------------
 * Test Cases.
 * --------------------------------------
 * I will build the list of vertices
 * out of all strings found in the edge
 * tuples. I am not enforcing
 * the strict assumption that there is an
 * edge between every pair of vertices.
 * My solution will work in general.
 * -------------------------------------- */
vector<tuple<string, string>> E0 = {
	make_tuple("A", "B"),
	make_tuple("B", "C"),
	make_tuple("A", "C")
}; // KINGS = { A }

vector<tuple<string, string>> E1 = {
	make_tuple("A", "B"),
	make_tuple("B", "C"),
	make_tuple("C", "A")
}; // KINGS = { A, B, C }

vector<tuple<string, string>> E2 = {
	make_tuple("A", "B"),
	make_tuple("B", "C"),
	make_tuple("C", "D"),
	make_tuple("D", "A")
}; // KINGS = { }

vector<tuple<string, string>> E3 = {
	make_tuple("A", "B"),
	make_tuple("A", "C"),
	make_tuple("A", "D"),
	make_tuple("B", "D"),
	make_tuple("B", "C"),
	make_tuple("C", "D")
}; // KINGS = { A }

vector<tuple<string, string>> E4 = {
	make_tuple("A", "B"),
	make_tuple("A", "C"),
	make_tuple("D", "A"),
	make_tuple("C", "D"),

	make_tuple("B", "D"),
	make_tuple("B", "C")
}; // KINGS = { A, B, D }

#endif
