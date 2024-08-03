#include <iostream>
#include <unordered_map>
using namespace std;

int prev_node[100005];
int next_node[100005];
int value[100005];
int N, M;
int start_idx;
unordered_map <int,int> val_to_index;

void delete_node(int idx) {
    int prev_node_idx = prev_node[idx];
    int next_node_idx = next_node[idx];

    if (start_idx == idx)
        start_idx = next_node_idx;
    
    next_node[prev_node_idx] = next_node_idx;
    prev_node[next_node_idx] = prev_node_idx;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> value[i];
        val_to_index[value[i]] = i;
        prev_node[i] = i - 1;
        next_node[i] = i + 1;
    }
    prev_node[1] = N;
    next_node[N] = 1;
    start_idx = 1;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        int idx = val_to_index[num];
        cout << value[next_node[idx]] << " " << value[prev_node[idx]] << "\n";
        delete_node(idx);
    }

    return 0;
}