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

void update_count (map <string, int>* m, string* s) {
    if (m->find(*s) == m->end()) {
        (*m)[*s] = 1;
    }
    else {
        (*m)[*s]++;
    }
}

int main(int argv, char** argc) {
    ifstream input("input.txt");
    ofstream output("output.csv");

    map <string, int> word_count;
    int all_words_count = 0;

    string str;
    while (!input.eof()) {
        getline(input, str, ' ');
        bool in_word = false;
        string cur_str = "";
        for (int i = 0; i < str.size(); ++i) {
            if (is_correct_char(str[i])) {
                cur_str += tolower(str[i]);
                if (!in_word) {
                    in_word = true;
                    all_words_count++;
                }
            }
            else if (in_word) {
                update_count(&word_count, &cur_str);
                in_word = false;
                cur_str = "";
            }
        }
        if (cur_str != "") {
            update_count(&word_count, &cur_str);
            cur_str = "";
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
