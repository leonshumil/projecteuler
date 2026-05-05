// Goldbach's Other Conjecture
/*
A little bit rough but check all odd and skip primes for the other try to remove all twice square and check if remainder is prime.
*/


#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    for (long long n = 9; ; n += 2) {
        
        if (is_prime(n)) continue;

        bool found_sum = false;

        for (long long k = 1; 2 * k * k < n; ++k) {
            long long remainder = n - 2 * k * k;

            if (is_prime(remainder)) {
                found_sum = true;
                break;
            }
        }

        if (!found_sum) {
            cout << "Smallest odd false composite: " << n << endl;
            break; 
        }
    }

    return 0;
}