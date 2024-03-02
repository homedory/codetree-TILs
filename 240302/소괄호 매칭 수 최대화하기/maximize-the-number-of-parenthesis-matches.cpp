#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N 100005
#define MAX_S 500005

bool cmp(pair<int,int> a, pair<int,int> b) {
    long long sum1 = (long long) a.first * b.second;
    long long sum2 = (long long) b.first * a.second;

    return sum1 >= sum2;
}

int main() {
    int n;
    pair<int,int> s[MAX_N];
    long long ans = 0;
    char arr[MAX_N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr;

        string str = arr;

        int open = 0, close = 0;
        for (int j = 0; j < (int) str.length(); j++) {
            if (str[j] == '(') {
                open++;
            }
            else {
                close++;
                ans += open;
            }
        }
        s[i] = make_pair(open, close);
    }

    sort(s, s + n, cmp);

    int open_sum = 0;
    for (int i = 0; i < n; i++) {
        int open = s[i].first;
        int close = s[i].second;

        ans += (long long) open_sum * close;

        open_sum += open;
    }

    cout << ans;

    return 0;
}