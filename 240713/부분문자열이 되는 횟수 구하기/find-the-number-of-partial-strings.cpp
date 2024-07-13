#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int A_length;
vector<int> erase_order;
string A, B;

bool isPartialString(int erase_num) {
    unordered_set <int> erased;
    for (int i = 0; i < erase_num; i++) {
        erased.insert(erase_order[i]);
    }

    int index = 0;
    for (int i = 0; i < A_length; i++) {
        if (erased.find(i+1) != erased.end())
            continue;
        
        if (A[i] == B[index])
            index++;
        
        if (index == B.length()) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> A;
    cin >> B;
    A_length = A.length();

    for (int i = 0; i < A_length; i++) {
        int num;
        cin >> num;
        erase_order.push_back(num);
    }


    int left = 0;
    int right = A_length;
    int ans = -1;
    
    while(left <= right) {
        int mid = (left + right) / 2;

        if (isPartialString(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }

    ans++;

    cout << ans;

    return 0;
}