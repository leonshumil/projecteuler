//Longest Collatz Sequence
//brute force

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (){
  int num ;
  long temp;
  int chain = 0, max_chain = 0, b_prod = 0; 

  for (int num = 1; num < 1000000; ++num) {
        temp = num;
        int chain = 0;
        
        while (temp != 1) {
            if (temp % 2 == 0) {
                temp = temp / 2;
            } else {
                temp = 3 * temp + 1; 
            }
            chain++;
        }
        
        if (chain > max_chain) {
            max_chain = chain;
            b_prod = num;
        }
    }

 cout << "Biggest chain maker under 1 milion : "<< b_prod << endl;

}