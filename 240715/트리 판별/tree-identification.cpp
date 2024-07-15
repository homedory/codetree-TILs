#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    int m;
    unordered_map <int,int> in_degree;
    unordered_set <int> node;
    bool ans = true;
    
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (in_degree.find(b) != in_degree.end() && in_degree[b] > 0) {
            ans = false;
        }
        else
            in_degree[b] = 1;
        
        if (in_degree.find(a) == in_degree.end())
            in_degree[a] = 0;
    }

    if (in_degree.size() != m + 1)
        ans = false;
    
    cout << ans;

    
    return 0;
}