    //Digit Fifth Powers
    //The question asked as if we divide a number to its digit can each digit fifth power sumed can be equal to the original number
    //one problem is what number is the upper most possibale option to fill this requairment this can be check by checking when scalling break
    //for numbers: 9,99,999,.. when he number is bigger then sum 

    #include <fstream>
    #include <iostream>
    #include <cmath>

    using namespace std;

    int upper_bound(int n);

    int main (){

    int power = 5, sum = 0, sum_tot = 0, tmp, digit; 
    int lim = upper_bound(power);

    // exlude 1 by definition
    for (int i = 2; i <= lim; ++i){
    
    sum = 0;
    tmp = i;

    while (tmp > 0) {
        digit = tmp % 10;
        sum += pow(digit, power);  
        tmp = tmp / 10;
        }

        if (sum == i) {
        sum_tot += i;
        }
    }

        cout << "The sum of all the numbers that can be written as the sum of fifth powers of their digits: " << sum_tot << endl;

    }

    //return big omega bound value
    int upper_bound(int n) {
        
        int nine_pow = pow(9, n);
        int digits = 1;
        
        while (true) {

            long long max_sum = (long long)digits * nine_pow;
            int count = 0;
            long long temp = max_sum;
            
            while (temp > 0) {
                temp /= 10;
                count++;
            }

            if (count < digits) {
                return max_sum;
            }
            digits++;
        }
    }
