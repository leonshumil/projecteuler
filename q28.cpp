//Number Spiral Diagonals
//another basic question lets creat a 1001 by 1001 matrix and sum a valuse on the vertical
// keep notice to not count the middle twice

#include <iostream>

using namespace std;

int main() {
    int mat[1001][1001] = {0};
    int x = 500, y = 500;
    int value = 1;
    int steps = 1;
    
    mat[y][x] = value++;

    while (value <= 1001 * 1001) {
        for (int i = 0; i < steps && value <= 1001 * 1001; i++) mat[y][++x] = value++;
        for (int i = 0; i < steps && value <= 1001 * 1001; i++) mat[++y][x] = value++;
        steps++;
        for (int i = 0; i < steps && value <= 1001 * 1001; i++) mat[y][--x] = value++;
        for (int i = 0; i < steps && value <= 1001 * 1001; i++) mat[--y][x] = value++;
        steps++; 
    }

    long long diag_sum = 0;
    for (int i = 0; i < 1001; i++) {
        diag_sum += mat[i][i];              
        diag_sum += mat[i][1000 - i];        
    }
    
    diag_sum -= 1;

    cout << "The sum of the diagonals is: " << diag_sum << endl;

    return 0;
}