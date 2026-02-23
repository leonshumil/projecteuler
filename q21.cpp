//Amicable Numbers
//ok i run one time on  each number to find all devisers and sum them
//store each sum in an array where the index point to where it came from and do another run to find paires

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int find_divisors_sum(int n);

int main() {
  
    int divisor_sums[10000] = {0};
    int sum = 0;

    for (int i = 1; i < 10000; ++i) {
        divisor_sums[i] = find_divisors_sum(i);
    }

    for (int a = 1; a < 10000; ++a) {
        int b = divisor_sums[a];

        if (b < 10000 && b != a && divisor_sums[b] == a) {
            sum += a;
        }
    }

     cout << "The number of Amicable Numbers are: "<< sum << endl;
   
     return 0;
}

int find_divisors_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}