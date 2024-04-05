#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 3000000

vector<bool> checked(MAX_N + 1, false);
queue<pair<int,int>> num_q;


void addNum(int num, int cnt) {
    if (checked[num]) 
        return;
    
    num_q.push(make_pair(num, cnt));
    checked[num] = true;
}

int findMinCalcCnt(int target) {
    int min_cnt;

    addNum(1, 0);
    while(!num_q.empty()) {
        auto [curr_num, curr_cnt] = num_q.front();
        num_q.pop();

        if (curr_num == target) {
            min_cnt = curr_cnt;
            break;
        }

        if (curr_num < target) {
            addNum(curr_num * 3, curr_cnt + 1);
            addNum(curr_num * 2, curr_cnt + 1);
            addNum(curr_num + 1, curr_cnt + 1);
        }

        if (curr_num > 1)
            addNum(curr_num - 1, curr_cnt + 1);
    }

    return min_cnt;
}

int main() {
    int N;

    cin >> N;

    cout << findMinCalcCnt(N);

    return 0;
}