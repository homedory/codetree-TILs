#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> checked_node;

int getBlockingNode(int start_node) {
    int node = start_node;
    int blocking_node = 1;
    
    while(node > 1) {
        if (checked_node.find(node) != checked_node.end()) 
            blocking_node = node;
        
        node /= 2;
    }

    return blocking_node;
}

int main() {
    
    int n, q;

    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int node;
        cin >> node;

        int blocking_node = getBlockingNode(node);
        if (blocking_node == 1) {
            checked_node.insert(node);
            cout << 0 << "\n";
        }
        else {
            cout << blocking_node << "\n";
        }
    }


    return 0;
}