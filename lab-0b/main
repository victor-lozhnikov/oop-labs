#include <string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

struct cmpByFreq {
	bool operator()(const string& a, const pair<string, int>& b) const {
		return b.second < b.first;
	}
};

int main(int argv, char** argc) {
	ifstream input("input.txt");
	ofstream output("output.csv");

	map <string, pair<int, double>> words;
	int word_count = 0;

	string str;
	while (!input.eof()) {
		getline(input, str, ' ');
		word_count++;
		if (words.find(str) == words.end()) {
			words[str].first = 1;
		}
		else {
			words[str].first++;
		}
		words[str].second = 1.0 / word_count;
	}



	for (auto i : words) {
		cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
	}
}
