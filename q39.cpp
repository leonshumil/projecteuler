//Integer Right Triangles
/*
theres several ways to do this question i want to do a fun way by knowing if a^2 + b^2  = c^2 so if b is very small a would be max of helf of the parimeter and min
of about 1 with b in the same scale, the fun part is that we will check all combos of a and b calc c and put the parimeter in a hash table that hold count. 
*/


#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

void pythagorean(unordered_map<int, int>& counts, int perimeter) {
    for (int a = 1; a <= perimeter / 2; ++a) {
        for (int b = a + 1; b <= perimeter / 2; ++b) {
            
            int c_squared = a * a + b * b;
            int c = sqrt(c_squared);
            
            if (c * c == c_squared) {
                int current_p = a + b + c;
                if (current_p <= perimeter) {
                    counts[current_p]++;
                }
            }
        }
    }

}


int main(){

 unordered_map<int, int> counts;
 int max_parimeter = 1000;
 pythagorean(counts, max_parimeter);
 int max_combos = 0;
 int best_p = 0;

 for (auto const& [p, count] : counts) {
        if (count > max_combos) {
            max_combos = count;
            best_p = p;
        }
    }

 cout << "Perimeter with most combos: " << best_p << " (" << max_combos << " solutions)"<< endl;
 return 0;

}