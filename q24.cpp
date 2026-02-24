//Lexicographic Permutations
//we can reduce the scoope easly by knowing 10! is 3,628,800 and 9! is 362,880 and so and so
// so the item in the milionth indes ( of sorted array ) will start at 2 (362,880*2 - 362,880*3)
// we can expand this knowledge to keep reducing. 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = 999999; 
    string answer = "";


    int fact[10];
    fact[0] = 1;
    for (int i = 1; i < 10; i++)
        fact[i] = fact[i-1] * i;

    for (int i = 9; i >= 0; i--) {
        int chosen = index / fact[i];  
        answer += to_string(digits[chosen]);
        digits.erase(digits.begin() + chosen);
        index %= fact[i];         
    }

    cout << "The 1,000,000th lexicographic permutation is: " << answer << endl;
    return 0;
}