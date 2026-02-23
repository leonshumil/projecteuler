//Number Letter Counts
//each number accoriding to english grammer rule will be slpit into his parts and will be assing value based on map. 

#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, int> m = {
        {1,3},{2,3},{3,5},{4,4},{5,4},{6,3},{7,5},{8,5},{9,4},{10,3},
        {11,6},{12,6},{13,8},{14,8},{15,7},{16,7},{17,9},{18,8},{19,8},
        {20,6},{30,6},{40,5},{50,5},{60,5},{70,7},{80,6},{90,6}
    };

    long long sum = 0; 
    int singal = 0, decimal = 0, hunderds = 0;
 
    for (int i = 1; i <= 1000 ; ++i) {
        if (i == 1000) {
            sum += 11; 
            continue;
        }

        hunderds = i / 100;
        decimal = (i / 10) % 10;
        singal = i % 10;

        if (hunderds != 0) {
            sum += m[hunderds] + 7; 
            if (decimal != 0 || singal != 0) {
                sum += 3; 
            }
        }

        if (decimal == 1) {
            sum += m[i % 100];
        } else {
            if (decimal > 1) {
                sum += m[decimal * 10]; 
            }
            if (singal > 0) {
                sum += m[singal];
            }
        }
    }
  cout << "sum of latters is : "<< sum << endl;

}
