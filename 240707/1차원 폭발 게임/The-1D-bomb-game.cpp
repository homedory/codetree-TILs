#include <iostream>
using namespace std;

int arr[105];
int N, M;

bool explode() {
    int exploded = false;

    int idx = 0;
    while(idx < N) {
        int cnt = 0;
        int temp_idx = idx;
        while(temp_idx < N && arr[temp_idx] == arr[idx]) {
            cnt++;
            temp_idx++;
        }

        if (cnt >= M) {
            exploded = true;
            for (int i = idx; i < temp_idx; i++) {
                arr[i] = 0;
            }
        }

        idx = temp_idx;
    }

    return exploded;
}

void drop() {
    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            arr[idx] = arr[i];
            idx++;
        }
    }
    N = idx;
}

int main() {
    cin >> N >> M;
    for (int i = N - 1; i >= 0; i--) {
        cin >> arr[i];
    }

    while(explode()) {
        drop();
    }

    cout << N << "\n";

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}