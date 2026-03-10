//Double-base Palindromes
/*we need to check if number is palindromic in base 10 and 2, checking in based 10 is easyer so we use array of 1 million and check first all numbers 
then check only suspect numbers in base 2 (need to do convertion) converting to string revering and comparing should be the way
*/


#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string conv_binary(int n){
  
  string binary = "";
    while (n > 0) {
        binary += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }

   return binary;
 }

int palindrome(int arr[], int lim) {
    int sum = 0;

    for (int i = 1; i < lim; ++i) { 
        string b_10 = to_string(i);
        string rev_10 = b_10;
        reverse(rev_10.begin(), rev_10.end());

        if (b_10 == rev_10) {
            arr[i] = true;
        }
    }
    
    for (int i = 1; i < lim; ++i) {
       if (arr[i] == true) {
            string b_2 = conv_binary(i); 
            string rev_2 = b_2;
            reverse(rev_2.begin(), rev_2.end());

            if (b_2 == rev_2) {
                sum += i;
            }
       }
    }
    return sum;
}


int main (){
 int lim = 1000000;
 int arr[lim] = {false};
 int sum = palindrome(arr, lim);

 cout << "The sum of all numbers, less than one million, which are palindromic in base 10 and 2 base: " << sum << endl;

 
}