#include <iostream>
using namespace std;

int main() {
    int n, t;
    int conveyor_belt[600];
    int temp[600];
    cin >> n >> t;
    
    for (int i = 0; i < 3*n; i++) {
        cin >> conveyor_belt[i];
    }

    t = t % (3*n);
    for (int i = 0; i < t; i++) {
        temp[i] = conveyor_belt[3*n-t+i];
    }

    for (int i = 0; i < 3*n-t; i++) {
        conveyor_belt[3*n-1-i] = conveyor_belt[3*n-1-t-i];
    }

    for (int i = 0; i < t; i++) {
        conveyor_belt[i] = temp[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cout << conveyor_belt[n*i+j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}