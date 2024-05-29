#include <iostream>
#include <vector>
using namespace std;

int n;
int visited[10];
vector <int> seq;

void choose(int cur_num) {
    if (cur_num == n + 1) {
        for (int i = 0; i < n; i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = n; i > 0; i--) {
        if (visited[i])
            continue;

        visited[i] = 1;
        seq.push_back(i);

        choose(cur_num + 1);

        visited[i] = 0;
        seq.pop_back();
    }
}

int main() {
    cin >> n;

    choose(1);

    return 0;
}