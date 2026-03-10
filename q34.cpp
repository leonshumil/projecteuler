//Digit Factorials
//first we need to find the limit of number using scale ( 9!+9!+... < 99...  ) afther that a simple checkk is sufficient


    #include <fstream>
    #include <iostream>
    #include <cmath>

    using namespace std;
   
    int find_lim();
    long long factorial(int n); 

    int main (){

      int lim = find_lim(), sum = 0, local_sum = 0, digit, num;

      for (int i = 3; i < lim; ++i) {
       
      local_sum = 0;
       num = i;
       while (num != 0){
         digit = num % 10;
         local_sum += factorial(digit);
         num = num / 10;
       }
       if(local_sum == i ){
         sum += local_sum;
       }
      }
    cout << "The sum of all numbers which are equal to the sum of the factorial of their digits: " << sum << endl;
    return 0;

    }

    int find_lim() {
      int fac = factorial(9);
      int num = 9;
      while (fac > num){
         fac += factorial(9);
         num = num * 10 + 9;
      }
      return num;
    }

    long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}