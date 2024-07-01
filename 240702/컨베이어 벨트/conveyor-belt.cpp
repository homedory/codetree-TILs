#include <iostream>
using namespace std;

int main() {
    int n, t;
    int conveyor_belt[400];
    int temp[200];

    cin >> n >> t;
    for (int i = 0; i < 2*n; i++) {
        cin >> conveyor_belt[i];
    }

    // move conveyor belt
    t = t % (2*n);
    for (int i = 0; i < t; i++) {
        temp[i] = conveyor_belt[2*n - t + i];
    }
    for (int i = 2*n - 1; i >= 0; i--) {
        conveyor_belt[i + t] = conveyor_belt[i];
    }
    for (int i = 0; i < t; i++) {
        conveyor_belt[i] = temp[i];
    }

    // answer
    for (int i = 0; i < n; i++) {
        cout << conveyor_belt[i] << " ";
    }
    cout << "\n";
    for (int i = n; i < 2*n; i++) {
        cout << conveyor_belt[i] << " ";
    }

    return 0;
}