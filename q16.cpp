//Power Digit Sum
// the catches is that we need 2 in the power of 100 and long long will only give us power of 64
// lets do a trick using array to store the number
#include <iostream>

using namespace std;

int main () {
  int impowered[400] = {0}; 
  impowered[0] = 1;
  int limit = 1; 
  int remain = 0;

  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < limit; ++j) {
      int prod = impowered[j] * 2 + remain;
      impowered[j] = prod % 10;
      remain = prod / 10;
    }

    while (remain > 0) {
      impowered[limit] = remain % 10;
      remain = remain / 10;
      limit++;
    }
  }

  int sum = 0; 
  for (int j = 0; j < limit; ++j) {
    sum += impowered[j];
  }

  cout << "The sum power digit: " << sum << endl;

  return 0;
}