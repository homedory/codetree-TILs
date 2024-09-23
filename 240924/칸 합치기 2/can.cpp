#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int left_uf[MAX_N], right_uf[MAX_N];
int total_count;

void initialize() {
    for (int i = 1; i <= n; i++) {
        left_uf[i] = i;
        right_uf[i] = i;
    }
    total_count = n;
}

int findLeft(int node) {
    if (node == left_uf[node])
        return node;
    
    return left_uf[node] = findLeft(left_uf[node]);
}

int findRight(int node) {
    if (node == right_uf[node])
        return node;
    
    return right_uf[node] = findRight(right_uf[node]);
}

void unionNodes(int node1, int node2) {
    int left = (node1 < node2) ? node1 : node2;
    int right = (node1 >= node2) ? node1 : node2;

    int left_end = findLeft(left);
    int right_end = findRight(right);

    int index = findRight(left);
    int end = findLeft(right);
    int union_count = -1;
    while(index <= end) {
        int next_idx = findRight(index) + 1;
        right_uf[index] = right_end;
        left_uf[index] = left_end;
        index = next_idx;
        union_count++;
    }
    total_count -= union_count;

    right_uf[left] = right_end;
    right_uf[left_end] = right_end;

    left_uf[right] = left_end;
    left_uf[right_end] = left_end;
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