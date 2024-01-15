#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N, cnt = 0;
    long long T;
    int check[100005];

    vector <pair<int,int>> p;

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        int s,v;
        cin >> s >> v;
        p.push_back(make_pair(s, v));
    }

    for (int i = 0; i < N - 1; i++) {
        long long x = ((long long)(p[i].second - p[i + 1].second)) * T;
        if (x >= (long long)(p[i+1].first - p[i].first)) {
            check[i] = 1;
            
        }
        else {
            check[i] = 0;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (check[i] == 0) {
            cnt++;
        }
        else {
            cnt++;
            while(check[i] == 1) {
                i++;
            }
            i--;
        }
    }

    cout << cnt;

    return 0;
}