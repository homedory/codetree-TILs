#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

#define MAX_N 100005

int main() {
    int N, M;
    int w, v;
    
    tuple<double, int, int> j[MAX_N];

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        j[i] = make_tuple((double) v / w, w, v);
    }

    sort(j, j + N, greater<tuple<double, int,int>>());

    double sum = 0;
    int weight = 0;
    
    for (int i = 0; i < N; i++) {
        tie(ignore, w, v) = j[i];

        if (M - weight >= w) {
            sum += v;
            weight += w;
        }
        else {
            sum += (double) v * (double) (M - weight) / w;
            break;
        }
    }

    cout << fixed;
    cout.precision(3);

    cout << sum;

    return 0;
}