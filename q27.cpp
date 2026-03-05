//Quadratic Primes
//just check for all combos consecative prime creation


#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n);

int main() {

  int max_a, max_b, max_primes = 0;
  int check_prime;
  bool prime;

  for (int a = -1000; a < 1000; ++a){
    for (int b = -1000; b <= 1000; ++b){
      int n = 0;
      int count_primes = 0;
      while (is_prime(n * n + a * n + b)){
        count_primes++;
        n++;
      }
      if (count_primes > max_primes){
            max_primes = count_primes;
            max_a = a;
            max_b = b;
      }
    } 
  }
  int ans = max_a * max_b;
  cout << "The roduct of the coefficients,a and b, for the quadratic expression that produces the maximum number of primes for consecutive values :" 
  << ans << endl;


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