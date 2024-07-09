#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2) {
    long long sum1 = (long long) p1.first * p2.second;
    long long sum2 = (long long) p1.second * p2.first;

    return sum1 > sum2;
}

int main() {
    int n;
    long long total_point = 0;
    vector <pair<int,int>> paranthesis_cnt;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int open = 0;
        int close = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(')
                open++;
            else {
                close++;
                total_point += open;
            }
        }

        paranthesis_cnt.push_back(make_pair(open, close));
    }

    sort(paranthesis_cnt.begin(), paranthesis_cnt.end(), compare);

    long long prev_open_cnt = 0;
    for (int i = 0; i < paranthesis_cnt.size(); i++) {
        total_point += prev_open_cnt * paranthesis_cnt[i].second;
        prev_open_cnt += paranthesis_cnt[i].first;
    }
    
    cout << total_point;

    return 0;
}