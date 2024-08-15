#include <iostream>
using namespace std;

int pre_order[100005], in_order[100005], post_order[100005];

int order;

void traversal(int l1, int r1, int l2, int r2) {
    if (l1 > r1)
        return;
    
    post_order[order--] = pre_order[l1];

    int root_idx;
    for (int i = l2; i <= r2; i++) {
        if (in_order[i] == pre_order[l1]) {
            root_idx = i;
            break;
        }
    }

    int left_size = root_idx - l2;

    traversal(l1+left_size + 1, r1, root_idx + 1, r2);
    traversal(l1 + 1, l1 + left_size, l2, root_idx - 1);
}

int main() {
    int n;
    cin >> n;
    order = n;
    for (int i = 1; i <= n; i++) 
        cin >> pre_order[i];
    
    for (int i = 1; i <= n; i++) 
        cin >> in_order[i];
    

    traversal(1, n, 1, n);

    for (int i = 1; i <= n; i++) {
        cout << post_order[i] << " ";
    }


    return 0;
}