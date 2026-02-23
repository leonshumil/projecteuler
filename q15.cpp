// Lattice Paths
// do combinatoric
// we can only have btween 20-40 moves to get to the end goal so we can have ( 40 choose 20 )
#include <iostream>

using namespace std;

int main() {
    int n = 20;
    long long paths = 1;

    for (int i = 1; i <= n; i++) {
        paths = paths * (n + i) / i;
    }

    cout << "Total paths for 20x20: " << paths << endl;

    return 0;
}