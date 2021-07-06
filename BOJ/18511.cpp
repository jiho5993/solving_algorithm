#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, K, res=-1;
string a;
int arr[4];

void foo(string cur) {
    if(cur.size() > 0) {
        if(cur.size() > a.size()) return;
        if(stoi(cur) > N) return;
        res = max(res, stoi(cur));
    }

    for(int i=0; i<K; i++) {
        string tmp = cur;
        tmp += to_string(arr[i]);
        foo(tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N >> K;
    a = to_string(N);
    for(int i=0; i<K; i++) cin >> arr[i];
    foo("");
    cout << res;

    return 0;
}