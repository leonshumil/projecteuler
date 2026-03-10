    //Pandigital Products
    //The question asked to find  multiplicand, multiplier, and product 1 through 9 pandigital.
    //we can find limit of numbers to check by checking multiplicand of 1-99 and multyplier of 100-9999 this will grunts us 9 digit and around 1 million veriations
    //some variations break the rule from the get-go so we will work to eliminate them before the calc

    #include <fstream>
    #include <iostream>
    #include <cmath>

    using namespace std;

    bool can_b_pandigital(int n);
    int count_digits(int n);

    int main (){

     int prod;
     int sum = 0;
     bool known_prod[10000] = {false};

     for(int i = 1; i < 100; ++i){

        if(can_b_pandigital(i) != true){
            continue;
        }

        for(int j = 1; j < 10000; ++j){
          
          if(can_b_pandigital(j) != true) continue;

          prod = i * j;
          if (prod < 10000 && can_b_pandigital(prod)) {
              int d_count = count_digits(i) + count_digits(j) + count_digits(prod);
              
              long long final_check = i;
              final_check = final_check * pow(10, count_digits(j)) + j;
              final_check = final_check * pow(10, count_digits(prod)) + prod;
              
              if(d_count == 9 && can_b_pandigital(final_check)){
                if (known_prod[prod] == false){
                  sum += prod;
                  known_prod[prod] = true; 
                }
              }
          } 
        } 
     }
    cout << "The sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital: " << sum << endl;
    return 0;
   
    }


   bool can_b_pandigital(int n) {
       int digits[10] = {0};
       while (n > 0) {
          int d = n % 10;
          if (d == 0 || digits[d] > 0) return false;
          digits[d]++;
          n /= 10;
       }
    return true;
   }

  int count_digits(int n) {
    int c = 0;
    while (n > 0) { n /= 10; c++; }
    return c;
  }  