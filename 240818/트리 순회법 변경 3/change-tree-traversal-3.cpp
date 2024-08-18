#include <iostream>
using namespace std;

int pre_order[100005], in_order[100005], post_order[100005];

int order = 1;

void traversal(int l1, int r1, int l2, int r2) {
    if (l1 > r1)
        return;
    
    pre_order[order++] = post_order[r1];

    int index;
    for (int i = l2; i <= r2; i++) {
        if (in_order[i] == post_order[r1]) {
            index = i;
            break;
        }
    }

    int left_size = index - l2;

    traversal(l1, l1 + left_size - 1, l2, index - 1);
    traversal(l1 + left_size, r1 - 1, index + 1, r2);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> in_order[i];

    for (int i = 1; i <= n; i++)
        cin >> post_order[i];

    traversal(1, n, 1, n);

    for (int i = 1; i <= n; i++)
        cout << pre_order[i] << " ";

    return 0;
}