#include <iostream>
using namespace std;

int number_cnt = 0;
int n;

void beautifulNum(int curr_len) {
    if (curr_len == n) {
        number_cnt++;
        return;
    }
    else if (curr_len > n) {
        return;
    }

    for (int i = 1; i <= 4; i++) {
        beautifulNum(curr_len + i);
    }
}

int main() {
    cin >> n;

    beautifulNum(0);

    cout << number_cnt;
    
    return 0;
}