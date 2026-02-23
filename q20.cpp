//Factorial Digit Sum
//do the trick of storing in array cause 100! maybe to long for long long

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int main() {

  int factor = 100, sum = 0;
  int limit = 1; 
  int res_factor[500] = {0};
  res_factor[0] = 1;

  for (int i = 2; i <= factor; ++i) {
        int carry = 0;
        for (int j = 0; j < limit; ++j) {
            int prod = res_factor[j] * i + carry;
            res_factor[j] = prod % 10;
            carry = prod / 10;
        }

        while (carry > 0) {
            res_factor[limit] = carry % 10;
            carry = carry / 10;
            limit++;
        }
    }
  
  for (int j = 0; j < limit; ++j) {
    sum += res_factor[j];
  }

  cout << "The sum of all digits of factor 100 is : "<< sum << endl;

}