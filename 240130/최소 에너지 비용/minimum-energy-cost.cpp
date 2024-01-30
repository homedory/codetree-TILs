#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int charge_cost[MAX_N], move_energy[MAX_N];
long long prefix_sum[MAX_N];
vector <int> stop_point;

int main() {
    int n;

    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        cin >> move_energy[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> charge_cost[i];
    }

    prefix_sum[1] = 0;
    for (int i = 2; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + move_energy[i];
    }

    int prev_cost = 1000000;
    for (int i = 1; i <= n; i++) {
        if (prev_cost > charge_cost[i]) {
            prev_cost = charge_cost[i];
            stop_point.push_back(i);
        }
    }

    long long total_cost = 0;

    for (int i = 1; i < stop_point.size(); i++) {
        long long energy = prefix_sum[stop_point[i]] - prefix_sum[stop_point[i-1]];
        total_cost += energy * charge_cost[stop_point[i-1]];
    }

    cout << total_cost;


    return 0;
}