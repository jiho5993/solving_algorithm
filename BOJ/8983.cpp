#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int M, N, L, res=0;
int a[100001];
pair<int, int> b[100001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> M >> N >> L;
    for(int i=0; i<M; i++) cin >> a[i];
    for(int i=0; i<N; i++) {
        int x, y; cin >> x >> y;
        b[i] = make_pair(x, y);
    }
    sort(a, a+M);
    sort(b, b+N);
    int j=0;
    for(int i=0; i<M; i++) {
        for(; j<N; j++) {
            int x = b[j].first;
            int y = b[j].second;
            if(abs(a[i]-x) > abs(a[i+1]-x) && i < M-1) break;
            if(abs(a[i]-x)+y <= L) res++;
        }
    }
    cout << res;

    return 0;
}