//Pandigital Multiples
/*
Doing brute force could be wastefull first we can find limit doing this operation is 9,999 beacuse it is the larges number that give us 9 digits number (999919998)
we also a clue that 918273645 is not the largest so we can you it to skip tests
also the numbers can be contain in 32 bit so long type is enough  
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check_pan(long num){
  bool digits[10] = {false};
  int dig = 0;

  if (num > 999999999 || num < 123456789) return false;
  
  for(int i = 0; i < 9; ++i){
    dig = num % 10;
    if (dig != 0 && digits[dig] == false){
      digits[dig] = true;
      num /= 10; 
      continue;
    }
    return false;
  }
  return true;
}

int pandigital_multiples(int lim){
    long largest_pan = 0; 
     
    for(int i = 1; i < lim; ++i){
       long temp_pan = 0; 
       int total_dig = 0;
       int n = 1;

        while (total_dig < 9){
          long current_prod = i * n;
          
          int prod_dig = 0;
          long tmp = current_prod;
          if (tmp == 0) prod_dig = 1;
          while (tmp != 0) {
              tmp /= 10;
              prod_dig++;
          }
          
          if (total_dig + prod_dig > 9) break;

          temp_pan = (temp_pan * (long)pow(10, prod_dig)) + current_prod;
          total_dig += prod_dig;
          n++;
        }
        
        if(total_dig == 9 && check_pan(temp_pan)){
            if(temp_pan > largest_pan) largest_pan = temp_pan;
        }
    }
    return (int)largest_pan;
}

int main(){
 
    int limit = 9999;
    int largest_pan = pandigital_multiples(limit);

    cout << "Largest pandigital: " << largest_pan << endl;
    return 0;

}