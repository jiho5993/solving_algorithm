#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ll long long
#define V(T) vector<T>
#define VP(T) vector<pair<T, T> >
#define P(T) pair<T, T>
#define PQ(T) priority_queue<T>

int N, M, res=0;
int arr[11][100001];
int dp[11][100001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++)
            cin >> arr[i][j];
    }
    for(int i=1; i<=M; i++) dp[i][1] = arr[i][1];
    for(int j=2; j<=N; j++) {
        for(int i=1; i<=M; i++) {
            for(int k=1; k<=M; k++) {
                if(i == k) dp[i][j] = max(dp[i][j], dp[k][j-1] + arr[i][j]/2);
                else dp[i][j] = max(dp[i][j], dp[k][j-1] + arr[i][j]);
            }
        }
    }
    for(int i=1; i<=M; i++) res = max(res, dp[i][N]);
    cout << res;

    return 0;
}