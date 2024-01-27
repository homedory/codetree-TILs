#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int main() {
    int N;
    map <int,int> line;
    int arr[MAX_N];
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        line[x1] = x2;
        arr[i] = x2;
    }

    sort(arr, arr+N);

    int cnt = 0, ans = 0;
    for (map<int,int>::iterator it = line.begin(); it != line.end(); it++) {
        int order = lower_bound(arr, arr + N, it->second) - arr;
        if (order < cnt)
            ans += cnt - order + 1;
        cnt++;
    }

    cout << ans;


    return 0;
}