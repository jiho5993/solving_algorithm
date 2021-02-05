#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, idx=0;
int arr[101], res[101];
bool visit[101];

void foo(int tmp, int st) {
    if(visit[tmp]) {
        if(tmp == st)
            res[idx++] = tmp;
    } else {
        visit[tmp] = 1;
        foo(arr[tmp], st);
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=1; i<=N; i++) {
        memset(visit, 0, sizeof(visit));
        foo(i, i);
    }
    cout << idx << '\n';
    for(int i=0; i<idx; i++) cout << res[i] << '\n';

    return 0;
}