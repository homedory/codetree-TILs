#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map <char, int> position;
char left_child[26], right_child[26];

void preorder(char node) {
    if (node == '.')
        return;

    int idx = node - 'A';

    cout << node;
    preorder(left_child[idx]);
    preorder(right_child[idx]);
}

void inorder(char node) {
    if (node == '.')
        return;

    int idx = node - 'A';

    inorder(left_child[idx]);
    cout << node;
    inorder(right_child[idx]);
}

void postorder(char node) {
    if (node == '.')
        return;

    int idx = node - 'A';

    postorder(left_child[idx]);
    postorder(right_child[idx]);
    cout << node;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        char parent, left ,right;
        cin >> parent >> left >> right;

        int idx = parent - 'A';
        left_child[idx] = left;
        right_child[idx] = right;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0;
}