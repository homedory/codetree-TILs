#include <iostream>
#include <vector>
using namespace std;

vector<int> position, velocity;
int n;    

bool isPossible(double time) {
    double left_bound = position[0] - time * velocity[0];
    double right_bound = position[0] + time * velocity[0];

    for (int i = 1; i < n; i++) {
        double left_end = position[i] - time * velocity[i];
        double right_end = position[i] + time * velocity[i];

        left_bound = max(left_bound, left_end);
        right_bound = min(right_bound, right_end);
        if (left_bound > right_bound)
            return false;
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        position.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        velocity.push_back(v);
    }

    double left = 0;
    double right = 1000000000;
    double ans = 0;
    for (int i = 0; i < 10000; i++) {
        double mid = (left + right) / 2;
        if (isPossible(mid)) {
            right = mid;
            ans = mid;
        }
        else {
            left = mid;
        }
    }

    cout << fixed;
    cout.precision(4);

    cout << ans;

    return 0;
}