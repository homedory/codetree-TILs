#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int uf[MAX_N], opponent[MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        opponent[i] = i;
    }
}

int find(int node) {
    if (uf[node] == node)
        return node;
    
    return uf[node] = find(uf[node]);
}

void unionNodes(int node1, int node2) {
    int node1_uf = find(node1);
    int node2_uf = find(node2);

    uf[node1_uf] = node2_uf;
}

bool isContradict(int node1, int node2) {
    return find(node1) == find(node2);
}

int main() {
    cin >> n >> m;

    initialize();
    bool ans = true;
    for (int i = 0; i < m; i++) {
        int player1, player2;
        cin >> player1 >> player2;

        if (find(player1) == find(player2)) {
            ans = false;
            break;
        }

        if (opponent[player1] != player1) {
            if (isContradict(opponent[player1], player2)) {
                ans = false;
                break;
            }
            unionNodes(opponent[player1], player2);
        }

        if (opponent[player2] != player2) {
            if (isContradict(opponent[player2], player1)) {
                ans = false;
                break;
            }
            unionNodes(opponent[player2], player1);
        }

        opponent[player1] = player2;
        opponent[player2] = player1;
    }

    cout << (ans ? 1 : 0);


    return 0;
}