#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, d, w;
int done[1001];
pair<int, int> arr[1001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> d >> w;
        arr[i] = {w, d};
    }
    sort(arr, arr+N);

    for(int i=N-1; i>=0; i--) {
        w = arr[i].first;
        d = arr[i].second;
        if(done[d] == 0) done[d] = w;
        else {
            for(int j=d-1; j>0; j--) {
                if(done[j] == 0) {
                    done[j] = w;
                    break;
                }
            }
        }
    }

    int res=0;
    for(int i=1; i<=1000; i++) res += done[i];
    cout << res;

    return 0;
}