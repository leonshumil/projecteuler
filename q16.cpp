//Power Digit Sum
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (){
 long long power =2;
 int sum =0;
    for (int i=1; i <= 1e3; i++){
        power = power*2; 
    }
    for (int i=1; i <= 1e3; i++){
       sum = power%10;
       power = power/10;
    }
       cout << "Power sum digit of 1000 is: " << sum << endl;


}