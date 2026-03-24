//Pentagon Numbers
/*
The naive way whould be geeting a huge vector with iteration then checking each pair if there sum and diffrences is in the vector, easyerway whould be checking 
sum and diff and see if the answer is pentagon
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool pos_root(long long x) {

    if (x < 1) return false;

    double n = (1.0 + sqrt(24.0 * x + 1.0)) / 6.0;

    return (n == (long long)n);
}

int main() {
    vector<long long> pentagon;
    bool found = false;
    long long k = 1;

    while (!found) {
        k++;
        long long pk = k * (3 * k - 1) / 2;
        
        for (int i = pentagon.size() - 1; i >= 0; --i) {
            long long pj = pentagon[i];
            
            long long sum = pk + pj;
            long long diff = pk - pj;

            if (pos_root(sum) && pos_root(diff)) {

                cout << "Difference D: " << diff << endl;
                found = true;
                break;
            }
        }
        pentagon.push_back(pk);
        
        if (k > 10000) break; 
    }

    return 0;
}
