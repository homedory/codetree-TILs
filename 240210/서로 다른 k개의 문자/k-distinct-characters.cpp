#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int k;
    string str;
    unordered_set <char> s;

    cin >> str >> k;

    int ans = 0;
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        while (j + 1 < str.length() && (s.size() < k || s.find(str[j + 1]) != s.end())) {
            j++;
            s.insert(str[j + 1]);
        }

        ans = max(ans, j - i + 1);
    }

    cout << ans;

    
    return 0;
}