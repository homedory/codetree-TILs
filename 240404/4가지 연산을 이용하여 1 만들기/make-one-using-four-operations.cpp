#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<int> nums;
queue<pair<int,int>> num_q;

bool isDuplicated(int num) {
    return nums.find(num) != nums.end();
}

void addNum(int num, int cnt) {    
    num_q.push(make_pair(num, cnt));
    nums.insert(num);
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

        if (curr_num > 1 && !isDuplicated(curr_num - 1)) {
            addNum(curr_num - 1, curr_cnt + 1);   
        }

        if (curr_num > target)
            continue;
        
        if (!isDuplicated(curr_num + 1))
            addNum(curr_num + 1, curr_cnt + 1);    
        
        if (!isDuplicated(curr_num * 2))
            addNum(curr_num * 2, curr_cnt + 1);
        
        if (!isDuplicated(curr_num * 3))
            addNum(curr_num * 3, curr_cnt + 1);
        
    }

    return min_cnt;
}

int main() {
    int N;

    cin >> N;

    cout << findMinCalcCnt(N);

    return 0;
}