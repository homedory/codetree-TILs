#include <iostream>
#include <vector>
using namespace std;

vector <int> seq;
int n;
bool found_seq = false;

bool isPossible() {
    int l = seq.size();
    for (int i = 1; i <= l/2; i++) {
        bool same_seq = true;

        int left = l - 2 * i;
        int right = l - i;
        for (int j = 0; j < i; j++) {
            if (seq[left + j] != seq[right + j]) {
                same_seq = false;
                break;
            }
        }
        if (same_seq) {
            return false;
        }
    }
    return true;
}

void find(int len) {
    if (len == n) {
        found_seq = true;
        return;
    }

    for (int i = 4; i <= 6; i++) {
        seq.push_back(i);
        if (isPossible()) {
            find(len + 1);
        }

        if (found_seq) {
            return;
        }
        seq.pop_back();
    }
}

int main() {
    cin >> n;

    find(0);

    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i];
    }

    return 0;
}