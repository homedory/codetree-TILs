#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> numbers;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (numbers.size() == 0 || numbers[numbers.size()-1] < num) {
            numbers.push_back(num);
        }
        else {
            int index = lower_bound(numbers.begin(), numbers.end(), num) - numbers.begin();
            numbers[index] = num;
        }
    } 

    cout << numbers.size();
    
    return 0;
}