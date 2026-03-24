//Sub-string Divisibility
/*
Pandigital of 0 to 9 have around 9*9! numbers of premutation taking each premutation then deviding to sub-strings and cheaking array of the asked primes to see  
who is divideble
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int divisors[] = {2, 3, 5, 7, 11, 13, 17};

int main() {
    string s = "1023456789";
    bool next = true;
    long long total_sum = 0; 

    while (next) {
        
        bool passes = true;
        for (int i = 1; i <= 7; ++i) {
            int check = stoi(s.substr(i, 3)); 
            
            if (check % divisors[i-1] != 0) {
                passes = false;
                break; 
            }
        }

        if (passes) {
            total_sum += stoll(s); 
        }

        next = next_permutation(s.begin(), s.end());
    }

    cout << "The sum is: " << total_sum << endl;
    return 0;
}