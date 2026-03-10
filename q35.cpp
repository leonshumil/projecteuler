//Circular Primes
// solve it with a friend it was extreamly inefficiant
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
bool is_prime(int n);
map<int, bool> all_primes_to_n(int n);
bool is_p_cyclic(int p, map<int, bool> dict);


int main() {
    int CHECK_UNTIL = 1000000;
    int amount_of_cyclic_primes = 0;
    map<int, bool> dict;
    dict = all_primes_to_n(CHECK_UNTIL);
    //for (auto p : dict) {
    //    cout << p.first << " : " << p.second << endl;
    //}


    for (auto p : dict) {
        if (p.second) {
            if (is_p_cyclic(p.first, dict)) {
                amount_of_cyclic_primes++;
            }
        }
    }
    printf("amount_of_cyclic_primes is: %i\n", amount_of_cyclic_primes);

    return 0;
}

map<int, bool> all_primes_to_n(int n) {
    map<int, bool> dict;
    for(int i = 0; i <= n; i++) {
        if (is_prime(i)) {
            dict[i] = true;
        }
        else {
            dict[i] = false;
        }
    }
    return dict;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}


bool is_p_cyclic(int p, map<int, bool> dict) {
    string p_str = to_string(p);       // original number as string
    int str_len = p_str.length();
    string rotated = p_str;            // will hold rotations
    int result = 0;
    for(int i = 0; i < str_len; i++) {
        // rotate: move last character to the front
        rotated = rotated.back() + rotated.substr(0, rotated.size() - 1);

        result = stoi(rotated);

        if (dict[result] == false) return false;
    }
    printf("true cyclic: %i\n", result);
    return true;
}
