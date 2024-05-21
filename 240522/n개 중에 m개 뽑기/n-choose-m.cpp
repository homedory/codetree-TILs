#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> v;

void choose(int num, int cnt) {
    if (num == N + 1) {
        if (cnt == M) {
            for (int i = 0; i < M; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    v.push_back(num);
    choose(num + 1, cnt + 1);
    v.pop_back();

    choose(num + 1, cnt);

    return;
}

int main() {
    
    cin >> N >> M;

    choose(1, 0);

    return 0;
}