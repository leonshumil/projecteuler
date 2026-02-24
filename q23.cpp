//Non-Abundant Sums
//it can be solved by doing one run to the limit to find abandant
//then run of suming all possible paires it will take n^2 but around this semple size its ok 

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int find_divisors_sum(int n);

int main (){

 int limit_abundant = 28123;
 int num_abundant = 0;
 int* abundant_arr = new int[limit_abundant];

 for (int i = 1; i<= limit_abundant; ++i){
    if (find_divisors_sum(i) > i){
       abundant_arr[num_abundant] = i;
       num_abundant ++;
    }
 }
  cout << "The numer of abundant numbers are : "<< num_abundant << endl;
 
   bool* can_be_sum = new bool[limit_abundant + 1];
   for (int i = 0; i <= limit_abundant; i++){
        can_be_sum[i] = false;
    }

   for (int i = 0; i < num_abundant; ++i) {
        for (int j = i; j < num_abundant; ++j) { 
            int temp = abundant_arr[i] + abundant_arr[j];
            if (temp <= limit_abundant) {
                can_be_sum[temp] = true;
            } else {
                break;
            }
        }
    }

   long long total_sum = 0; 
    for (int i = 1; i <= limit_abundant; ++i) {
        if (!can_be_sum[i]) {
            total_sum += i;
        }
    }
 
    cout << "The sum of all the positive integers which cannot be written as the sum of two abundant numbers is: "<< total_sum  << endl;

  delete[] abundant_arr;
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