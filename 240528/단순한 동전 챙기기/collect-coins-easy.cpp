#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

vector <tuple<int,int,int>> coin;
int coinNum = 0;
int minDist = 2000000000;
int start_x, start_y, end_x, end_y;

int calcDist(int x1, int y1, int x2, int y2) {
    return abs(x1- x2) + abs(y1 - y2);
}

void chooseCoin(int idx, int cnt, int prev_x, int prev_y, int cur_dist) {
    if (cnt == 3) {
        cur_dist += calcDist(prev_x, prev_y, end_x, end_y);
        minDist = min(minDist, cur_dist);
        return;
    }

    if (idx == coinNum)
        return;
    
    int num, cur_x, cur_y;
    make_tuple(num, cur_x, cur_y) = coin[idx]; 

    chooseCoin(idx + 1, cnt + 1, cur_x, cur_y, cur_dist + calcDist(prev_x, prev_y, cur_x, cur_y));

    chooseCoin(idx + 1, cnt, prev_x, prev_y, cur_dist);
}

int main() {
    int N;
    
    string s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '.')
                continue;
            
            if (s[j] == 'S') {
                start_x = i;
                start_y = j;
            }
            else if (s[j] == 'E') {
                end_x = i;
                end_y = j;
            }
            else {
                int num = s[j] - '0';
                coin.push_back(make_tuple(num, i, j));
                coinNum++;
            }
        }
    }

    sort(coin.begin(), coin.end());

    chooseCoin(0, 0, start_x, start_y, 0);

    if (coinNum < 3) 
        cout << -1;
    else 
        cout << minDist;
    

    return 0;
}