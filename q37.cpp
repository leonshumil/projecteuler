//Truncatable Primes
/*
We to store in a vector primes for each one do a checking from the right it a metter of div 10 from the left we need to find how mant digits 
once and % accordinaly, we can mark in vector primes that we know wont work 
*/

#include <iostream>
#include <vector>
#include <cmath>

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

bool is_truncatable(int n) {
    if (n < 10) return false; 

    int temp = n;
    while (temp > 0) {
        if (!is_prime(temp)) return false;
        temp /= 10;
    }

    temp = n;
    int divisor = 1;
    while (divisor <= temp / 10) {
        divisor *= 10;
    }

    while (temp > 0) {
        if (!is_prime(temp)) return false;
        temp %= divisor; //
        divisor /= 10;
    }

    return true;
}

int main() {
    int count = 0;
    int sum = 0;
    int current = 11; 

    while (count < 11) {
        if (is_truncatable(current)) {
            sum += current;
            count++;
        }
        current++;
    }

    cout << "The sum of the only eleven primes that are both truncatable from left to right and right to left: " << sum << endl;
    return 0;
}