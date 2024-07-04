#include <iostream>
using namespace std;

int n;
int arr[105];

void removeBlock(int start, int end) {
    int temp[105];
    int temp_end = 0;

    for (int i = 1; i <= n; i++) {
        if (i >= start && i <= end)
            continue;
        
        temp_end++;
        temp[temp_end] = arr[i];
    }

    for (int i = 1; i <= temp_end; i++) {
        arr[i] = temp[i];
    }

    n = temp_end;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 2; i++) {
        int start, end;
        cin >> start >> end;

        removeBlock(start, end);
    }

    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}