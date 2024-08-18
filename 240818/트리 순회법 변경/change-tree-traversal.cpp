#include <iostream>
using namespace std;

int pre_order[10005], post_order[10005];
int n, order = 1;

void traversal(int left, int right) {
    if (left > right)
        return;
    
    int root = pre_order[left];

    int index = left + 1;
    while(index <= n && pre_order[index] < root) {
        index++;
    }

    traversal(left + 1, index - 1);
    traversal(index, right);
    post_order[order++] = root;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> pre_order[i];

    traversal(1, n);

    for (int i = 1; i <= n; i++) 
        cout << post_order[i] << "\n";
    

    return 0;
}