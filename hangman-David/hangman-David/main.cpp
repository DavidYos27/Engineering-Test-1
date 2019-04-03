#include<iostream>
#include<cstdio>
#include<ctime>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main() {

	unordered_map <string, vector<string>> myMap;
	vector<string> fruit;
	vector<string> animal;
	vector<string> country;

	fruit.push_back("apple");
	fruit.push_back("banana");
	fruit.push_back("watermelon");
	fruit.push_back("guava");
	fruit.push_back("orange");

	animal.push_back("dog");
	animal.push_back("cat");
	animal.push_back("elephant");
	animal.push_back("tiger");
	animal.push_back("bird");

	country.push_back("indonesia");
	country.push_back("france");
	country.push_back("usa");
	country.push_back("china");
	country.push_back("japan");
	country.push_back("korea");

	myMap["fruit"] = fruit;
	myMap["animal"] = animal;
	myMap["country"] = country;

	// Uncomment below to see the data
	//for (auto &i : myMap) {
	//	cout << i.first << endl;
	//	cout << "-----------" << endl;
	//	for (int j=0; j<i.second.size(); j++) {
	//		cout << i.second[j] << endl;
	//	}
	//	cout << endl;
	//}

	srand(time(NULL));
	auto categoryIndex = myMap.begin();
	advance(categoryIndex, rand() % myMap.size());

	string category = categoryIndex->first;

	auto ctgrElementIndex = myMap[category];
	int randomIndex = rand() % ctgrElementIndex.size();

	string selectedWord = ctgrElementIndex[randomIndex];
	cout << "Hint : " << category << " -> " << selectedWord << endl;

	vector<char> word;
	vector<char> currGuessContainer;
	unordered_map<char, int> repeatedChars;
	bool flag = false;
	int maxGuess = selectedWord.size();
	int correctGuess = 0;
	int wrongGuess = 0;
	string input;

	for (auto &c : selectedWord) {
		word.push_back(toupper(c));
		currGuessContainer.push_back('_');
	}

	while (wrongGuess != maxGuess && correctGuess != maxGuess) {

		cout << endl;
		getline(cin, input);

		if (input.size() > 1) {

			char tempInput1[20];
			char tempInput2[20];

			strcpy_s(tempInput1, input.c_str());
			strcpy_s(tempInput2, selectedWord.c_str());

			if (_strcmpi(tempInput1, tempInput2) == 0) {
				cout << "Correct!";
				break;
			}
			wrongGuess++;
			cout << "Wrong Guess!" << " Wrong guess = " << wrongGuess << ", Max = " << maxGuess << endl;
		}else{

			char tempInput[2];
			strcpy_s(tempInput, input.c_str());

			if (repeatedChars[toupper(tempInput[0])] > 0) {
				cout << "Letter " << char(toupper(tempInput[0])) << " already guessed." << endl;
				continue;
			}

			flag = false;

			for (int i=0; i<selectedWord.size(); i++) {
				if (word[i] == tempInput[0] || word[i] == toupper(tempInput[0])) {
					word[i] = '_';
					currGuessContainer[i] = toupper(tempInput[0]);
					repeatedChars[toupper(tempInput[0])] = 1;
					correctGuess++;
					flag = true;
				}
			}
			if (flag == false) {
				wrongGuess++;
				cout << "No letter " << tempInput[0] << ". Wrong guess = " << wrongGuess << ", Max = " << maxGuess << endl;
			}
			for (char &c : currGuessContainer) {
				cout << c << ' ';
			}
		}
		cout << endl;
	}

	if (wrongGuess == maxGuess) {
		cout << "Game Over";
	}

	getchar();
	return 0;
}