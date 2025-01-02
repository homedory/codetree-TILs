#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1005

int arr[MAX_N];
vector<int> lds;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (lds.size() == 0 || lds[lds.size()-1] < -arr[i]) {
            lds.push_back(-arr[i]);
        }
        else {
            int idx = upper_bound(lds.begin(), lds.end(), -arr[i]) - lds.begin();
            lds[idx] = -arr[i];
        }
    }

    cout << lds.size();
    
    return 0;
}