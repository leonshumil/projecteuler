//Names Scores
//move the names to array size 5000
//convert names to numeric values use marge sort to sort sum index * index(value)

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int get_score(string name) {
    int score = 0;
    for (char c : name) {
        if (c >= 'A' && c <= 'Z') score += (c - 'A' + 1);
    }
    return score;
}

int main() {
    vector<string> names;
    ifstream f("q22_input.txt");

    if (!f.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string temp;
    while (getline(f, temp, ',')) {
        string cleaned = "";
        for (char c : temp) {
            if (c != '\"') cleaned += c;
        }
        names.push_back(cleaned);
    }
    f.close();

    sort(names.begin(), names.end()); 

    long long total_sum = 0;
    for (int i = 0; i < names.size(); ++i) {
        total_sum += (long long)(i + 1) * get_score(names[i]);
    }

    cout << "The total score is: " << total_sum << endl;

    return 0;
}