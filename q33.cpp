   //Digit Cancelling Fractions
   //so this is kind of wierd question to asked but theres naivly only 89^2 cases to check they asked the the value to be less then 1 so 
   //numerator < denominator and also sum of 11 to 99 cases so half of the original and also we can break when 4 case are found
   
#include <iostream>

using namespace std;

bool is_non_trivial(int n, int m);
int gcd(int a, int b);

int main() {
    int prod_den = 1, prod_num = 1;

    for (int i = 11; i < 100; ++i) {
        for (int j = 10; j < i; ++j) {
            if (is_non_trivial(j, i)) {
                prod_den *= i;
                prod_num *= j;
            }
        }
    }

    int common = gcd(prod_num, prod_den);
    cout << "The value of the denominator: " << prod_den / common << endl;
    
    return 0;
}

bool is_non_trivial(int n, int m) {
    int n1 = n / 10;
    int n2 = n % 10;
    int m1 = m / 10;
    int m2 = m % 10;

    if (n2 == 0 && m2 == 0) return false;
    if (n2 == m1 && n * m2 == m * n1) return true;
    if (n1 == m2 && n * m1 == m * n2) return true;

    return false;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}