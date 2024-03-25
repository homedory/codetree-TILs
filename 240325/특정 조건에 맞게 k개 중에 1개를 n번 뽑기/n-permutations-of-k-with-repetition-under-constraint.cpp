#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> answer;

void print() {
    for (auto num : answer) {
        cout << num << " ";
    }
    cout << "\n";
}

bool isPossible(int curr_idx, int curr_num) {
    if (answer[curr_idx - 2] == answer[curr_idx - 1] && answer[curr_idx - 1] == curr_num)
        return false;
    
    return true;
}

void chooseNum(int curr_idx) {
    if (curr_idx == N) {
        print();
        return;
    }

    for (int i = 1; i <= K; i++) {
        if (curr_idx >= 2 && !isPossible(curr_idx, i))
            continue;
        
        answer.push_back(i);
        chooseNum(curr_idx + 1);
        answer.pop_back();
    }
}

int main() {
    cin >> K >> N;

    chooseNum(0);
    
    return 0;
}