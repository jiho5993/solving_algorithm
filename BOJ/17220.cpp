#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N, M, K;
vi arr[27];
int deg[27];
bool detected[27];

int dfs(int x) {
    detected[x] = true;
    int ret=1;
    for(int i:arr[x]) {
        if(detected[i]) continue;
        ret += dfs(i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        char a, b; cin >> a >> b;
        deg[b-'A']++;
        arr[a-'A'].pb(b-'A');
    }
    cin >> K;
    for(int i=0; i<K; i++) {
        char a; cin >> a;
        detected[a-'A'] = true;
    }
    int res=0;
    for(int i=0; i<N; i++) {
        if(deg[i] == 0 && !detected[i])
            res += dfs(i)-1;
    }
    cout << res;

    return 0;
}