#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int k;
    string str;
    unordered_map <char, int> cnt;

    cin >> str >> k;

    int ans = 0;
    int j = -1;
    for (int i = 0; i < str.length(); i++) {
        while (j + 1 < str.length() && (cnt.size() < k || cnt.find(str[j + 1]) != cnt.end())) {
            j++;
            cnt[str[j + 1]] += 1;
        }

        ans = max(ans, j - i + 1);
        cnt[str[i]] -= 1;

        if (cnt[str[i]] == 0) {
            cnt.erase(str[i]);
        }
    }

    cout << ans;


    return 0;
}