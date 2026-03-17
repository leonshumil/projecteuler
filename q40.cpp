//Champernowne's Constant
/*
We need to find 7 digits, we know the 9 first number are 1 digit the 90 next are 2 the 900 next are 3 etc.
this will be enougth to find reletive close point string searching.
*/

#include <iostream>

using namespace std;

int find_digit(int n) {
    long pos = 0, i = 1;
    int digit = 0;

    while (pos < n) {
        string s = to_string(i);
        int len = s.length();
        
        if (pos + len >= n) {
            digit = s[n - pos - 1] - '0';
            break;
        }
        
        pos += len;
        ++i; 
    }

    return digit;
}


int main(){
   
    int prod = 1, find = 1, num_digits = 7, digit;

    for (int i = 0; i < num_digits; ++i){
    
        digit = find_digit(find);
        prod *= digit;
        find *= 10;
    }

  cout << "Product of digits: " << prod << endl;
  return 0;

}