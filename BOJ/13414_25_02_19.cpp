#include <bits/stdc++.h>
using namespace std;

string arr[500001];
unordered_map<string, int> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int K, L; cin >> K >> L;
    for (int i=0; i<L; i++) {
        cin >> arr[i];
        m[arr[i]] = i;
    }

    for (int i=0, cnt=0; i<L && cnt<K; i++) {
        if (m[arr[i]] == i) {
            cnt++;
            cout << arr[i] << '\n';
        }
    }
    
    return 0;
}
