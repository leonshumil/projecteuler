//Pandigital Prime
/*
We can send an array with all posible combos of pandigital and check prime start from biggest to smallest this is less then a million checks
we can use premutation to check it and we know 1->8 and 1->9 are aint working from the start because of are divedeble by 3 so only 1->7 and 1->4 are ok.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


int main() {
    vector<string> lengths = {"7654321", "4321"};

    for (string s : lengths) {
        while (prev_permutation(s.begin(), s.end())) {
            int candidate = stoi(s);

            if (candidate % 2 != 0 && is_prime(candidate)) {
                cout << "Biggest pandigital prime: " << candidate << endl;
                return 0; 
            }
        }
    }

    return 0;
}