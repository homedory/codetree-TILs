#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, L;
    vector <int> c_vector;

    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        c_vector.push_back(c);
    }

    sort(c_vector.begin(), c_vector.end());

    int h_index = 0;
    int idx = N - 1;
    while (idx >= 0) {
        if (c_vector[idx] >= h_index + 1) 
            h_index++;
        else 
            break;
        idx--;
    }

    long long total_num = K * L;
    while (idx >= 0) {
        if (total_num >= (h_index + 1) - c_vector[idx] && h_index + 1 <= c_vector[idx] + K) {
            h_index++;
            total_num -= (h_index + 1) - c_vector[idx];
            idx--;
        }
        else 
            break;
    }  

    cout << h_index;

    return 0;
}