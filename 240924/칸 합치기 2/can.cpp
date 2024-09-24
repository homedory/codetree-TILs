#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int uf[MAX_N];
int total_count;

void initialize() {
    for (int i = 1; i <= n; i++) 
        uf[i] = i;

    total_count = n;
}

int find(int num) {
    if (num == uf[num])
        return num;
    
    return uf[num] = find(uf[num]);
}

void unionNodes(int from, int to) {
    int idx = find(from);

    while(idx < to) {
        uf[idx] = idx + 1;
        idx++;
        total_count--;
        idx = find(idx);
    }
}


int main() {
    cin >> n >> m;
    initialize();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionNodes(a, b);
        cout << total_count << "\n";
    }

    return 0;
}