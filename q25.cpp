//1000-digit Fibonacci Number
//hugh number need to be saved with array 

#include <iostream>

using namespace std;

int main() {
    int f1[1001] = {0};
    int f2[1001] = {0};
    int res[1001] = {0};

    f1[0] = 1;
    f2[0] = 1;

    int index = 2; 
    int digits = 1; 

    while (digits < 1000) {
        int carry = 0;
        index++;

        for (int i = 0; i < digits; i++) {
            int sum = f1[i] + f2[i] + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {
            res[digits] = carry;
            digits++;
        }

        for (int i = 0; i < digits; i++) {
            f1[i] = f2[i];
            f2[i] = res[i];
        }
    }

    cout << "The index of the first 1000-digit Fibonacci number is: " << index << endl;

    return 0;
}