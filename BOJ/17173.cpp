#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, M; cin >> N >> M;
    int arr[1001], res=0;
    map<int, bool> chk;
    for(int i=0; i<M; i++) cin >> arr[i];
    for(int i=0; i<M; i++) {
        for(int j=1; j<=N; j++) {
            if(chk[j]) continue;
            if(j%arr[i] == 0) {
                res += j;
                chk[j] = true;
            }
        }
    }
    cout << res;

    return 0;
}