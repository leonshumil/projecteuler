//Triangular, Pentagonal, and Hexagonal
/*
Probebly the fastes way is just getting the non stop iteration of hex numbers and check if this number is pent and then tri 
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool pent(long long x) {

    if (x < 1) return false;

    double n = (1.0 + sqrt(24.0 * x + 1.0)) / 6.0;

    return (n == (long long)n);
}

bool tri(long long x) {

    if (x < 1) return false;

    double n = (-1.0 + sqrt(8.0 * x + 1.0)) / 2.0;

    return (n == (long long)n);
}

int main(){

  long long trinity = 0;
  bool found = false;
  int i = 144;

  while (!found){
     long long hex = i * (2*i - 1);

     if (pent(hex)){
        if(tri(hex)){
         trinity = hex;
         found = true;
        }
     }
     i ++;
  }
  cout << "The number to complete the trinity is:  " << trinity << endl;

}