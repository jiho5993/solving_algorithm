#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, M;
bool visit[2001], flag;
vector<int> arr[2001];

void foo(int i, int cnt) {
    if(flag) return;
    if(cnt == 4) {
        flag = true;
        return;
    }
    visit[i] = true;
    for(auto tmp:arr[i])
        if(!visit[tmp])
            foo(tmp, cnt+1);
    visit[i] = false;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    for(int i=0; i<N; i++) foo(i, 0);
    flag ? cout << 1 : cout << 0;

    return 0;
}