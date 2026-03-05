// Reciprocal Cycles
// The question ask which number 1-1000 if you devide 1 by him will give you the longest cycle 
// when you do long devision when you get back to deviding 1you finish a cycle so lets check all numer and see who give max 

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int max_length = 0;
    int result_num = 0;

    for (int i = 2; i < 1000; ++i) {
        int remainder_pos[1000] = {0};
        int remainder = 1;
        int position = 0;

        while (remainder != 0 && remainder_pos[remainder] == 0) {
            remainder_pos[remainder] = position;
            remainder *= 10;
            remainder %= i;
            position++;
        }

        if (remainder != 0) {
            int cycle_length = position - remainder_pos[remainder];
            if (cycle_length > max_length) {
                max_length = cycle_length;
                result_num = i;
            }
        }
    }

    cout << "The number with the longest cycle is: " << result_num << endl;
    cout << "Cycle length: " << max_length << endl;

    return 0;
}