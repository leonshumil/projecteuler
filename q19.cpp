//Counting Sundays
// easy question just sum your days and cheack each mounth if you start at sunday 
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
 //start on monday
 int start = 2, mounth = 0 , count = 0;
 int leap = 0 , sundays = 0;;
 //find what day was 1 jenuary 1901
 count = (start + 365 )%7;
 
 for (int i = 0; i<= 100*12; ++i){
   if (count%7 == 1){
    sundays++;
   }
   mounth = i%12;

   if (mounth == 4 || 6 || 9 || 11){
       count += 30;
   }

   else if (mounth == 2 ){
      if (leap == 4 ){
         count += 29;
         leap = 0;
      }
      else{
         count += 28;
         leap ++; 
      }
   }

   else{
    count += 31;
   }
 }
 cout << "There are " << sundays << " in the time periode" << endl;


}