#include <iostream>
using namespace std;

int tree[1025];
int input[1025];
int K;
int input_idx;

void inorder(int node) {
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    if (left_child < (1 << K))
        inorder(left_child);
    
    tree[node] = input[input_idx++];

    if (right_child < (1 << K))
        inorder(right_child);
}

int main() {
    cin >> K;
    for (int i = 0; i < (1 << K) - 1; i++) {
        cin >> input[i];
    }

    inorder(1);

    for (int i = 0; i < K; i++) {
        for (int j = (1 << i); j < (1 << (i+1)); j++) {
            cout << tree[j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}