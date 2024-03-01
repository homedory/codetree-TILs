#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int main() {
    int n, s, e;
    pair<int,int> request[MAX_N];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;

        request[i] = make_pair(e, s);
    }

    sort(request, request + n);

    int ans = 0;
    int t = 0;

    for (int i = 0; i < n; i++) {
        if (request[i].second >= t) {
            ans++;
            t = request[i].first;
        }    
    }

    cout << ans;


    return 0;
}