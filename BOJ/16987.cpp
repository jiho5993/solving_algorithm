#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N, ans=0;
int s[10], w[10];

void foo(int idx) {
    if(idx >= N) {
        int cnt = 0;
        for(int i=0; i<N; i++) {
            if(s[i] <= 0)
                cnt++;
        }
        ans = max(cnt, ans);
        return;
    }
    
    if(s[idx] <= 0) foo(idx+1);
    else {
        bool flag = false;
        for(int i=0; i<N; i++) {
            if(i == idx || s[i] <= 0) continue;
            s[idx] -= w[i];
            s[i] -= w[idx];
            flag = true;
            foo(idx + 1);
            s[i] += w[idx];
            s[idx] += w[i];
        }
        if(!flag) foo(N);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> s[i] >> w[i];
    foo(0);
    cout << ans;

    return 0;
}