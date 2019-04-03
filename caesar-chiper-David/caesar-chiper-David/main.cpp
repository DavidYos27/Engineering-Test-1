#include <iostream>
#include <assert.h>

using namespace std;

// Solution
#include "Decrypt.h"

int main() {

	string testCase1 = decrypt(28, "HeLlO WorLD?Z#");
	string testCase2 = decrypt(29, "HeLlO WorLD?Z#");
	string testCase3 = decrypt(30, "HeLlO WorLD?Z#");
	string testCase4 = decrypt(31, "HeLlO WorLD?Z#");
	string testCase5 = decrypt(32, "ABCDEF#ghijklm");
	string testCase6 = decrypt(33, "ABCDEF#ghijklm");
	string testCase7 = decrypt(34, "ABCDEF#ghijklm");

	// TestCases
	assert(testCase1 == "JgNnQ YqtNF?B#");
	cout << "testCase1 Successful" << endl;

	assert(testCase2 == "KhOoR ZruOG?C#");
	cout << "testCase2 Successful" << endl;

	assert(testCase3 == "LiPpS AsvPH?D#");
	cout << "testCase3 Successful" << endl;

	assert(testCase4 == "MjQqT BtwQI?E#");
	cout << "testCase4 Successful" << endl;

	assert(testCase5 == "GHIJKL#mnopqrs");
	cout << "testCase5 Successful" << endl;

	assert(testCase6 == "HIJKLM#nopqrst");
	cout << "testCase6 Successful" << endl;

	assert(testCase7 == "IJKLMN#opqrstu");
	cout << "testCase7 Successful" << endl;

	cout << endl << "Press any key to exit...";

	getchar();
	return 0;
}