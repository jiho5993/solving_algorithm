#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int res=0;
pair<int, int> arr[10001];
bool visit[10001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+N, [&](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });
    for(int i=0; i<N; i++) {
        for(int j=arr[i].second; j>0; j--) {
            if(!visit[j]) {
                visit[j] = true;
                res += arr[i].first;
                break;
            }
        }
    }
    cout << res;

    return 0;
}