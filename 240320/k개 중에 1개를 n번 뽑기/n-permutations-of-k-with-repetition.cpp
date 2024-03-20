#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector <int> nums;

void print() {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

void chooseNumber(int curr_num) {
    if (curr_num == N + 1) {
        print();
        return;
    }

    for (int i = 1; i <= K; i++) {
        nums.push_back(i);
        chooseNumber(curr_num + 1);
        nums.pop_back();
    }
    
}

int main() {
    cin >> K >> N;

    chooseNumber(1);

    return 0;
}