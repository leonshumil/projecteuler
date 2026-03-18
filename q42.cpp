//
/*
First we load the txt to vectors of strings (ai can do it easly) then let's just find the
 sequans of the 30 first iteration of the equation to a vector (seems like a good guess) calc each word value and search in the vector.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//ai wrote this
vector<string> load_words(string filename) {
    ifstream file(filename);
    vector<string> words;
    string temp;

    if (!file.is_open()) {
        cerr << "Could not open: " << filename << endl;
        return words; 
    }

    while (getline(file, temp, ',')) {
        if (!temp.empty() && temp.front() == '"') temp.erase(0, 1);
        if (!temp.empty() && temp.back() == '"') temp.pop_back();

        words.push_back(temp);
    }

    file.close();
    return words;
}
// i wrote this
vector<int> triangle_numers(int num){

 vector<int> triangle;
 int ans;

 for (int i = 1; i <= num; ++i ){
    ans = (i * (i + 1)) / 2;
    triangle.push_back(ans);
 }

  return triangle;
}

int word_is_tri(vector<string> word_list, vector<int> triangle_list) {
    int count = 0;

    for (string word : word_list) {
        int word_value = 0;

        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                word_value += (c - 'A' + 1);
            }
        }

        for (int t : triangle_list) {
            if (word_value == t) {
                count++;
                break;
            }
        }
    }

    return count;
}
int main() {

    vector<string> word_list = load_words("0042_words.txt");
    vector<int> triangle_list = triangle_numers(30);

    if (word_list.empty()) {
        return 1;
    }

    cout << "Successfully loaded " << word_list.size() << " words." << endl;
    cout << "Successfully calc " << triangle_list.size() << " iteration." << endl;
   
    int count = word_is_tri(word_list, triangle_list);

    cout << count << " are triangle words." << endl;
    return 0;
}