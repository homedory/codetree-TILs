#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int left_uf[MAX_N], right_uf[MAX_N], left_count[MAX_N], right_count[MAX_N];


void initialize() {
    for (int i = 1; i <= n; i++) {
        left_uf[i] = i;
        right_uf[i] = i;
        left_count[i] = i-1;
        right_count[i] = n-i;
    }
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
    while(index <= end) {
        right_uf[index] = right_end;
        left_uf[index] = left_end;
        index++;
    }

    right_uf[left] = right_end;
    right_uf[left_end] = right_end;

    left_uf[right] = left_end;
    left_uf[right_end] = left_end;

    // update count value
    if (left_end != 1) {
        left_count[left_end] = left_count[findLeft(left_end-1)] + 1;
    }
    if (right_end != n) {
        right_count[right_end] = right_count[findRight(right_end+1)] + 1;
    }
}


int main() {
    cin >> n >> m;
    initialize();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionNodes(a, b);
        int left = findLeft(a);
        int right = findRight(b);
        int total_count = left_count[left] + right_count[right] + 1;
        cout << total_count << "\n";
    }

    return 0;
}