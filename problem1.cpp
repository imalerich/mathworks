#include <iostream>
#include <limits.h>
#include <vector>
#include <time.h>
#include <cmath>

using namespace std;

#define LAYOUT_SIZE (UCHAR_MAX+1)
#define NO_ROW -1

/**
 * Generates a layout array serving as a map between
 * ASCII characters and their corresponding row on a
 * keyborad layout. Input is a list of rows, each
 * row containing a string defining a keyboard row.
 * Any characters not present will be assigned a value of NO_ROW.
 */
int * gen_layout(vector<string> rows) {
	// create an empty layout where each character is not assigned a row
	int * layout = new int[LAYOUT_SIZE];
	for (int i=0; i<LAYOUT_SIZE; ++i) { layout[i] = NO_ROW; }

	for (int i=0; i<rows.size(); i++) {
		string row = rows[i];
		for (char c : row) {
			// upper and lower case are considered to be on the same row
			layout[tolower(c)] = i;
			layout[toupper(c)] = i;
		}
	}

	return layout;
}

/** QWERTY Layout. */
int * gen_qwerty() {
	vector<string> rows = {
		"qwertyuiop",
		"asdfghjkl",
		"zxcvbnm"
	};

	return gen_layout(rows);
}

/** DVORAK Layout. */
int * gen_dvorak() {
	vector<string> rows = {
		"pyfgcrl",
		"aoeuidhtns",
		"qjkxbmwvz"
	};

	return gen_layout(rows);
}

/**
 *  Returns the row of input character c in O(1) time.
 */
int get_row(char c, int * layout) {
	return layout[c];
}

bool is_single_row_string(string str, int * layout) {
	// all rows should be equivalent to the first character
	int r = get_row(str[0], layout);
	// character is part of an undefined row, return false
	if (r == NO_ROW) { return false; }

	for (auto c : str) {
		if (r != get_row(c, layout)) {
			return false;
		}
	}

	return true;
}

int main(int argc, char ** argv) {
	int * qwerty = gen_qwerty();
	int * dvorak = gen_dvorak();

	// List of sample test words to run against the QWERTY & DVORAK layout.
	vector<string> words = {
		"Alabama", "Alaska", "Arizona", "Arkansas", "Idaho", "Indiana",
		"QWERTY", "asdf", "QWERTYasdf", "123456789", "aoeu", "RCGF"
	};

	cout << "QWERTY:" << endl<< "-------" << endl;
	for (string word : words) {
		if (is_single_row_string(word, qwerty)) {
			cout << word << endl;
		}
	}

	cout << endl << "DVORAK:" << endl << "-------" << endl;
	for (string word : words) {
		if (is_single_row_string(word, dvorak)) {
			cout << word << endl;
		}
	}

	delete[] qwerty;
	delete[] dvorak;
	return 0;
}
