#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int arr[51][51];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<M; j++) arr[i][j] = s[j]-'0';
    }
    int res = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            for(int k=j+1; k<M; k++) {
                if(arr[i][j] != arr[i][k]) continue;
                int diff = k-j, n = arr[i][j];
                if(diff+i < N && arr[i+diff][j] == n && arr[i+diff][k] == n)
                    res = max(res, (diff+1)*(diff+1));
            }
        }
    }
    cout << res;

    return 0;
}