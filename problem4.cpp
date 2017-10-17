#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <tuple>
#include <set>
#include <map>

#include "tests4.h"

using namespace std;

#define KING_REQ 2

/**
 * Constructs a set of neigboring vertices
 * associated with each vertex in a map.
 * We can then take unions of these sets to simulate
 * jumps in the graph.
 */
map<string, set<string>> get_neighbors(const vector<string> &V, 
		const vector<tuple<string,string>> &E) {
	map<string, set<string>> ret;

	// iterate over edges, adding reachable neighbors
	// to each starting vertices neighbors set
	for (auto e : E) {
		const auto from = get<0>(e);
		const auto to = get<1>(e);
		ret[from].insert(to);
	}

	return ret;
}

/**
 * Recursively performs jumps to build a set of reachable nodes
 * in a maximum of J jumps. 
 *
 * @param N Neighbors map for all vertices, 
 * 	this can be generated via a call to get_neighbors.
 * @param J Maximum number of jumps we're allowed to take to reach nodes.
 * @param Reach	Initially should only contain the starting vertex.
 */
void reachable(map<string, set<string>> &N, 
		const int J, set<string> &Reach) {
	if (J == 0) {
		// base case: no more jumps left
		return;
	}
	
	// after making one more jump, we can now reach
	// neighbors of found vertices
	// don't add them until we're done though
	// as we don't want to mess with iteration
	set<string> next;
	for (auto found : Reach) {
		for (auto add : N[found]) {
			next.insert(add);
		}
	}

	// after the additional jump, we can now also reach
	// elements of 'next', go ahead and add all of these to Reach
	for (auto n : next) { Reach.insert(n); }

	// one jump down, J-1 to go!
	reachable( N, J-1, Reach);
}

/**
 * Utility call to reachable which sets up the initial set, and returns 
 * the result.
 *
 * @return Vertices reachable from V in J jumps.
 */
set<string> reachable(const string start, map<string, set<string>> &N,
		const int J) {
	// the only node reachable in 0 jumps is ourself
	set<string> R = { start };

	// redirect to the recursive implementation to build R
	reachable(N, J, R);

	// reachable modifies R in place, so we can now return it
	return R;
}

/**
 * Determines the set of reachable vertices starting from V
 * in KING_REQ jumps or less.
 */
bool is_king(const string start, const unsigned vcount, map<string, set<string>> &N) {
	auto R = reachable(start, N, KING_REQ);

	// R subset V & |R| = |V| implies R = V
	return R.size() == vcount;
}

/* --------------
 * Main & Testing
 * -------------- */

void test(string name, vector<tuple<string, string>> E) {
	cout << "TEST: " << name << endl;

	// construct the vector of vertices by searching for 
	// all nodes present in the list of edges
	set<string> _V;
	for (auto e : E) {
		_V.insert(get<0>(e));
		_V.insert(get<1>(e));
	}
	vector<string> V(_V.begin(), _V.end());

	auto N = get_neighbors(V, E);
	cout << "KINGS: { ";
	for (auto v : V) {
		if (is_king(v, V.size(), N)) {
			cout << v << " ";
		}
	}
	cout << "}" << endl;

	cout << "-----------------------------------" << endl << endl;
}

int main(int argc, char ** argv) {
	test("E0", E0);
	test("E1", E1);
	test("E2", E2);
	test("E3", E3);
	test("E4", E4);
	return 0;
}
