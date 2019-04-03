#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string decrypt(int n, string word) {

	string result;
	int step = n % 26;

	for (char &c : word) {
		if (int(c) >= 65 && int(c) <= 90) {
			if ((int(c) + step) % 91 < 65) {
				result += char(65 + ((int(c) + step) % 91));
			}
			else {
				result += char(c + step);
			}
		}
		else if ((int(c) >= 97 && int(c) <= 122)) {
			if ((int(c) + step) % 123 < 97) {
				result += char(97 + ((int(c) + step) % 123));
			}
			else {
				result += char(c + step);
			}
		}
		else {
			result += c;
		}
	}

	return result;
}