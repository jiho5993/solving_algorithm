#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[1001];
bool visit[1001];

void foo(int st) {
    visit[st] = true;
    int cur = arr[st];
    while(!visit[cur]) {
        visit[cur] = true;
        cur = arr[cur];
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int N, res=0; cin >> N;
        for(int i=1; i<=N; i++) cin >> arr[i];
        memset(visit, 0, sizeof(visit));
        for(int i=1; i<=N; i++) {
            if(visit[i]) continue;
            foo(i);
            res++;
        }
        cout << res << '\n';
    }

    return 0;
}