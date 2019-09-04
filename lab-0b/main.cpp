#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool is_correct_char (unsigned char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool comp (pair<string, double> a, pair<string, double> b) {
    return a.second < b.second;
}

int main(int argv, char** argc) {
    ifstream input("input.txt");
    ofstream output("output.csv");

    map <string, int> word_count;
    int all_words_count = 0;

    string str;
    while (!input.eof()) {
        getline(input, str, ' ');
        vector <string> words_in_line;
        int vec_index = 0;
        bool in_word = false;
        for (int i = 0; i < str.size(); ++i) {
            if (is_correct_char(str[i])) {
                if (in_word) {
                    words_in_line[vec_index].push_back(str[i]);
                }
                else {
                    words_in_line.emplace_back("");
                    words_in_line[vec_index].push_back(str[i]);
                    in_word = true;
                    all_words_count++;
                }
            }
            else {
                if (in_word) {
                    in_word = false;
                    vec_index++;
                }
            }
        }
        for (auto i : words_in_line) {
            if (word_count.find(i) == word_count.end()) {
                word_count[i] = 1;
            }
            else {
                word_count[i]++;
            }
        }
    }

    vector <pair <string, double>> frequencies;

    for (auto i : word_count) {
        frequencies.emplace_back(make_pair(i.first, (double) i.second / all_words_count));
    }
    
    sort (frequencies.rbegin(), frequencies.rend(), comp);

    for (auto i : frequencies) {
        output << i.first << "," << word_count[i.first] << "," << i.second << "\n";
    }
}
